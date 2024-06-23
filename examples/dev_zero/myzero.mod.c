#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/export-internal.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

#ifdef CONFIG_UNWINDER_ORC
#include <asm/orc_header.h>
ORC_HEADER;
#endif

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif



static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x3ffca6f, "class_destroy" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x122c3a7e, "_printk" },
	{ 0xaa4bd0fd, "cdev_add" },
	{ 0x6f019f5b, "device_create" },
	{ 0x18f6c465, "class_create" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x4c10d953, "device_destroy" },
	{ 0x4db7e644, "cdev_init" },
	{ 0xbe6f9fff, "cdev_del" },
	{ 0xe01e091c, "cdev_alloc" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0xe7d3c602, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "F9E222DAE39D83EBE5E6038");
