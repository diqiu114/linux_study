KERNEL_DIR=~/Desktop/ebf_linux_kernel/build_image/build

ARCH=arm
CROSS_COMPILE=arm-linux-gnueabihf-
export  ARCH  CROSS_COMPILE

obj-m :=a_test.o

all:
	$(MAKE) -C $(KERNEL_DIR) M=$(CURDIR) modules

.PHONE:clean 

clean:
	$(MAKE) -C $(KERNEL_DIR) M=$(CURDIR) clean	
