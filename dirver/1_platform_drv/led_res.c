#include <linux/module.h>
#include <linux/platform_device.h>
#include "./my_common.h"

static struct resource resources[] = {
    {
            .start = 1,
            .flags = IORESOURCE_IRQ,
            .name = "100ask_led_pin",
    },
    {
            .start = 2,
            .flags = IORESOURCE_IRQ,
            .name = "100ask_led_pin",
    },
};

static void release(struct device *dev)
{
    printk("%s\n", __FUNCTION__);
}

static struct platform_device board_A_led_dev = {
    .resource = resources,
    .name = pf_name,
    .num_resources = ARRAY_SIZE(resources),
    .dev = {
        .release = release,
 },
};


/**
    平台驱动分为设备和驱动
    一个驱动对应多个设备，只要把需要指定的相关资源传给设备就行
    自顶向下写程序的话，首先是设备，要让内核能找到设备
*/

// ================= 设备相关 ===================
// 注册


static __init int pf_dev_init(void)
{
    printk("%s\n", __FUNCTION__);
    platform_device_register(&board_A_led_dev);
    return  0;
}

static __exit void pf_dev_exit(void)
{
    printk("%s\n", __FUNCTION__);
    platform_device_unregister(&board_A_led_dev);
}

module_init(pf_dev_init);
module_exit(pf_dev_exit);

MODULE_LICENSE("GPL");



