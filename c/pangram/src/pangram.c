#include "pangram.h"

bool is_pangram(const char * str) {
    if ((str == NULL) || (strlen(str) == 0)) {
        return false;
    }

    char c; // dummy
    unsigned short int ic; // numerical value of c
    unsigned short int counts[NALPH] = { 0 };

    // fill in the "counts" array
    do {
        c = tolower(*str);
        if ((c >= 'a' ) && (c <= 'z')) {
            ic = c - 'a';
            counts[ic]++;
            printf("c=%c, ic=%d, count=%hu\n", c, ic, counts[ic]);
        }
    } while((c = *++str) != '\0');

    // iterate over "counts" and terminate as soon as an element 
    // has zero value
    for (ic=0; ic<NALPH; ic++) {
        if (counts[ic] == 0) return false;
    }

    return true;
}