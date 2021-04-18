#ifndef SPACE_AGE_H
#define SPACE_AGE_H

#include <stdint.h>

typedef enum planet {
   MERCURY = 0,
   VENUS,
   EARTH,
   MARS,
   JUPITER,
   SATURN,
   URANUS,
   NEPTUNE,
} planet_t;

// orbital period in Earth year(s)
static const float p_yr[8] = {
   0.2408467,    // mercury
   0.61519726,   // venus
   1.0,          // earth
   1.8808158,    // mars
   11.862615,    // jupyter
   29.447498,    // saturn
   84.016846,    // uranus
   164.79132     // neptune
};

float age(planet_t planet, int64_t seconds);

#endif
