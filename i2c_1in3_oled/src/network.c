#include "network.h"


extern sig_atomic_t stop;

pthread_t network_thread;

void* network_monitor(void* arg) {
	netstate_s *Status = (netstate_s *)arg;
    while (!stop) {
		bool eth_state = IsEthConnected();
		bool wlan_state = IsWlanConnected();
		bool proxy_state = IsProxyConnected();
		char *ip = getIpAddr();


        pthread_mutex_lock(&Status->netstate_lock);

		Status->EthWorking = eth_state;
		Status->WlanWorking = wlan_state;
		Status->ProxyWorking = proxy_state;
		Status->IpAddr = ip;

        pthread_mutex_unlock(&Status->netstate_lock);

		usleep(200 * 1000);
    }
    return NULL;
}



#define IP_MSG_BUFLEN		32
#define IP_BUFLEN			16

static char last_IP[IP_BUFLEN] = "";
static char tmp_ip_buf[IP_BUFLEN] = "";

bool getNewIpAddr(char *IPMsg_bufp) {
	bool retval = false;
	while (1) {
		FILE *cmd_fp = popen("hostname -I", "r");
		if (cmd_fp == NULL)
			goto retry;
		
		char *fgets_ret = fgets(tmp_ip_buf, IP_BUFLEN - 1, cmd_fp);
		pclose(cmd_fp);
		if (fgets_ret == NULL)
			goto retry;

		char *end_idx = strchr(tmp_ip_buf, ' ');
		if (end_idx != NULL)
			memset(end_idx, 0, IP_BUFLEN - (end_idx - tmp_ip_buf));
		else {
			if (tmp_ip_buf[0] == '\n')
				strncpy(tmp_ip_buf, "!!! 0.0.0.0 !!!", IP_BUFLEN);
			tmp_ip_buf[IP_BUFLEN - 1] = 0;
		}
		if (strcmp(tmp_ip_buf, last_IP) != 0) {
			sprintf(IPMsg_bufp, "IP: %s", tmp_ip_buf);
			strncpy(last_IP, tmp_ip_buf, IP_BUFLEN);
			retval = true;
		}
		break;

retry:
		usleep(100 * 1000);
		continue;
	}
	return retval;
}




#define STATE_MSG_BUFLEN	32

static char last_eth_state[STATE_MSG_BUFLEN] = "";

bool getNewEthState(char *EthStateMsg_bufp) {
	bool retval = false;
	while (1) {
		FILE *cmd_fp = popen("nmcli -t -f DEVICE,STATE d | grep eth0", "r");
		if (cmd_fp == NULL)
			goto retry;
		
		char *fgets_ret = fgets(EthStateMsg_bufp, STATE_MSG_BUFLEN - 1, cmd_fp);
		pclose(cmd_fp);
		if (fgets_ret == NULL)
			goto retry;

		char *newline_ptr = strchr(EthStateMsg_bufp, '\n');
		if (newline_ptr != NULL)
			*newline_ptr = 0;
		char *bracket_ptr = strchr(EthStateMsg_bufp, '(');
		if (bracket_ptr != NULL)
			*bracket_ptr = 0;
		if (strcmp(EthStateMsg_bufp, last_eth_state) != 0) {
			strcpy(last_eth_state, EthStateMsg_bufp);
			retval = true;
		}
		break;

retry:
		usleep(100 * 1000);
		continue;
	}
	return retval;
}

static char last_wlan_state[STATE_MSG_BUFLEN] = "";

bool getNewWlanState(char *WlanStateMsg_bufp) {
	bool retval = false;
	while (1) {
		FILE *cmd_fp = popen("nmcli -t -f DEVICE,STATE d | grep wlan0", "r");
		if (cmd_fp == NULL)
			goto retry;
		
		char *fgets_ret = fgets(WlanStateMsg_bufp, STATE_MSG_BUFLEN - 1, cmd_fp);
		pclose(cmd_fp);
		if (fgets_ret == NULL)
			goto retry;

		char *newline_ptr = strchr(WlanStateMsg_bufp, '\n');
		if (newline_ptr != NULL)
			*newline_ptr = 0;
		char *bracket_ptr = strchr(WlanStateMsg_bufp, '(');
		if (bracket_ptr != NULL)
			*bracket_ptr = 0;
		if (strcmp(WlanStateMsg_bufp, last_wlan_state) != 0) {
			strcpy(last_wlan_state, WlanStateMsg_bufp);
			retval = true;
		}
		break;

retry:
		usleep(100 * 1000);
		continue;
	}
	return retval;
}


char *getIpAddr() {
	while (1) {
		FILE *cmd_fp = popen("hostname -I", "r");
		if (cmd_fp == NULL)
			goto retry;
		
		char *fgets_ret = fgets(tmp_ip_buf, IP_BUFLEN, cmd_fp);
		pclose(cmd_fp);
		if (fgets_ret == NULL)
			goto retry;

		char *end_idx = strchr(tmp_ip_buf, ' ');
		if (end_idx != NULL)
			memset(end_idx, 0, IP_BUFLEN - (end_idx - tmp_ip_buf));
		else {
			if (tmp_ip_buf[0] == '\n')
				strncpy(tmp_ip_buf, "!!! 0.0.0.0 !!!", IP_BUFLEN);
			tmp_ip_buf[IP_BUFLEN - 1] = 0;
		}
		return tmp_ip_buf;

retry:
		usleep(100 * 1000);
		continue;
	}
}

#define CMD_OUTBUF_LEN	4096
static char cmd_output_buf[CMD_OUTBUF_LEN];

bool IsEthConnected() {
	while (1) {
		FILE *cmd_fp = popen("ip link show eth0 | grep \"state UP\"", "r");
		if (cmd_fp == NULL) {
			printf("Get Eth State Failed.\t");
			goto retry;
		}
		
		memset(cmd_output_buf, 0, CMD_OUTBUF_LEN);
		char *fgets_ret = fgets(cmd_output_buf, CMD_OUTBUF_LEN - 1, cmd_fp);
		pclose(cmd_fp);

		return !(fgets_ret == NULL);

retry:
		usleep(100 * 1000);
	}
}

bool IsWlanConnected() {
	while (1) {
		FILE *cmd_fp = popen("ip link show wlan0 | grep \"state UP\"", "r");
		if (cmd_fp == NULL) {
			printf("Get Wlan State Failed.\t");
			goto retry;
		}
		
		memset(cmd_output_buf, 0, CMD_OUTBUF_LEN);
		char *fgets_ret = fgets(cmd_output_buf, CMD_OUTBUF_LEN - 1, cmd_fp);
		pclose(cmd_fp);

		return !(fgets_ret == NULL);

retry:
		usleep(100 * 1000);
	}
}

bool IsProxyConnected() {
	while (1) {
		FILE *cmd_fp = popen("wget --tries=1 --timeout=1 -O /dev/null \'google.com\' 2>&1 | grep \"saved\"", "r");
		if (cmd_fp == NULL) {
			printf("Get Proxy State Failed.\t");
			goto retry;
		}
		
		memset(cmd_output_buf, 0, CMD_OUTBUF_LEN);
		char *fgets_ret = fgets(cmd_output_buf, CMD_OUTBUF_LEN - 1, cmd_fp);
		pclose(cmd_fp);

		return !(fgets_ret == NULL);

retry:
		usleep(100 * 1000);
	}
}