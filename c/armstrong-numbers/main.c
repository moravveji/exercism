#include "src/armstrong_numbers.h"
#include <stdio.h>

int is_armstrong_number(int);
int main() {
  int const target = 153;
  int sum = is_armstrong_number(target);
  printf("target was %d, and sum is %d\n", target, sum);
  return 0;
}
