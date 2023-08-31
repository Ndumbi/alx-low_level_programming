#include "main.h"

int get_bit(unsigned long int n, unsigned int index)
{
  return _get_bit_helper(n, index);
}

int _get_bit_helper(unsigned long int n, unsigned int index) {
  return (n >> index) & 1;
}
