#include <linux/init.h>
#include <linux/module.h>

/*驱动注册的头文件，包含驱动的结构体和注册和卸载的函数*/
#include <linux/platform_device.h>

#define DRIVER_NAME "hello_ctl"

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("TOPEET");

static void	leds_release(struct device *dev)
{
	printk(KERN_EMERG "leds_release");
}

struct platform_device platform_device_hello = {
	.name   = "hello_ctl",
	.id     = -1,
	.dev = {
		.release = leds_release,
	}
};

static int hello_init(void)
{
	printk(KERN_EMERG "hello_init");
	platform_device_register(&platform_device_hello);
	return 0;
}

static void hello_exit(void)
{
	platform_device_unregister(&platform_device_hello);
}

module_init(hello_init);
module_exit(hello_exit);
