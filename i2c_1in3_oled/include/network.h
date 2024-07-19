#ifndef _NETWORK_STATUS_H_
#define _NETWORK_STATUS_H_

#include "types.h"


	extern netstate_s NetWork_Status;
	extern pthread_t network_thread;
	extern void *network_monitor(void* arg);

	extern bool getNewIpAddr(char *IPMsg_bufp);
	extern bool getNewEthState(char *EthStateMsg_bufp);
	extern bool getNewWlanState(char *WlanStateMsg_bufp);

	extern char *getIpAddr(void);
	extern bool IsEthConnected(void);
	extern bool IsWlanConnected(void);
	extern bool IsProxyConnected(void);

#endif /* _NETWORK_STATUS_H_ */