#!/bin/bash

# 1. 使用不同的开发板内核时, 一定要修改KERN_DIR
# 2. KERN_DIR中的内核要事先配置、编译, 为了能编译内核, 要先设置下列环境变量:
# 2.1 ARCH,          比如: export ARCH=arm64
# 2.2 CROSS_COMPILE, 比如: export CROSS_COMPILE=aarch64-linux-gnu-
# 2.3 PATH,          比如: export PATH=$PATH:/home/book/100ask_roc-rk3399-pc/ToolChain-6.3.1/gcc-linaro-6.3.1-2017.05-x86_64_aarch64-linux-gnu/bin 
# 注意: 不同的开发板不同的编译器上述3个环境变量不一定相同,
#       请参考各开发板的高级用户使用手册

export ARCH=arm
export CROSS_COMPILE=arm-linux-gnueabihf-
export PATH=$PATH:/opt/gcc-linaro-7.5.0-2019.12-x86_64_arm-linux-gnueabihf/bin
export MY_KERN_DIR=/home/ubuntu18/Desktop/ebf_linux_kernel/build_image/build

cd app
source evn.sh
cd ..
rm -f ./compile_commands.json
ln -s /home/ubuntu18/Desktop/ebf_linux_kernel/compile_commands.json  ./compile_commands.json

# 验证路径是否存在（可选）
if [ -d "/home/ubuntu18/Desktop/ebf_linux_kernel/build_image/build" ]; then
    echo "环境变量已生效: PATH 包含交叉编译工具链"
else
    echo "错误：工具链路径不存在，请检查路径！"
fi

