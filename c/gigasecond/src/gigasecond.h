#ifndef GIGASECOND_H
#define GIGASECOND_H

    #include <time.h>

    size_t is_leap(int);
    time_t days_past_1ad(int);
    time_t epoch2sec(int, int, int, int, int, int);
    time_t gigasecond_after(time_t);

#endif
