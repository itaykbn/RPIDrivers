# Set the output directory for object files
obj_output_dir := ${PWD}/bin

# List of source files
src_files := $(wildcard src/*.c)

# Generate object file names
obj_files := $(patsubst src/%.c,$(obj_output_dir)/%.o,$(src_files))

# Specify the target object file
obj-m := $(obj_output_dir)/*

all: $(obj_files)
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

# Rule to compile each .c file into .o file in bin directory
$(obj_output_dir)/%.o: src/%.c
	$(MAKE) -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
	$(CC) $(CFLAGS) -c -o $@ $<

# Ensure that 'bin' directory exists
$(shell mkdir -p $(obj_output_dir))

.PHONY: all clean
