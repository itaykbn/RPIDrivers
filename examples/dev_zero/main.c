#include <linux/cdev.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

/*Declarations*/
ssize_t myzero_write(struct file *f, const char __user *buf, size_t sz,
                     loff_t *off);
/*Consts*/
static struct file_operations my_fops = {.owner = THIS_MODULE,
                                         .write = myzero_write};
static unsigned minors_count = 1;
/*Vars*/
struct cdev *my_cdev = NULL;
struct class *my_class = NULL;
dev_t my_dev = 0;

static int __init myzero_init(void) {
  int err = 0;

  /*Allocate Major and Minor numbers*/
  err = alloc_chrdev_region(&my_dev, 255, minors_count, THIS_MODULE->name);
  if (0 != err) {
    pr_err("alloc_chrdev_region: failed");
    goto cleanup_nothing;
  }

  pr_info("Allocated MAJOR: %d, MINOR: %d", MAJOR(my_dev), MINOR(my_dev));

  /*Allocate cdev and add*/
  my_cdev = cdev_alloc();
  if (NULL == my_cdev) {
    err = -1;
    pr_err("cdev_alloc: failed");
    goto cleanup_dev_region;
  }

  cdev_init(my_cdev, &my_fops);
  err = cdev_add(my_cdev, my_dev, minors_count);
  if (0 != err) {
    pr_err("cdev_add: failed");
    goto cleanup_cdev;
  }

  my_class = class_create("myzero_class");
  if (IS_ERR(my_class)) {
    pr_err("class_create: failed");
    goto cleanup_cdev;
  }

  if (IS_ERR(device_create(my_class, NULL, my_dev, NULL, "myzero_device"))) {
    pr_err("class_create: failed");
    goto cleanup_class;
  }

  pr_info("init function complete!");
  goto cleanup_nothing;

cleanup_class:
  class_destroy(my_class);
  my_class = NULL;
cleanup_cdev:
  cdev_del(my_cdev);
  my_cdev = NULL;
cleanup_dev_region:
  unregister_chrdev_region(my_dev, minors_count);
  my_dev = 0;
cleanup_nothing:
  return err;
};

ssize_t myzero_write(struct file *f, const char __user *buf, size_t sz,
                     loff_t *off) {
  return sz;
}

static void __exit myzero_exit(void) {
  device_destroy(my_class, my_dev);
  my_class = NULL;
  class_destroy(my_class);
  my_class = NULL;
  cdev_del(my_cdev);
  my_cdev = NULL;
  unregister_chrdev_region(my_dev, minors_count);
  my_dev = 0;
}

// Ixit and init functions
module_init(myzero_init);
module_exit(myzero_exit);

// Module Definitions
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Kabangoose");
MODULE_DESCRIPTION("Own implemetation of dev zero");
MODULE_VERSION("1.0");
