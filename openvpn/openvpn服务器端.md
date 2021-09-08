# openvpn服务器端配置

本教程针对华南理工大学大学城校区校园网  

## 前提条件

服务器系统为Linux(我用的是Ubuntu，网络上相同方法用的是CentOS，所以估计多数Linux都可以)  
服务器已安装git  

## 步骤

```sh
git clone https://github.com/angristan/openvpn-install
cd openvpn
sudo ./openvpn-install.sh
#下面开始安装过程，需要选择一些选项
#端口相关的，选Custom和67
#选UDP
#client名称随便起,比如myclient_67
#其余的一路回车
```

注：我还去阿里云控制台放通了67端口，不知道实际需不需要  

安装完成后：  

```sh
cd ~
ls
#这个目录下有myclient_67.ovpn文件（名称是安装时自己起的）
#想办法把它弄到本地机(比如用cat命令，然后复制)
#在本地openvpn connect中导入该文件
#连校园网WiFi的情况下当时测试是有效的，连手机热点时反而连接失败
```