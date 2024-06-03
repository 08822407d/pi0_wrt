#include <stdio.h>
#include <string.h>
#include <time.h> 
#include <unistd.h>
#include <signal.h>
#include <errno.h>

#include "EPD.h"
#include "EPD_Test.h"
#include "utils.h"


#define SEC_PER_MIN			60
#define MIN_PER_HOUR		60
#define REFRESH_INTERVAL	(2 * SEC_PER_MIN * MIN_PER_HOUR)
// #define REFRESH_INTERVAL	60


#define IP_MSG_BUFLEN		32
#define IP_BUFLEN			16


char *new_ip = NULL;
char *new_eth_state = NULL;
char *new_wlan_state = NULL;

void refresh_EPaper_handler(int param) {
	EPD_2in13_V4_Clear();
	EPD_2in13_V4_Init();
	new_ip = getNewIpAddr();
	alarm(REFRESH_INTERVAL);
}

int showip(void)
{
	if(DEV_Module_Init()!=0)
		return -1;

	EPD_2in13_V4_Init();
	EPD_2in13_V4_Clear();

	//Create a new image cache
	UBYTE *BlackImage;
	UWORD Imagesize = ((EPD_2in13_V4_WIDTH % 8 == 0)?
						(EPD_2in13_V4_WIDTH / 8 ):
						(EPD_2in13_V4_WIDTH / 8 + 1)) * EPD_2in13_V4_HEIGHT;
	if((BlackImage = (UBYTE *)malloc(Imagesize)) == NULL) {
		Debug("Failed to apply for black memory...\r\n");
		return -1;
	}
	Debug("Paint_NewImage\r\n");
	Paint_NewImage(BlackImage, EPD_2in13_V4_WIDTH, EPD_2in13_V4_HEIGHT, 270, WHITE);
	Paint_SelectImage(BlackImage);
	Paint_Clear(WHITE);

	signal(SIGALRM, refresh_EPaper_handler);
	alarm(REFRESH_INTERVAL);


	while (1) {
		new_ip = getNewIpAddr();
		new_eth_state = getNewEthState();
		new_wlan_state = getNewWlanState();
		if (new_ip != NULL) {
			Paint_Clear(WHITE);
			Paint_DrawString_EN(0, 0, new_ip, &Font16, WHITE, BLACK);
			EPD_2in13_V4_Display_Fast(BlackImage);
			new_ip = NULL;
		}

		usleep(500 * 1000);
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
