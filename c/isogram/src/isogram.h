#ifndef ISOGRAM_H
#define ISOGRAM_H

  #include <stdio.h>
  #include <stdlib.h>
  #include <stdbool.h>
  #include <string.h>
  #include <ctype.h>

  #define NUM_CHARS 'z' - 'a' + 1

  bool is_isogram(char * phrase);
  bool is_empty(char * ptr);
  bool is_null(char * ptr);
  bool is_space(char c);
  bool is_dash(char c);
  void reset(unsigned char counters[], unsigned int n);

#endif
