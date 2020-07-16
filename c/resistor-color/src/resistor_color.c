#include "resistor_color.h"

int color_code(resistor_band_t clr) {
    return clr;
}

resistor_band_t * colors(void) {
    resistor_band_t * ptr = NULL;
    ptr = (resistor_band_t *) malloc(n_colors * sizeof(BLACK));
//    ptr = {BLACK, BROWN, RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET, GREY, WHITE};
    ptr[BLACK] = BLACK;
    ptr[BROWN] = BROWN;
    ptr[RED] = RED;
    ptr[ORANGE] = ORANGE;
    ptr[YELLOW] = YELLOW;
    ptr[BLUE] = BLUE;
    ptr[GREEN] = GREEN;
    ptr[VIOLET] = VIOLET;
    ptr[GREY] = GREY;
    ptr[WHITE] = WHITE;
    return ptr;
}

void release(resistor_band_t * ptr) {
    free(ptr);
}
