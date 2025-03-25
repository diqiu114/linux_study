# 参考内核源码drivers/char/ipmi/Makefile
# 要想把a.c, b.c编译成ab.ko, 可以这样指定:
# ab-y := a.o b.o
# obj-m += ab.o

obj-m += drv_template.o
# 设置app的名字
app_name = "app_template"

run:
	make -j$(nproc) all
	cp *.ko /home/ubuntu18/Desktop/mnt
	cp $(app_name) /home/ubuntu18/Desktop/mnt
all:
	echo "======== run ========"
	make -C $(MY_KERN_DIR) M=$(PWD) modules
	$(CROSS_COMPILE)gcc app_template.c -o $(app_name)
	echo "\e[32m======= make ok ========\e[0m"
	make some_clean
	echo "\e[32m======= clean ok ========\e[0m"

some_clean:
	rm -f modules.order *.o .*.cmd *.mod.c *.mod *.mod *.symvers *.elf

clean:
	rm -f *.ko ledtest $(app_name)
	make some_clean
	echo "\e[32m======= clean ok ========\e[0m"


