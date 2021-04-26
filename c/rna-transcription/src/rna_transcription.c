#include "rna_transcription.h"

char map(char c) {
  char ch;
  if (c == 'G') 
    {ch = 'C';}
  else if (c == 'C')
    {ch = 'G';}
  else if (c == 'T')
    {ch = 'A';}
  else if (c == 'A')
    {ch = 'U';}
  else if (c == '\0')
    {ch = '\0';}
  else {
    printf("Unsupported nucleotide\n");
    ch = '\0';
  }
  return ch;
}

char * to_rna(const char * dna) {
    unsigned short n = strlen(dna);
    char * rna = (char *) malloc(n * sizeof(char));

    strcpy(rna, dna);
    if (*rna == '\0') return rna;

    for (int i=0; i<=n; i++) {
      // rna[i] = map(rna[i]);
      rna[i] = map(rna[i]);
    }

    return rna;
}
