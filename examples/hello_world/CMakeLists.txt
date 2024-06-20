cmake_minimum_required(VERSION 3.10)
project(hello_project)

# Set the path to the kernel source directory
set(KERNEL_SOURCE_DIR "/lib/modules/${CMAKE_SYSTEM_VERSION}/build")

set(MODULE_NAME helloer)
file(GLOB MODULE_SOURCES "src/*.c")

# Specify the kernel module target
add_custom_target(${MODULE_NAME}.ko ALL
    COMMAND make -C ${KERNEL_SOURCE_DIR} M=${CMAKE_CURRENT_SOURCE_DIR} modules
    COMMENT "Building ${MODULE_NAME}.ko"
    VERBATIM
)
