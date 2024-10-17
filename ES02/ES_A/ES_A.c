/* Beretta Alessio
    Scrivi  un  programma  che  esegue  la  copia  di  un  file  di  testo.
  Il  programma  legge  carattere per carattere il contenuto del file in.txt e lo ricopia nel file out.txt.
*/

#include "stdio.h"
#include "errno.h"

int main()
{
  char nomeFileIN[] = "in.txt";
  char c;
  FILE *puntIn = fopen(nomeFileIN, "r");
  FILE *puntOut = fopen("out.txt", "w");
  if(puntIn == NULL || puntOut == NULL) {
    perror("Il file non si puo aprire: ");
  }
  while (!feof(puntIn))
  {
    c = fgetc(puntIn);
    fputc(c, puntOut);
  }
  fclose(puntIn);
  fclose(puntOut);

}