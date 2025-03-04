#include <stdint.h>

int32_t count_digits(int32_t n) {
  int32_t len = 1;

  while (n >= 10) {
    n = n / 10;
    len++;
  }

  return len;
}
