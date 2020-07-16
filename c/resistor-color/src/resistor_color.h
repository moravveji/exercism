#ifndef RESISTOR_COLOR_H
#define RESISTOR_COLOR_H
  #include <stdio.h>
  #include <stdlib.h>
  #include <stdint.h>

  typedef enum {
    BLACK, 
    BROWN,
    RED,
    ORANGE,
    YELLOW,
    BLUE,
    GREEN,
    VIOLET,
    GREY,
    WHITE
  } resistor_band_t;

static const uint8_t n_colors = 10;

resistor_band_t * colors(void);
int color_code(resistor_band_t);
void release(resistor_band_t *);

#endif
