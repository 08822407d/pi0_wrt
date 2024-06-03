#include <stdio.h>
#include <string.h>
#include <time.h> 
#include <unistd.h>

#include "utils.h"



#define IP_MSG_BUFLEN		32
#define IP_BUFLEN			16

static char last_IP[IP_BUFLEN] = "";
static char tmp_ip_buf[IP_BUFLEN] = "";
static char IP_msg[IP_MSG_BUFLEN] = "";

char *getNewIpAddr() {
	char *retval = NULL;
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
			sprintf(IP_msg, "IP: %s", tmp_ip_buf);
			retval = IP_msg;
			strncpy(last_IP, tmp_ip_buf, IP_BUFLEN);
			memset(tmp_ip_buf, 0, IP_BUFLEN);
		}
		break;

retry:
		usleep(100 * 1000);
		continue;
	}
	return retval;
}




#define STATE_MSG_BUFLEN	32
#define STAT_BUFLEN			128

static char last_eth_state[STATE_MSG_BUFLEN] = "";
static char tmp_eth_buf[STAT_BUFLEN] = "";
static char EthState_msg[STATE_MSG_BUFLEN] = "";

char *getNewEthState() {
	char *retval = NULL;
	char *curr_state = NULL;

	while (1) {
		FILE *cmd_fp = popen("nmcli dev show eth0 | grep STATE", "r");
		if (cmd_fp == NULL)
			goto retry;
		
		char *fgets_ret = fgets(tmp_eth_buf, STAT_BUFLEN - 1, cmd_fp);
		pclose(cmd_fp);
		if (fgets_ret == NULL)
			goto retry;

		if (strstr(tmp_eth_buf, "connected") != NULL)
			curr_state = "connected";
		else if (strstr(tmp_eth_buf, "disabled") != NULL)
			curr_state = "disabled";
		else
			curr_state = "no device";

		if (strcmp(curr_state, last_eth_state) != 0) {
			sprintf(EthState_msg, "eth0 : %s", curr_state);
			strcpy(last_eth_state, curr_state);
			retval = EthState_msg;
		}
		break;

retry:
		usleep(100 * 1000);
		continue;
	}
	return retval;
}

static char last_wlan_state[STATE_MSG_BUFLEN] = "";
static char tmp_wlan_buf[STAT_BUFLEN] = "";
static char WlanState_msg[STATE_MSG_BUFLEN] = "";

char *getNewWlanState() {
	char *retval = NULL;
	char *curr_state = NULL;

	while (1) {
		FILE *cmd_fp = popen("nmcli dev show wlan0 | grep STATE", "r");
		if (cmd_fp == NULL)
			goto retry;
		
		char *fgets_ret = fgets(tmp_wlan_buf, STAT_BUFLEN - 1, cmd_fp);
		pclose(cmd_fp);
		if (fgets_ret == NULL)
			goto retry;

		if (strstr(tmp_wlan_buf, "connected") != NULL)
			curr_state = "connected";
		else if (strstr(tmp_wlan_buf, "disabled") != NULL)
			curr_state = "disabled";
		else
			curr_state = "no device";

		if (strcmp(curr_state, last_wlan_state) != 0) {
			sprintf(WlanState_msg, "eth0 : %s", curr_state);
			strcpy(last_wlan_state, curr_state);
			retval = WlanState_msg;
		}
		break;

retry:
		usleep(100 * 1000);
		continue;
	}
	return retval;
}