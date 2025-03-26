#ifndef __MY_COMMON_H
#define __MY_COMMON_H

#ifdef __cplusplus
extern "C" {
#endif

#include <linux/platform_device.h>

#define pf_name "pf_led"

extern void my_create_dev(struct platform_device *hd);

#ifdef __cplusplus
}
#endif


#endif




