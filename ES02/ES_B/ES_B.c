/* Beretta Alessio
Scrivi  un  programma  che  legge  il  file  nomi.txt e  scrive  un  file  NOMI2.TXT,  dove  tutti  i  nomi  sono stati trasformati in caratteri maiuscoli.
*/

#include "stdio.h"
#include "errno.h"

int main()
{
  char nomeFileIN[] = "nomi.txt";
  char c;
  FILE *puntIn = fopen(nomeFileIN, "r");
  FILE *puntOut = fopen("NOMI2.txt", "w");
  if(puntIn == NULL || puntOut == NULL) {
    perror("Il file non si puo aprire: ");
  }
  while (!feof(puntIn))
  {
    c = fgetc(puntIn);
    if(c >= 'a' && c<= 'z') {
        c-=32;
    }
    fputc(c,puntOut);
  }
    fclose(puntIn);
    fclose(puntOut);
}