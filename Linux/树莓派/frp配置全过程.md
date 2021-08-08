### Winser端
在`https://github.com/fatedier/frp/releases`下载Windows版(zip格式)，解压
编辑frps.ini，改完内容如下：
```
[common]
bind_port = 7000
token = 123k4567
```

注册服务：
>在`https://github.com/kohsuke/winsw/releases`下载WinSW-x64.exe<br/>
>放在frps.exe所在目录<br/>
>在该目录新建WinSW-x64.xml文件<br/>
>内容如下：<br/>
>```
><service>
>    <id>frp</id>
>    <name>frp</name> <!-- 这里是服务的名称 -->
>    <description>这里是服务的介绍，随便写</description>
>    <executable>frps</executable><!-- 这里是运行的软件名 -->
>    <arguments>-c frps.ini</arguments><!-- 这里是运行的软件配置文件 -->
>    <onfailure action="restart" delay="60 sec"/>
>    <onfailure action="restart" delay="120 sec"/>
>    <logmode>reset</logmode>
></service>
>```
>然后打开cmd<br/>
>cd到该目录<br/>
>执行.\WinSW-x64.exe install<br/>
>然后就可以去services管理服务了<br/>
### 树莓派端
在`https://github.com/fatedier/frp/releases`下载linux-arm版(.tar.gz格式)，解压
编辑frps.ini，改完内容如下：
```
[common]
server_addr = 121.4.61.187  #服务器IP
server_port = 7000          #服务器端口
token = 123k4567            #密码
[ssh]
type = tcp
local_ip = 127.0.0.1
local_port = 22
remote_port = 6000
```
注册服务：
>在`/usr/lib/systemd/system`目录下添加文件frpc.service，内容如下：
>```
>[Unit]
>Description=frpc
>After=network.target
>
>[Service]
>TimeoutStartSec=30
>ExecStart=/home/pi/frp_0.36.2_linux_arm/frpc -c /home/pi/frp_0.36.2_linux_arm/frpc.ini
>ExecStop=/bin/kill $MAINPID
>
>[Install]
>WantedBy=multi-user.target
>```
ExecStart后的内容根据具体路径修改，总之是frpc -c frpc.ini<br/>
启动服务：`systemctl start frpc`<br/>
停止服务：`systemctl stop frpc`<br/>
开机自启：`systemctl enable frpc`<br/>
