#ifndef DARTS_H
#define DARTS_H
  #include <stdlib.h>
  #include <math.h>

  typedef struct {
    float x;
    float y;
  } coordinate_t;

  int score(coordinate_t);
  float radius(float, float);

#endif
