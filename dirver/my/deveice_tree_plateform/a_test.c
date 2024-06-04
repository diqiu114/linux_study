#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>

#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/delay.h>
#include <linux/ide.h>
#include <linux/errno.h>
#include <linux/gpio.h>
#include <asm/mach/map.h>
#include <linux/of.h>
#include <linux/of_address.h>
#include <linux/of_gpio.h>
#include <asm/io.h>
#include <linux/device.h>

#include <linux/platform_device.h>
#include <linux/gpio/consumer.h>

/*------------------字符设备内容----------------------*/
#define DEV_NAME "rgb_led"
#define DEV_CNT (1)


static struct cdev led_chr_dev;			 //定义字符设备结构体chr_dev
struct class *class_led;				 //保存创建的类
struct device *device;					 // 保存创建的设备
struct device_node *rgb_led_device_node; //rgb_led的设备树节点结构体

/*定义 R G B 三个灯的led_resource 结构体，保存获取得到的节点信息*/
struct led_resource led_red;
struct led_resource led_green;
struct led_resource led_blue;

/*字符设备操作函数集，open函数*/
static int led_chr_dev_open(struct inode *inode, struct file *filp)
{
	printk(KERN_EMERG "\n open form driver \n");
	return 0;
}

/*字符设备操作函数集，write函数*/
static ssize_t led_chr_dev_write(struct file *filp, const char __user *buf, size_t cnt, loff_t *offt)
{
	static uint32_t num;
	num++;	
    printk(KERN_EMERG "%s, %s, ===== cnt:%d\r\n", __FILE__, __FUNCTION__, num);
	return 0;
}

/*字符设备操作函数集*/
static struct file_operations led_chr_dev_fops =
	{
		.owner = THIS_MODULE,
		.open = led_chr_dev_open,
		.write = led_chr_dev_write,
};

/*----------------平台驱动函数集-----------------*/
static int led_probe(struct platform_device *pdv)
{

	int ret = -1; //保存错误状态码
	unsigned int register_data = 0;

	printk(KERN_EMERG "\t  match successed  \n");

	gpiod_get();

	//第四步
	/*创建类 */
	class_led = class_create(THIS_MODULE, DEV_NAME);

	/*创建设备*/
	device = device_create(class_led, NULL, led_devno, NULL, DEV_NAME);

	return 0;

add_err:
	//添加设备失败时，需要注销设备号
	unregister_chrdev_region(led_devno, DEV_CNT);
	printk(KERN_EMERG "\n error! \n");
alloc_err:

	return -1;
}

static const struct of_device_id rgb_led[] = {
	{.compatible = "fire,rgb_led_red"},
	};

/*定义平台设备结构体*/
struct platform_driver led_platform_driver = {
	.probe = led_probe,
	.driver = {
		.name = "led_test",
		.owner = THIS_MODULE,
		.of_match_table = rgb_led,
	}};

/*
*驱动初始化函数
*/
static int __init led_platform_driver_init(void)
{
	int DriverState;
	DriverState = platform_driver_register(&led_platform_driver);
	printk(KERN_EMERG "\tDriverState is %d\n", DriverState);
	return 0;
}

/*
*驱动注销函数
*/
static void __exit led_platform_driver_exit(void)
{
	/*删除设备*/
	device_destroy(class_led, led_devno);		  //清除设备
	class_destroy(class_led);					  //清除类
	cdev_del(&led_chr_dev);						  //清除设备号
	unregister_chrdev_region(led_devno, DEV_CNT); //取消注册字符设备

	/*注销字符设备*/
	platform_driver_unregister(&led_platform_driver);

	printk(KERN_EMERG "HELLO WORLD exit!\n");
}

module_init(led_platform_driver_init);
module_exit(led_platform_driver_exit);

MODULE_LICENSE("GPL");


/*
编译、加载内核模块后 终端会输出内核分配到的主、子设备号（也可以cat /proc/devices）
由于alloc_chrdev_region不会创建设备文件，
需要创建： mknod /dev/xxx c 主设备号 次设备号	
测试方法：sudo sh -c "echo 'EmbedCharDev test' > /dev/xxx"
*/
