#include "space_age.h"

static float yr2sec = 365.25 * 24 * 3600;

float age(planet_t planet, int64_t seconds) {
    return seconds / (p_yr[planet] * yr2sec);
}
