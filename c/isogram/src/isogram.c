#include "isogram.h"

bool is_empty(char * ptr) {
  /**
  * brief Check whether the string is empty
  *
  * @param ptr: char *
  * @return bool
  */
  if ((ptr != NULL) && (ptr[0] == '\0')) {
    return true;
  }
  else {
    return false;
  }
}

bool is_null(char * ptr) {
  /**
  * brief Check whether the string pointer is NULL
  *
  * @param ptr: char *
  * @return bool
  */
  return (bool)(ptr == NULL);
}

bool is_space(char c) {
  /**
  * brief Check whether the character is space: ' '
  *
  * @param c: char
  * @return bool
  */
  return (bool)(c == ' ');
}

bool is_dash(char c) {
  /**
  * brief Check whether the character is dash: '-'
  *
  * @param c: char
  * @return bool
  */
  return (bool)(c == '-');
}

void reset(unsigned char counters[], unsigned int n) {
  /**
  * brief Reset all elements of the integer counter array to zero
  *
  * @param ptr: unsigned char *: the counter array
  * @param n: unsigned int: length of the counter array
  * @return void
  */
  for (unsigned int i=0; i<n; i++) {
    counters[i] = 0;
  }
}

bool is_isogram(char * txt) {
  unsigned char counters[NUM_CHARS];

  // empty inputs
  if (is_empty(txt)) { return true; }
  if (is_null(txt))  { return false; }

  reset(counters, NUM_CHARS);

  char c;
  int ind;
  while ((c = tolower(*txt)) != '\0') {
    if ((is_space(c)) || is_dash(c)) {
      txt++;
      continue;
    }

    ind = c - 'a';
    if (counters[ind] == 1) {
      return false;
    } else {
      counters[ind]++;
    }
    txt++;
  }

  return true;
}