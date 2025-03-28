cmake_minimum_required (VERSION 3.5)

set(MY_NAME $ENV{MY_NAME})

project (${MY_NAME})

set(TOOLCHAIN_PATH "/opt/gcc-linaro-7.5.0-2019.12-x86_64_arm-linux-gnueabihf")
set(CMAKE_C_COMPILER ${TOOLCHAIN_PATH}/bin/arm-linux-gnueabihf-gcc)
set(CMAKE_CXX_COMPILER ${TOOLCHAIN_PATH}/bin/arm-linux-gnueabihf-g++)

include_directories(
    ${TOOLCHAIN_PATH}/bin/../lib/gcc/arm-linux-gnueabihf/7.5.0/include
    ${TOOLCHAIN_PATH}/bin/../lib/gcc/arm-linux-gnueabihf/7.5.0/include-fixed
    ${TOOLCHAIN_PATH}/bin/../lib/gcc/arm-linux-gnueabihf/7.5.0/../../../../arm-linux-gnueabihf/include
    ${TOOLCHAIN_PATH}/bin/../arm-linux-gnueabihf/libc/usr/include
)

add_executable(${MY_NAME} app_template.c)
