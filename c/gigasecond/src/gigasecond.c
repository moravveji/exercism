#include "gigasecond.h"

size_t is_leap(int year) {
    if ((year % 400 == 0)) {
        return 1;
    } else if (year % 100 == 0) {
        return 0;
    } else if (year % 4 == 0) {
        return 1;
    } else {
        return 0;
    }
}

time_t gigasecond_after(time_t t) {
    return t;
}
