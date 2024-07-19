#ifndef _SCREEN_DISPLAY_H_
#define _SCREEN_DISPLAY_H_

#include "types.h"


    extern int eth_x;
    extern int eth_y;
    extern int wlan_x;
    extern int wlan_y;
    extern int proxy_x;
    extern int proxy_y;

	extern pthread_t display_thread;
    extern void *display_status(void* arg);

#endif /* _SCREEN_DISPLAY_H_ */