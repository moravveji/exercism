#include "armstrong_numbers.h"
#include <stdio.h>

int int_power(int, int);

int int_power(int base, int exponent) {
  int result = 1;
  while (exponent > 0) {
    result *= base;
    exponent--;
  }
  return result;
}

int is_armstrong_number(int n) {
  int power = 0, remain = n;

  // First, find the power
  do {
    remain /= 10;
    power++;
  } while (remain > 0);
//  printf("power=%d\n", power);
  
  // now, rip the number apart, and sum each part to the power
  int sum = 0, k;
  for (k = 0; k < power; k++) {
    // printf("k=%d, n=%d, sum=%d \n", k, n, sum);
    sum += int_power(n%10 , power);
    n /= 10;
  }
  //printf("power = %d\n", power);
  return sum;
}
