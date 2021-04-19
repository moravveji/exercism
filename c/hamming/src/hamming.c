#include "hamming.h"

int compute(const char *lhs, const char *rhs) {
    int count = 0;
    char lc = *lhs, rc=*rhs;
    while ( (lc!='\0') && (rc!='\0') ){
        if (lc != rc) count++;
    lc=*++lhs;
    rc=*++rhs;
    }
    
    count = ( (lc=='\0') && (rc!='\0') ) ? -1 : count;
    count = ( (lc!='\0') && (rc=='\0') ) ? -1 : count;

    return count;
}