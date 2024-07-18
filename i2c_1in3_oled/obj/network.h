#ifndef _WRT_UTILS_H_
#define _WRT_UTILS_H_

#include <stdbool.h>

    extern bool getNewIpAddr(char *IPMsg_bufp);
    extern bool getNewEthState(char *EthStateMsg_bufp);
    extern bool getNewWlanState(char *WlanStateMsg_bufp);

    extern char *getIpAddr(void);
    extern bool IsEthConnected(void);
    extern bool IsWlanConnected(void);
    extern bool IsProxyConnected(void);

#endif /* _WRT_UTILS_H_ */