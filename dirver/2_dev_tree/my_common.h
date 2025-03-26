#ifndef __MY_COMMON_H
#define __MY_COMMON_H

#ifdef __cplusplus
extern "C" {
#endif

#include <linux/platform_device.h>

#define pf_name "pf_led"
#define DEV_TREE_NODE_NAME  "fire,rgb_led_red"
// #define DEV_TREE_NODE_NAME  "rgb_led_red"


extern void my_create_dev(struct platform_device *hd);

#ifdef __cplusplus
}
#endif


#endif




