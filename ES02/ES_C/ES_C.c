/* Beretta Alessio
Scrivi un programma che conta i caratteri, le parole e le righe presenti in un file di testo (non gli spazi, tabulazioni e a capo)
*/

#include "stdio.h"
#include "errno.h"

int main()
{
    int caratteri=0,parole=1,righe=0;
  char nomeFileIN[] = "frase.txt";
  char c;
  FILE *puntIn = fopen(nomeFileIN, "r");
  if(puntIn == NULL) {
    perror("Il file non si puo aprire: ");
  }
  while (!feof(puntIn))
  {
    c = fgetc(puntIn);
    if(c!=' ') {
        caratteri++;
    }
    if(c==' ' || c==9) {
        parole++;
    }
    if(c =='\n') {
        righe++;
    }
  }
    fclose(puntIn);
    printf("Ci sono: %d caratteri, %d parole, %d frasi",caratteri,parole,righe);
}