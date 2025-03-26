#include <linux/module.h>  // 包含模块相关的宏和函数
#include <linux/types.h>   // 包含内核数据类型
#include <linux/init.h>    // 包含模块初始化和退出宏
#include <linux/kernel.h>  // 包含内核打印函数
#include <linux/err.h>
#include <linux/of.h>
#include <linux/platform_device.h>
#include "./my_common.h"
#include <linux/of_device.h>

// 在这个属性中进行/dev/下设备注册
int probe(struct platform_device *dev)
{
    u32 val[2];
    int size;
    struct device_node* np = dev->dev.of_node;
    // struct resource res;
    int err;
    struct device_node* sub_node;
    struct property *prop;

    printk("%s\n", __FUNCTION__);
    sub_node = of_find_compatible_node(np, NULL, "fire,rgb_led_red");
    if(!sub_node) {
        printk("sub_node err: %s", __FUNCTION__);
        return -1;
    }
    // 这里确定一下获取到的设备树节点是对的
    printk("sub node name:%s\n", sub_node->name);

    err = of_property_read_u32_array(sub_node, "reg", val, ARRAY_SIZE(val));
    if(err!=0) {
        printk("of_property_read_u32_array\n");
        return -1;
    }

    printk("reg val:0x%x, 0x%x", val[0], val[1]);
    
    my_create_dev(dev);
    return 0;
}

int remove(struct platform_device *dev)
{
    printk("%s\n", __FUNCTION__);

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

