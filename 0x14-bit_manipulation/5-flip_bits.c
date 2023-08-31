#include "main.h"

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
  unsigned long int exclusive = _xor_helper(n, m);
  int count = 0;

  for (int i = 63; i >= 0; i--) {
    if (exclusive & (1UL << i)) {
      count++;
    }
  }

  return count;
}

unsigned long int _xor_helper(unsigned long int n, unsigned long int m) {
  return n ^ m;
}
