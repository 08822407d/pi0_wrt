#ifndef _WRT_TYPES_H_
#define _WRT_TYPES_H_

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <limits.h>
#include <stdbool.h>


	typedef struct network_status {
		pthread_mutex_t lock;

		bool EthWorking;
		bool WlanWorking;
		bool ProxyWorking;
		char *IpAddr;
	} netstate_s;

	typedef struct display_status {
		pthread_mutex_t lock;

		bool	Active;
		int		ActiveTime;
	} dispstate_s;

	typedef struct keys_status {
		pthread_mutex_t lock;

		bool Up;
		bool Down;
		bool Left;
		bool Right;
		bool Center;

		bool Key1;
		bool Key2;
		bool Key3;
	} keysstate_s;

	typedef struct global_data {
		netstate_s	NetWork_Status;
		dispstate_s	Display_Status;
		keysstate_s	Keys_Status;
	} glob_s;

#endif /* _WRT_TYPES_H_ */
