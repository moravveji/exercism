#include "acronym.h"

char * abbreviate(const char * str) {
  /**
  * brief Abbreviate the passed string
  *
  * @param str (char *): input string to be abbreviated.
           Every word proceeding a space character will be
           abbreviated.
    @return abbr (char *): a string containing the abbreviation.
  */
  if (str == NULL || *str == '\0') return NULL;

  char * abbr;
  unsigned int ind = 0;
  abbr = (char *)malloc(MAX_CHAR_LEN * sizeof(char));

  /* first abbreviation is added manually */
  abbr[ind++] = toupper(*str);
  /* the next abbreviations happen in a loop */
  char c = '\0';
  do {
    if (*(++str) != ' ' && (*str != '-')) {
      continue;
    } else {
      abbr[ind++] = toupper(*(++str));
    }
  } while ((c = *str) != '\0');

  return abbr;
}