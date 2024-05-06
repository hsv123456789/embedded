#include <linux/module.h>
#include <linux/init.h>
/*META INFORMATION*/
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Raghav 4 GNU/Linux");
MODULE_DESCRIPTION("A hello world Linux kernal module");
// @brief This function is called, when the module is loaded into the kernel
static int __init hello_start(void)
{
printk ("Hello, I'm here to help\n");
return 0;
}
// @brief This function is called, when the module is removed into the kernel
static void __exit hello_end(void)
{
printk("Goodbye, I hope I was helpful\n");
}
module_init(hello_start);
module_exit(hello_end