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

time_t days_past_1ad(int year) {
    year--; /* subtract one year to handle the missing 0AD year */
    return (365 * year) + (year / 400) - (year / 100) + (year / 4);
}

time_t epoch2sec(int year, int month, int day, int hour, int min, int sec) {
    const time_t d2sec = 86400; // 60 * 60 * 24
    const time_t lookup[2][12] = {
        {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334},
        {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335}
    };
    time_t elapsed_d = (days_past_1ad(year) - days_past_1ad(1970)) + lookup[is_leap(year)][month-1] + (day-1);
    time_t _sec = elapsed_d * d2sec + (hour * 3600 + min * 60 + sec);
    return _sec;
}

time_t gigasecond_after(time_t t) {
    const time_t gigasec = 1000000000;
    return t + gigasec;
}
