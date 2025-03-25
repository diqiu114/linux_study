#include <linux/module.h>  // 包含模块相关的宏和函数
#include <linux/types.h>   // 包含内核数据类型
#include <linux/init.h>    // 包含模块初始化和退出宏
#include <linux/kernel.h>  // 包含内核打印函数

// 模块初始化函数
static int __init my_init(void)
{
    printk(KERN_INFO "init\n");  // 使用 KERN_INFO 指定日志级别
    return 0;  // 返回 0 表示初始化成功
}

// 模块退出函数
static void __exit my_exit(void)
{
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