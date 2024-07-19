#include <stdio.h>		//printf()
#include <stdlib.h>		//exit()
#include <time.h>
#include <signal.h>     //signal()

#include "OLED_Driver.h"
#include "OLED_GUI.h"
#include "DEV_Config.h"
#include "KEY_APP.h"

#include "network.h"

pthread_cond_t cond;
volatile sig_atomic_t stop = 0;
netstate_s NetWork_Status;

int eth_x = 8;
int eth_y = 24;
int wlan_x = 48;
int wlan_y = 24;
int proxy_x = 88;
int proxy_y = 24;


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
	// 初始化互斥锁和条件变量
	if (pthread_mutex_init(&NetWork_Status.netstate_lock, NULL) != 0 ||
		pthread_cond_init(&cond, NULL) != 0) {
		fprintf(stderr, "Mutex or Cond init failed\n");
		return 1;
	}
	// 创建线程
	// if (pthread_create(&network_thread, NULL, network_monitor, NULL) != 0 ||
	// 	pthread_create(&gpio_thread, NULL, gpio_listener, NULL) != 0 ||
	// 	pthread_create(&display_thread, NULL, display_status, NULL) != 0) {
	if (pthread_create(&network_thread, NULL, network_monitor, &NetWork_Status) != 0) {
		fprintf(stderr, "Error creating thread\n");
		return 1;
	}
	// Exception handling:ctrl + c
	signal(SIGINT, terminateHandler);
	// System shutdown handling
	signal(SIGTERM, terminateHandler);


	//1.System Initialization
	if(DEV_ModuleInit())
		exit(0);
	
	//2.show
	printf("**********Init OLED**********\r\n");
	OLED_SCAN_DIR OLED_ScanDir = SCAN_DIR_DFT;//SCAN_DIR_DFT = D2U_L2R
	OLED_Init(OLED_ScanDir);	
	
	printf("OLED Show \r\n");
	GUI_Show();

	OLED_Clear(OLED_BACKGROUND);
	GUI_Disbitmap(eth_x, eth_y, Eth_UnAvailable, 32, 32);
	GUI_Disbitmap(wlan_x, wlan_y, AP_UnAvailable, 32, 32);
	GUI_Disbitmap(proxy_x, proxy_y, Proxy_UnAvailable, 32, 32);
	OLED_Display();		
	DEV_Delay_ms(500);
	OLED_Clear(OLED_BACKGROUND);


	printf("Start\n");
	while (1) {
		// printf("Getting states...\t");
		// char *EthState = "DisConnected";
		// char *WlanState = "DisConnected";
		// char *ProxyState = "DisConnected";

		pthread_mutex_lock(&NetWork_Status.netstate_lock);

		bool eth_state = NetWork_Status.EthWorking;
		bool wlan_state = NetWork_Status.WlanWorking;
		bool proxy_state = NetWork_Status.ProxyWorking;
		char *IpAddr = NetWork_Status.IpAddr;

        pthread_mutex_unlock(&NetWork_Status.netstate_lock);
		
		// if (eth_state)
		// 	EthState = "Connected";
		// if (wlan_state)
		// 	WlanState = "Connected";
		// if (proxy_state)
		// 	ProxyState = "Connected";

		GUI_DisString_EN(10, 4, IpAddr, &Font12, FONT_BACKGROUND, WHITE);

		if (eth_state)
			GUI_Disbitmap(eth_x, eth_y, Eth_Available, 32, 32);
		else
			GUI_Disbitmap(eth_x, eth_y, Eth_UnAvailable, 32, 32);

		if (wlan_state)
			GUI_Disbitmap(wlan_x, wlan_y, AP_Available, 32, 32);
		else
			GUI_Disbitmap(wlan_x, wlan_y, AP_UnAvailable, 32, 32);
		
		if (proxy_state)
			GUI_Disbitmap(proxy_x, proxy_y, Proxy_Available, 32, 32);
		else
			GUI_Disbitmap(proxy_x, proxy_y, Proxy_UnAvailable, 32, 32);


		// printf("IP: %s; ", IpAddr);
		// printf("Eth: %s; ", EthState);
		// printf("Wlan: %s; ", WlanState);
		// printf("Proxy: %s\n", ProxyState);

		OLED_Display();		
		OLED_Clear(OLED_BACKGROUND);
		DEV_Delay_ms(500);
	}
	
	//3.System Exit
	// OLED_Clear(OLED_BACKGROUND);
	// OLED_Display();
	// DEV_ModuleExit();
	systemExit();
	return 0;
}

