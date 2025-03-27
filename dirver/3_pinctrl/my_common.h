#ifndef __MY_COMMON_H
#define __MY_COMMON_H

#ifdef __cplusplus
extern "C" {
#endif

#include <linux/platform_device.h>
#include <linux/gpio/consumer.h>

#define pf_name "pf_led"
#define DEV_TREE_NODE_NAME  "fire,rgb_led_red"
// #define DEV_TREE_NODE_NAME  "rgb_led_red"


void my_create_dev(struct platform_device *hd, struct gpio_desc *led_gpio);

#ifdef __cplusplus
}
#endif


#endif




