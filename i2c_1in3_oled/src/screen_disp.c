#include "glob.h"
#include "screen_disp.h"

#include "OLED_Driver.h"
#include "OLED_GUI.h"
#include "DEV_Config.h"
#include "KEY_APP.h"


int eth_x = 8;
int eth_y = 24;
int wlan_x = 48;
int wlan_y = 24;
int proxy_x = 88;
int proxy_y = 24;

pthread_t display_thread;

void *display_status(void* arg) {

	glob_s *Glob = (glob_s *)arg;
	netstate_s *NetStat = &Glob->NetWork_Status;
	dispstate_s *DispStat = &Glob->Display_Status;

	while (!stop) {
		pthread_mutex_lock(&DispStat->lock);
		while (!DispStat->Active) {
			pthread_cond_wait(&cond, &DispStat->lock); // 等待唤醒信号
		}
		pthread_mutex_unlock(&DispStat->lock);

		for (int i = 0; i < 20 && !stop; ++i) {

			pthread_mutex_lock(&NetStat->lock);

			bool eth_state = NetStat->EthWorking;
			bool wlan_state = NetStat->WlanWorking;
			bool proxy_state = NetStat->ProxyWorking;
			char *IpAddr = NetStat->IpAddr;

			pthread_mutex_unlock(&NetStat->lock);


			// printf("Getting states...\t");
			// char *EthState = "DisConnected";
			// char *WlanState = "DisConnected";
			// char *ProxyState = "DisConnected";

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

		pthread_mutex_lock(&DispStat->lock);
		DispStat->Active = false; // 进入睡眠状态
		OLED_Clear(OLED_BACKGROUND);
		OLED_Display();
		pthread_mutex_unlock(&DispStat->lock);
	}
	return NULL;
}