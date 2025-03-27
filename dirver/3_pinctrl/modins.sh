#!/bin/bash
args=$1
args_seach=""
ins="ins"
rm="rm"
dtb="dtb"
my_args="$ins $rm $dtb"


mods_name="reg_chrdev.ko led_drv.ko"
# mods_name=$(ls *.ko)
# echo "===$mods_name"

for val in $my_args; do
    if [ "$args" == "$val" ]; then
        args_seach=$val
        break
    fi
done

if [ -z $args_seach ]; then
    echo "请输入参数：$my_args"
    exit 1
else
    echo "running"
fi

# 开始选择安装或者卸载模块
if [ "$args_seach" == "$ins" ]; then
    for val in $mods_name; do
        echo -e "\e[32m->insmod $val\e[0m"
        insmod $val
    done
elif [ "$args_seach" == "$rm" ]; then
    # 倒序
    reversed_mods=$(echo "$mods_name" | tr ' ' '\n' | tac | paste -sd ' ')
    # echo "$reversed_mods"
    for val in $reversed_mods; do
        echo -e "\e[32m->rmmod $val\e[0m"
        rmmod $val
    done

elif [ "$args_seach" == "$dtb" ]; then
    mv ./imx6ull-mmc-npi.dtb  /usr/lib/linux-image-4.19.35-imx6/
fi

