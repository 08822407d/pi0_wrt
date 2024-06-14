#!/bin/bash

# 定义以太网接口名称和 WiFi 热点名称
HOTSPOT_SSID="pi0-wrt"
HOTSPOT_PASSWD="cheyh18700872141"

ETH_INTERFACE="eth0"
WLAN_INTERFACE="wlan0"


# 检查以太网连接状态
ETH_STATUS=$(cat /sys/class/net/$ETH_INTERFACE/operstate)

# 检查热点状态
HOTSPOT_STATUS=$(nmcli dev status | grep "$HOTSPOT_SSID" | awk '{print $3}')

if [ "$ETH_STATUS" = "down" ]; then
    # 以太网未连接，关闭热点
    if [ "$HOTSPOT_STATUS" = "connected" ]; then
        sudo nmcli connection down $HOTSPOT_SSID
        echo "Ethernet is down. Hotspot has been turned off."
    fi
else
    # 以太网已连接，开启热点
    if [ "$HOTSPOT_STATUS" != "connected" ]; then
        sudo nmcli dev wifi hotspot ifname $WLAN_INTERFACE ssid $HOTSPOT_SSID password $HOTSPOT_PASSWD
        echo "Ethernet is up. Hotspot has been turned on."
    fi
fi