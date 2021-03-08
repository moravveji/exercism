#ifndef PANGRAM_H
#define PANGRAM_H

  #include <stdio.h>
  #include <stdbool.h>
  #include <string.h>
  #include <ctype.h>

  #define NALPH 'z' - 'a' + 1

  bool is_pangram(const char *sentence);

#endif
