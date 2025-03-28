#include <linux/module.h>  // 包含模块相关的宏和函数
#include <linux/types.h>   // 包含内核数据类型
#include <linux/init.h>    // 包含模块初始化和退出宏
#include <linux/kernel.h>  // 包含内核打印函数
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/range.h>
#include <linux/uaccess.h>
#include <linux/slab.h>
#include <linux/platform_device.h>
#include "./my_common.h"

// 这个文件负责文件操作以及/dev设备文件的创建

static int major;
static const char* _dev_name = "a_my_test";
static struct class *_class;
struct device* _device;
struct resource *res;
struct gpio_desc *_led_gpio;

// 设备和驱动匹配后创建设备文件
void my_create_dev(struct platform_device *hd, struct gpio_desc *led_gpio)
{
    _led_gpio = led_gpio;
    // int i = 0;
    printk("%s\n", __FUNCTION__);
    // 获得资源
    /**type对应的是resource中的flags
     */
    // while(1) {
    //     res = platform_get_resource(hd, IORESOURCE_IRQ, i);
    //     if(!res) {
    //         break;
    //     }
    //     i++;
    // }
    // printk("res num:%d\n", i);

    // 创建/dev文件夹下的文件
    _class = class_create(THIS_MODULE, _dev_name);
	if (IS_ERR(_class)) {
		printk("%s %s line %d\n", __FILE__, __FUNCTION__, __LINE__);
		unregister_chrdev(major, _dev_name);
		return;
	}

    _device = device_create (
        _class, NULL,
        MKDEV(major, 12),
        NULL,
        _dev_name);

    if(IS_ERR(_device)) {
		printk("%s %s line %d\n", __FILE__, __FUNCTION__, __LINE__);
		return;
    }
}
EXPORT_SYMBOL(my_create_dev);

ssize_t my_read(struct file * file, char __user * buffer, size_t size, loff_t * offset)
{
    struct qstr name;
    printk("%s\n", __FUNCTION__);
    name = file->f_path.dentry->d_name;
    printk("name: %s\n", name.name);
    return 0;
}

ssize_t my_write (struct file * file, const char __user * buffer, size_t size, loff_t * offset)
{
	int err;
    int set_val;

    err = copy_from_user(&set_val, buffer, sizeof(set_val));
    if(IS_ERR_VALUE(err)) {
        printk("%s, %s, %d\n", __FILE__, __FUNCTION__, __LINE__);
        return -1;
    }

    printk("wirte file:%d", set_val);
    gpiod_set_value(_led_gpio, set_val);

    return 0;
}

int my_open (struct inode * node, struct file * file)
{
    struct qstr name;

    printk("%s\n", __FUNCTION__);
    name = file->f_path.dentry->d_name;
    printk("name: %s\n", name.name);
    // 先设置gpio为输出模式
    gpiod_direction_output(_led_gpio, 0);
    return 0;
}

int my_release (struct inode *node, struct file *file)
{
    printk("%s\n", __FUNCTION__);
    // 设置为高阻
    // gpiod_direction_input(_led_gpio);
    return 0;
}

// 模块初始化函数
static int __init my_init(void)
{
    // 创建一个设备号，向内核注册file_operations
    static struct file_operations dev_drv = {
        .owner = THIS_MODULE,
        .read = my_read,
        .write = my_write,
        .open = my_open,
        .release = my_release,
    };
    // major = 0不指定分配
    major = register_chrdev(0, _dev_name, &dev_drv);
    printk("major: %d\n", major);

    return 0;
}

// 模块退出函数
static void __exit my_exit(void)
{
    if(_device) {
        device_destroy(_class, MKDEV(major, 12));
    }
    class_destroy(_class);
    unregister_chrdev(major, _dev_name);
    printk(KERN_INFO "exit\n");  // 使用 KERN_INFO 指定日志级别
}

// 注册模块初始化和退出函数
module_init(my_init);
module_exit(my_exit);

// 模块许可证声明
MODULE_LICENSE("GPL");
// 模块描述（可选）
MODULE_DESCRIPTION("A simple Linux kernel module");
// 作者信息（可选）
MODULE_AUTHOR("Your Name");