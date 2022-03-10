#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Tuna Tuncer");
MODULE_DESCRIPTION("Hello World Linux Driver");
MODULE_VERSION("0.1");

static int hello_init(void) 
{
    printk(KERN_ALERT "Hello, world!\n");
    return 0;
}

static void hello_exit(void)
{
    printk(KERN_ALERT "Goodbye, cruel world!\n");
}

module_init(hello_init);
module_exit(hello_exit);

