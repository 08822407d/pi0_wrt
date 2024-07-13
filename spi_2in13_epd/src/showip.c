#include <stdio.h>
#include <string.h>
#include <time.h> 
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <stdbool.h>

#include "EPD.h"
#include "EPD_Test.h"
#include "utils.h"

#define WIDTH				250
#define HEIGHT				122

#define SEC_PER_MIN			60
#define MIN_PER_HOUR		60
#define REFRESH_INTERVAL	(2 * SEC_PER_MIN * MIN_PER_HOUR)
// #define REFRESH_INTERVAL	10


#define IP_MSG_BUFLEN		32
#define IP_BUFLEN			16


UBYTE *BlackImage = NULL;
char ip_buf[IP_MSG_BUFLEN];
char eth_state_buf[IP_MSG_BUFLEN];
char wlan_state_buf[IP_MSG_BUFLEN];
bool need_refresh = false;
bool inRefreshing = false;

void refresh_EPaper_handler(int param) {
	// if (BlackImage != NULL)
	// {
	// 	Paint_Clear(WHITE);
	// 	EPD_2in13_V4_Display(BlackImage);
	// }
	// // EPD_2in13_V4_Init();
	// // EPD_2in13_V4_Clear();
	need_refresh = true;
	if (inRefreshing)
		alarm(1);
	else
		alarm(REFRESH_INTERVAL);
}

int showip(void)
{
	if(DEV_Module_Init()!=0)
		return -1;

	EPD_2in13_V4_Init();
	EPD_2in13_V4_Clear();

	//Create a new image cache
	UWORD Imagesize = ((HEIGHT % 8 == 0) ? (HEIGHT / 8 ) : (HEIGHT / 8 + 1)) * WIDTH;
	if((BlackImage = (UBYTE *)malloc(Imagesize)) == NULL) {
		Debug("Failed to apply for black memory...\r\n");
		return -1;
	}
	Debug("Paint_NewImage\r\n");
	Paint_NewImage(BlackImage, HEIGHT, WIDTH, 90, WHITE);
	Paint_SelectImage(BlackImage);
	Paint_Clear(WHITE);

	signal(SIGALRM, refresh_EPaper_handler);
	alarm(REFRESH_INTERVAL);


	while (1) {
		printf("Cycle - %s | %s | %s\n", ip_buf, eth_state_buf, wlan_state_buf);

		inRefreshing = true;
		if (!need_refresh) {
			need_refresh = getNewIpAddr(ip_buf) |
							getNewEthState(eth_state_buf) |
							getNewWlanState(wlan_state_buf);
		} else {
			Paint_Clear(WHITE);
			Paint_DrawString_EN(5, 5, ip_buf, &Font16, WHITE, BLACK);
			Paint_DrawString_EN(5, 25, eth_state_buf, &Font16, WHITE, BLACK);
			Paint_DrawString_EN(5, 45, wlan_state_buf, &Font16, WHITE, BLACK);
			EPD_2in13_V4_Display(BlackImage);
			need_refresh = false;
		}
		inRefreshing = false;

		sleep(1);
	}

	alarm(0);

	Debug("Clear...\r\n");
	EPD_2in13_V4_Init();
	EPD_2in13_V4_Clear();
	
	Debug("Goto Sleep...\r\n");
	EPD_2in13_V4_Sleep();
	free(BlackImage);
	BlackImage = NULL;
	DEV_Delay_ms(2000);//important, at least 2s
	// close 5V
	Debug("close 5V, Module enters 0 power consumption ...\r\n");
	DEV_Module_Exit();
	return 0;
}
