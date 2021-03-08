#include "resistor_color_trio.h"

uint64_t power(uint8_t n) {
  if (n == 0) {
    return 1;
  } else {
    return 10 * power(n-1);
  }
}

resistor_value_t color_code(resistor_band_t arr[]) {
  resistor_value_t item;
  uint64_t pow = power(arr[2]);
  uint16_t flag = 1;
  unsigned long long int resistance = (arr[0] * 10 + arr[1]) * pow;
  flag = resistance % 1000 == 0;
  item.value = flag ? (uint16_t)(resistance/1000) : (uint16_t)(resistance);
  item.unit  = flag ? KILOOHMS : OHMS;
  return item;
}