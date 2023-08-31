#include "main.h"

static char get_endianness_helper(unsigned int i) {
  return *(char *) &i;
}

int get_endianness(void)
{
  unsigned int i = 1;

  return get_endianness_helper(i);
}
