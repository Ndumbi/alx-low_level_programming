#include "main.h"

unsigned int binary_to_uint(const char *b)
{
  unsigned int dec_val = 0;

  if (!b)
    return 0;

  while (*b) {
    dec_val = _binary_to_uint_helper(dec_val, *b);
    b++;
  }

  return dec_val;
}

unsigned int _binary_to_uint_helper(unsigned int dec_val, char c) {
  return 2 * dec_val + (c - '0');
}
