#include "resistor_color_duo.h"

uint16_t color_code(resistor_band_t * arr) {
  uint16_t val = arr[0] * 10 + arr[1];
  return val;
}
