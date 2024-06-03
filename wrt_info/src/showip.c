#include <stdio.h>
#include <string.h>
#include <time.h> 
#include <unistd.h>
#include <signal.h>
#include <errno.h>

#include "EPD.h"
#include "EPD_Test.h"


#define SEC_PER_MIN			60
#define MIN_PER_HOUR		60
#define REFRESH_INTERVAL	(2 * SEC_PER_MIN * MIN_PER_HOUR)
// #define REFRESH_INTERVAL	60


#define IP_MSG_BUFLEN		32
#define IP_BUFLEN			16


char last_IP[IP_BUFLEN];
char IP_msg[IP_MSG_BUFLEN];
char tmp_buf[IP_BUFLEN];


void refresh_EPaper_handler(int param) {
	EPD_2in13_V4_Clear();
	EPD_2in13_V4_Init();
	memset(last_IP, 0, IP_BUFLEN);
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
		usleep(500 * 1000);

		FILE *cmd_fp = popen("hostname -I", "r");
		if (cmd_fp == NULL)
			return -1;
		
		char *fgets_ret = fgets(tmp_buf, IP_BUFLEN - 1, cmd_fp);
		pclose(cmd_fp);

		if (fgets_ret == NULL)
			continue;

		char *end_idx = strchr(tmp_buf, ' ');
		if (end_idx != NULL)
			memset(end_idx, 0, IP_BUFLEN - (end_idx - tmp_buf));
		else
			tmp_buf[IP_BUFLEN - 1] = 0;
		if (tmp_buf[0] == '\n') {
			//printf("[ %d - %d] \n", (unsigned char)tmp_buf[0], (unsigned char)tmp_buf[0]);
			strncpy(tmp_buf, "!!! 0.0.0.0 !!!", IP_BUFLEN);
			tmp_buf[IP_BUFLEN - 1] = 0;
		}
		// printf("\033[;32;m %s / %s\033[0m \n", tmp_buf, last_IP);


		if (strcmp(tmp_buf, last_IP) != 0) {
			Paint_Clear(WHITE);
			sprintf(IP_msg, "IP: %s", tmp_buf);
			// printf("%s\n", IP_msg);
			Paint_DrawString_EN(0, 0, IP_msg, &Font16, WHITE, BLACK);
			EPD_2in13_V4_Display_Fast(BlackImage);

			strncpy(last_IP, tmp_buf, IP_BUFLEN);
			memset(tmp_buf, 0, IP_BUFLEN);
		}
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
