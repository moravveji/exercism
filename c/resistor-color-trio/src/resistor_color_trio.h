#ifndef RESISTOR_COLOR_TRIO_H
#define RESISTOR_COLOR_TRIO_H
  #include <stdio.h>
  #include <stdlib.h>
  #include <stdint.h>

  typedef enum {
    BLACK, 
    BROWN,
    RED,
    ORANGE,
    YELLOW,
    GREEN,
    BLUE,
    VIOLET,
    GREY,
    WHITE,
    N_COLORS,
  } resistor_band_t;

  static unsigned char OHMS = 1;
  static unsigned char KILOOHMS = 3;

  typedef struct {
    uint16_t value;
    int unit;
  } resistor_value_t;

  uint64_t power(uint8_t);
  resistor_value_t color_code(resistor_band_t []);

#endif
