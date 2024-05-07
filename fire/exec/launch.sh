#!/bin/bash
# 没有build创建build
if [ ! -d "./build" ]; then
mkdir build
fi

cd build
cmake ../ && cmake --build .
# 判断前一个命令是否执行正确
if [ $? -eq 0 ]; then
    # 运行app
    if [ -n "$1" ]; then
        echo "================== run app =================="
        $1
    else
        echo "==================  No application is specified =================="
        ./run_me
    fi
fi
cd  ..