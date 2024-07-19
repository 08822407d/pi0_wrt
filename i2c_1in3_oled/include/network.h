#ifndef _WRT_UTILS_H_
#define _WRT_UTILS_H_

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <limits.h>
#include <stdbool.h>


	typedef struct network_status {
		pthread_mutex_t netstate_lock;

		bool EthWorking;
		bool WlanWorking;
		bool ProxyWorking;
		char *IpAddr;
	} netstate_s;

	extern netstate_s NetWork_Status;
	extern pthread_t network_thread;
	extern void* network_monitor(void* arg);

	extern bool getNewIpAddr(char *IPMsg_bufp);
	extern bool getNewEthState(char *EthStateMsg_bufp);
	extern bool getNewWlanState(char *WlanStateMsg_bufp);

	extern char *getIpAddr(void);
	extern bool IsEthConnected(void);
	extern bool IsWlanConnected(void);
	extern bool IsProxyConnected(void);

#endif /* _WRT_UTILS_H_ */