# 中文输入法安装流程：

<font color="blue">(这里是以KDE环境为例,其他环境没有尝试过)</font>



[1]`sudo     pacman      -S       fcitx5         fcitx5-configtool       fcitx5-chinese-addons`



[2]<kbd>系统设置</kbd>     ——>      <kbd>区域设置</kbd>        ——>      <kbd>输入法</kbd>

​                    <kbd>拼音</kbd>右边的<kbd>配置</kbd>图标

​            选中<kbd>启用云拼音</kbd>和<kbd>在程序中显示预编译文本</kbd>



[3]<code>vim      ~/.pam_environment </code>（原本是没有这个文件的）
        添加：

>             INPUT_METHOD DEFAULT=fcitx5
>             GTK_IM_MODULE DEFAULT=fcitx5
>             QT_IM_MODULE DEFAULT=fcitx5
>             XMODIFIERS DEFAULT=\@im=fcitx5



[4]<kbd>系统设置</kbd>     ——>      <kbd>开机和关机</kbd>      ——>      <kbd>自动启动</kbd>
     

​						 添加:<kbd>fcitx5</kbd>



# 使用

<font color="orange">可以试试按这两个按键组合：</font>

<kbd>Ctrl</kbd>+<kbd>                                   </kbd>

<kbd>Ctrl</kbd>+<kbd>Shift</kbd>









--------------------------------------------------------------------
某次按照此流程配置失败，但按照如下网址配置成功
https://blog.csdn.net/michaelq12/article/details/107747790
