#include <stdio.h>		//printf()
#include <stdlib.h>		//exit()
#include <time.h>
#include <signal.h>     //signal()

#include "OLED_Driver.h"
#include "OLED_GUI.h"
#include "DEV_Config.h"
#include "KEY_APP.h"

#include "network.h"
// #include "../sysinfo/network.h"

void systemExit()
{
	//System Exit
	OLED_Clear(OLED_BACKGROUND);
	OLED_Display();

	printf("Goto Sleep...\r\n");
	DEV_ModuleExit();
}

void terminateHandler(int signo)
{
	printf("\r\nHandler:exit\r\n");
	DEV_ModuleInit();
	systemExit();

	exit(0);
}


char value[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int main(void)
{
	// Exception handling:ctrl + c
	signal(SIGINT, terminateHandler);
	// System shutdown handling
	signal(SIGTERM, terminateHandler);


	time_t now;
	struct tm *timenow;
	int i;
	//1.System Initialization
	if(DEV_ModuleInit())
		exit(0);
	
	//2.show
	printf("**********Init OLED**********\r\n");
	OLED_SCAN_DIR OLED_ScanDir = SCAN_DIR_DFT;//SCAN_DIR_DFT = D2U_L2R
	OLED_Init(OLED_ScanDir);	
	
	printf("OLED Show \r\n");
	GUI_Show();
	
	while(1){
		i++;
		time(&now);
		timenow = localtime(&now);
	
		if (IsEthConnected())
			GUI_Disbitmap(0, 0, Eth_Available, 32, 32);
		else
			GUI_Disbitmap(0, 0, Eth_UnAvailable, 32, 32);

		if (IsWlanConnected())
			GUI_Disbitmap(0, 32, AP_Available, 32, 32);
		else
			GUI_Disbitmap(0, 32, AP_UnAvailable, 32, 32);
		
		OLED_Display();		
		OLED_Clear(OLED_BACKGROUND);
		usleep(500 * 1000);
	}
	
	//3.System Exit
	// OLED_Clear(OLED_BACKGROUND);
	// OLED_Display();
	// DEV_ModuleExit();
	systemExit();
	return 0;
}

