#include "word_count.h"

bool is_punctuation(char c) {
  const char * ignore = ":!&@$%^&.";
  for (unsigned int i=0; i<strlen(ignore); i++) {
    if (c == ignore[i]) {
      return true;
    }
  }
  return false;
}

bool is_delimiter(char c) {
  return (bool)((c == ' ') || (c == ',') || (c == '\n'));
}

bool is_digit(char c) {
  return (bool) (c >= '0' && c <= '9');
}

void store_word(word_count_word_t * words, char * word, int * wc, int ic) {
  word[ic] = '\0';
  int iword = 0;
  if (DEBUG) printf("\nstore_word: ");
  for (iword=0; iword<*wc && iword<MAX_WORDS; iword++) {
    if (strcmp(words[iword].text, word) == 0) { // both identical
      words[iword].count++;
      return;
    }
  }
  
  strncpy(words[iword].text, word, ic); // new word
  words[iword].count = 1;
  *wc = *wc + 1;

  if (DEBUG) printf("wc=%d, word=%s", *wc, words[*wc-1].text);

}

int word_count(const char * str, word_count_word_t * words) {
  int wc = 0;     // word-counter, as return value
  int ic = 0;     // index of char c in the word
  char c;
  bool prev_was_delim = false; // to skip multiple delimiters

  char * word = (char *) malloc(MAX_WORD_LENGTH * sizeof(char));
  do {
    c = (*str == '\0') ? '\0' : tolower(*str);
    if (DEBUG) printf("\nnow c=%c ", c);
    if (ic > MAX_WORD_LENGTH) { // stop if too long word
      wc = EXCESSIVE_LENGTH_WORD;
      break;
    }
    if (wc > MAX_WORDS) { // stop if too many words
      wc = EXCESSIVE_NUMBER_OF_WORDS;
      break;
    }
    if (is_punctuation(c)) { // skip
      if (DEBUG) printf("punctuation: c=%c ", c);
      str++;
      prev_was_delim = false;
    } else if (prev_was_delim && is_delimiter(c)) { // skip
      if (DEBUG) printf("multiple delimiters: c=%c ", c);
      str++;
      prev_was_delim = true;
    } else if (c == '\'' && (prev_was_delim || is_delimiter(*(str+1)))) { // ignore: \'
      if (DEBUG) printf("single quotation: c=%c ", c);
      str++;
      prev_was_delim = false;
    } else if ((! prev_was_delim) && is_delimiter(c)) { // store & reset
      if (DEBUG) printf("delimiter: c=%c ", c);
      store_word(words, word, &wc, ic);
      ic = 0;
      str++;
      prev_was_delim = true;
    } else if (c == '\0') { // store
      if (DEBUG) printf("EOL: c=%c (%d)", c, c);
      store_word(words, word, &wc, ic);
      break;
    } else if (is_digit(c)) { // advance
      if (DEBUG) printf("digit: c=%c ", c);
      word[ic++] = c;
      str++;
      prev_was_delim = false;
    } else { // advance
      if (DEBUG) printf("normal: c=%c ", c);
      word[ic++] = c;
      str++;
      prev_was_delim = false;
    }
  } while (wc <= MAX_WORDS);

  free(word);
  if (DEBUG) {
    // printf(", wc=%d, ", wc);
    printf("\n");
    for (int x=0; x<wc; x++) printf("(%d, %s: %d), ", x, words[x].text, words[x].count);
    printf("\n");
  }
  // return wc;
  return (wc > MAX_WORDS) ? EXCESSIVE_NUMBER_OF_WORDS : wc;
}
