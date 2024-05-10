KERNEL_DIR=/home/yzq-linux/Desktop/ebf_linux_kernel/build_image/build

ARCH=arm
CROSS_COMPILE=arm-linux-gnueabihf-
# 导出为环境变量，确保这些变量在所有子进程中都是可见的。
export  ARCH  CROSS_COMPILE

obj-m := hellomodule.o
# 切换到KERNEL_DIR中去执行make命令，并执行目标：modules
# M= 表示KERNEL_DIR中变量M设置为=后面内容
all:
	$(MAKE) -C $(KERNEL_DIR) M=$(CURDIR) modules

.PHONE:clean copy

clean:
	$(MAKE) -C $(KERNEL_DIR) M=$(CURDIR) clean	

copy:
	sudo  cp  *.ko  ~/Desktop/mnt/