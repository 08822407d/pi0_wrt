#!/bin/bash

# 定义安装路径
INSTALL_PATH="/usr/local/bin"
SERVICE_PATH="/etc/systemd/system"
PACKAGE_PATH=i2c_1in3_oled
EXEC_NAME=wrt_info
SEVICE_CONFIG=wrt_info.service

# 安装屏显程序并加入后台服务
#修改service文件中程序的路径
sed -i "/.*ExecStart*/c\ExecStart=$INSTALL_PATH/$EXEC_NAME" "$SEVICE_CONFIG"
sed -i "/.*ExecReload*/c\ExecReload=$INSTALL_PATH/$EXEC_NAME" "$SEVICE_CONFIG"

sudo systemctl stop $SEVICE_CONFIG
# 复制程序文件到安装路径
echo "Installing $EXEC_NAME to $INSTALL_PATH..."
sudo cp $PACKAGE_PATH/$EXEC_NAME $INSTALL_PATH/$EXEC_NAME
sudo chmod +x $INSTALL_PATH/$EXEC_NAME

# 复制systemd服务文件
echo "Setting up systemd service..."
sudo cp $SEVICE_CONFIG $SERVICE_PATH/$SEVICE_CONFIG

# 重新加载systemd配置并启动服务
sudo systemctl daemon-reload
sudo systemctl enable $SEVICE_CONFIG
sudo systemctl start $SEVICE_CONFIG

echo "Installation complete!"