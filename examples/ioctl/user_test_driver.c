#include <assert.h>
#include <fcntl.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include "main.h"
#define OPTION_ARG (1)

int main(int argc, char **argv) {
  int ret = 0;
  int fd = 0;
  int chosen_ioctl = 0;
  char *chosen_option = NULL;

  if (argc != 2) {
    return -1;
  }

  chosen_option = argv[OPTION_ARG];

  if (0 == strcmp("1", chosen_option)) {
    chosen_ioctl = IOCTL_OPTION1;
  } else if (0 == strcmp("2", chosen_option)) {
    chosen_ioctl = IOCTL_OPTION2;
  } else {
    return -1;
  }

  fd = open("/dev/myioctl", O_RDWR);
  assert(fd != -1);

  ret = ioctl(fd, chosen_ioctl);
  assert(ret != -1);

  ret = close(fd);
  assert(ret != -1);

  return 0;
}
