#!/bin/bash
if [ !-n $1 ]
then
    printf "不能带参数！请去掉参数再试。\n"
    exit 20
fi

printf "输入源扩展名:"
read ext_from

printf "输入目标扩展名:"
read ext_to

set $ext_from $ext_to   #ext_from成为$1,ext_to成为$2

printf "将把所有扩展名为$1的文件的扩展名改为$2,请确认[y/n]"

read response

case $response in 
y|Y)
    shift   # $1被舍弃, $2变为$1
    shift   # $1被舍弃
    for fname in $(ls | grep *.$ext_from)
    do
        mv ${fname} ${fname%%.$ext_from}.$ext_to
        # ${fname%%.$ext_from}表示从fname末端去除.$ext_from(包含“点”)
        # 此处这种情况下%%可换成单个%
    done
    ;;
*)
    printf "您亲自取消了任务\n"
    exit 0
    ;;
esac