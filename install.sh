#!/bin/bash

# 定义安装路径
BIN_PATH=wrt_info
PROGRAM=wrt_info
SEVICE_CONFIG=pi0_wrt.service
INSTALL_PATH="/usr/local/bin"
SERVICE_PATH="/etc/systemd/system"

#修改service文件中程序的路径
sed -i "/.*ExecStart*/c\ExecStart=$INSTALL_PATH/$PROGRAM" "$SEVICE_CONFIG"

sudo systemctl stop $SEVICE_CONFIG
# 复制程序文件到安装路径
echo "Installing $PROGRAM to $INSTALL_PATH..."
sudo cp $BIN_PATH/$PROGRAM $INSTALL_PATH/$PROGRAM
sudo chmod +x $INSTALL_PATH/$PROGRAM

# 复制systemd服务文件
echo "Setting up systemd service..."
sudo cp $SEVICE_CONFIG $SERVICE_PATH/$SEVICE_CONFIG

# 重新加载systemd配置并启动服务
sudo systemctl daemon-reload
sudo systemctl enable $SEVICE_CONFIG
sudo systemctl start $SEVICE_CONFIG

echo "Installation complete!"
