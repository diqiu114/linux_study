#include <linux/module.h>
#include <linux/platform_device.h>
#include "./my_common.h"

// 在这个属性中进行/dev/下设备注册
int probe(struct platform_device *dev)
{
    printk("%s\n", __FUNCTION__);
    my_create_dev(dev);
    return 0;
}

int remove(struct platform_device *dev)
{
    printk("%s\n", __FUNCTION__);

    return 0;
}


static struct platform_driver pf_drv = {
    // 当name和设备匹配上后就会调用probe
    .driver = {
        .name = pf_name,
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

