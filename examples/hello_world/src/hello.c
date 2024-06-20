#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

static int __init hello_init(void) {
  printk(KERN_ALERT "Hello Im In Kernel.\n");
  return 0;
}

static void __exit hello_exit(void) { printk(KERN_ALERT "Kernel Out\n"); }

module_init(hello_init);
module_exit(hello_exit);
MODULE_LICENSE("ECE");
MODULE_DESCRIPTION("Test Module");
MODULE_AUTHOR("Itay Kabanovsky");
