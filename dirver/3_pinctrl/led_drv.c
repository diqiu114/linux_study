#include <linux/module.h>  // 包含模块相关的宏和函数
#include <linux/types.h>   // 包含内核数据类型
#include <linux/init.h>    // 包含模块初始化和退出宏
#include <linux/kernel.h>  // 包含内核打印函数
#include <linux/err.h>
#include <linux/of.h>
#include <linux/platform_device.h>
#include "./my_common.h"
#include <linux/of_device.h>

static struct class *led_class;
struct gpio_desc *led_gpio;
EXPORT_SYMBOL(led_gpio);

// 在这个属性中进行/dev/下设备注册
int probe(struct platform_device *dev)
{
	/* 4.1 设备树中定义有: led-gpios=<...>;	*/

    led_gpio = gpiod_get(&dev->dev, "led", 0);
	if (IS_ERR(led_gpio)) {
		dev_err(&dev->dev, "Failed to get GPIO for led\n");
		return PTR_ERR(led_gpio);
	}
    
    my_create_dev(dev, led_gpio);
    return 0;
}

int remove(struct platform_device *dev)
{
    printk("%s\n", __FUNCTION__);
    gpiod_put(led_gpio);
    return 0;
}

static const struct of_device_id ask100_leds[] = {
    { .compatible = "fire,rgb_led_red_root" },
    { },
};

static struct platform_driver pf_drv = {
    // 当name和设备匹配上后就会调用probe
    .driver = {
        .name = pf_name,
        .of_match_table = ask100_leds,
    },
    .probe =  probe,
    .remove = remove,
};

// 驱动相关
static __init int pf_drv_init(void)
{
    printk("%s\n", __FUNCTION__);
    platform_driver_register(&pf_drv);
    return  0;
}

static __exit void pf_drv_exit(void)
{
    printk("%s\n", __FUNCTION__);
    platform_driver_unregister(&pf_drv);
}

module_init(pf_drv_init)
module_exit(pf_drv_exit)


MODULE_LICENSE("GPL");

