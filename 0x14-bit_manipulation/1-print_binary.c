#include "main.h"

void print_binary(unsigned long int n)
{
  int count = 0;

  _print_binary_helper(n, 63, &count);
}

void _print_binary_helper(unsigned long int n, int i, int *count)
{
  if (i < 0) {
    if (!*count) {
      _putchar('0');
    }
    return;
  }

  unsigned long int current = n >> i;

  if (current & 1) {
    _putchar('1');
    *count++;
  } else {
    _print_binary_helper(n, i - 1, count);
  }
}
