#include <linux/module.h>

#include <linux/fs.h>
#include <linux/errno.h>
#include <linux/miscdevice.h>
#include <linux/kernel.h>
#include <linux/major.h>
#include <linux/mutex.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/stat.h>
#include <linux/init.h>
#include <linux/device.h>
#include <linux/tty.h>
#include <linux/kmod.h>
#include <linux/gfp.h>
#include <linux/gpio/consumer.h>
#include <linux/platform_device.h>
#include <linux/of_gpio.h>
#include <linux/of_irq.h>
#include <linux/interrupt.h>
#include <linux/irq.h>
#include <linux/slab.h>

static int __init my_test_init()
{
	printk(KERN_DEBUG "%d init\n", __FUNCTION__);

	return 0;
}

static void __exit my_test_exit()
{
	printk(KERN_DEBUG "%d exit\n", __FUNCTION__);
	return 0;
}
// 模块注册
module_init(my_test_init)

// 模块deinit
module_exit(my_test_exit)
MODULE_LICENSE("GPL");
