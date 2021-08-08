#!/bin/bash

cd /home/K/Document/安卓代码片段
git add -A
#timenow=$(date +"%m月%d日 %A %H:%M:%S %Y年")

while true
do

    read -p "是否要自定义提交说明？[Y/N]" info

    case $info in
        "Y")
        echo "请输入提交说明："
        read commitinfo
        break;;

        "y")
        echo "请输入提交说明："
        read commitinfo
        break;;

        "N")
        timenow=$(date +"%Y-%m-%d %H:%M:%S")
        commitinfo="$timenow Linux提交"
        break;;

        "n")
        timenow=$(date +"%Y-%m-%d %H:%M:%S")
        commitinfo="$timenow Linux提交"
        break;;
        *)
        continue;;
    esac

done

echo "。。。。。。。。。。提交已开始。。。。。。。。。。"
git commit -m "$commitinfo"
git push origin master
echo "。。。。。提交完成，即将跳转github。。。。。"
google-chrome https://github.com/HulaHulaKang/Android
