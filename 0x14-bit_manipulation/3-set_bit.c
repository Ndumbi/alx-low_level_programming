#include "main.h"

int set_bit(unsigned long int *n, unsigned int index)
{
  return _set_bit_helper(n, index);
}

int _set_bit_helper(unsigned long int *n, unsigned int index) {
  if (index > 63) {
    return -1;
  }

  *n |= (1UL << index);
  return 1;
}
