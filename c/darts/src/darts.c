#include "darts.h"

int score(coordinate_t coord) {
  float x, y;
  int const outside = 0, outer = 1, middle = 5, inner = 10;
  float const r_out = 10., r_mid = 5.0, r_in = 1.0;

  x = coord.x;
  y = coord.y;
  float radii = radius(x, y);
  
  if (radii <= r_in) {
     return inner;
  } else if (radii <= r_mid) {
     return middle;
  } else if (radii <= r_out) {
     return outer;
  } else {
     return outside;
  }

}

float radius(float x, float y) {
  return sqrt(x*x + y*y);
}
