#include <stdio.h>		//printf()
#include <stdlib.h>		//exit()
#include <time.h>
#include <signal.h>     //signal()

#include "OLED_Driver.h"
#include "OLED_GUI.h"
#include "DEV_Config.h"
#include "KEY_APP.h"

#include "glob.h"
#include "network.h"
#include "screen_disp.h"
#include "gpio_listener.h"


pthread_cond_t cond;
volatile sig_atomic_t stop = 0;
glob_s GlobData;


void systemExit()
{
	netstate_s *NetStat = &GlobData.NetWork_Status;
	dispstate_s *DispStat = &GlobData.Display_Status;

	stop = 1;
	pthread_cond_broadcast(&cond);	// 确保所有线程能够退出

    // 等待线程结束
    pthread_join(network_thread, NULL);
    pthread_join(display_thread, NULL);
    pthread_join(gpio_thread, NULL);

    // 销毁互斥锁和条件变量
    pthread_mutex_destroy(&NetStat->lock);
    pthread_mutex_destroy(&DispStat->lock);
    pthread_cond_destroy(&cond);

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

void screen_init()
{
	//1.System Initialization
	if(DEV_ModuleInit())
		exit(1);
	
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
}

char value[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int main(void)
{
	screen_init();

	netstate_s *NetStat = &GlobData.NetWork_Status;
	dispstate_s *DispStat = &GlobData.Display_Status;
	keysstate_s *KeysStat = &GlobData.Keys_Status;
	NetStat->IpAddr = "!!! 0.0.0.0 !!!";
	DispStat->Active = true;
	DispStat->ActiveTime = 0;

	// 初始化互斥锁和条件变量
	if (pthread_mutex_init(&NetStat->lock, NULL) != 0 ||
		pthread_mutex_init(&DispStat->lock, NULL) != 0 ||
		pthread_mutex_init(&KeysStat->lock, NULL) != 0 ||
		pthread_cond_init(&cond, NULL) != 0) {
		fprintf(stderr, "Mutex or Cond init failed\n");
		return 1;
	}
	keys_reset(KeysStat);
	// 创建线程
	if (pthread_create(&network_thread, NULL, network_monitor, NetStat) != 0 ||
		pthread_create(&display_thread, NULL, display_sysstatus, &GlobData) != 0 ||
		pthread_create(&gpio_thread, NULL, gpio_listener, &GlobData) != 0) {
		fprintf(stderr, "Error creating thread\n");
		return 1;
	}
	// Exception handling:ctrl + c
	signal(SIGINT, terminateHandler);
	// System shutdown handling
	signal(SIGTERM, terminateHandler);

	activeScreen(DispStat);

	while (1) {
		sleep(1);
	}
	
	//3.System Exit
	systemExit();
	return 0;
}

