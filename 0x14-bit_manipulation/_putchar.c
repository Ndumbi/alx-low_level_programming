#include "main.h"
#include <unistd.h>

static int write_char(int fd, char c) {
  return write(fd, &c, 1);
}

int _putchar(char c)
{
  return write_char(1, c);
}
