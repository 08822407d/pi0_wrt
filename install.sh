#!/bin/bash


INSTALL_PATH="/usr/local/bin"
SERVICE_PATH="/etc/systemd/system"



# 安装以太网和热点配置脚本并加入后台服务
PACKAGE_PATH=.
EXEC_NAME=APconfig.sh
SEVICE_CONFIG=APconfig.service

#修改service文件中程序的路径
sed -i "/.*ExecStart*/c\ExecStart=$INSTALL_PATH/$EXEC_NAME" "$SEVICE_CONFIG"

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



# 安装屏显程序并加入后台服务
if [ "$#" -eq 1 ] && [ "$1" != "screen_display" ]; then
    # 定义安装路径
    PACKAGE_PATH=wrt_info
    EXEC_NAME=wrt_info
    SEVICE_CONFIG=net_info.service

    #修改service文件中程序的路径
    sed -i "/.*ExecStart*/c\ExecStart=$INSTALL_PATH/$EXEC_NAME" "$SEVICE_CONFIG"

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
fi