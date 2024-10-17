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
  FILE *puntIn = fopen(nomeFileIN, "r");  // Dichiarazione del file di input
  FILE *puntOut = fopen("out.txt", "w"); // Dichiarazione del file di output
  
  // Condizione se il file non si riesce ad aprire
  if(puntIn == NULL || puntOut == NULL) {
    perror("Il file non si puo aprire: ");
  }
  while (!feof(puntIn))
  {
    c = fgetc(puntIn);  // Ottengo il primo carattere 
    fputc(c, puntOut); // Lo inserisco nel file di output
  }

  // Chiudo i file di input e output
  fclose(puntIn); 
  fclose(puntOut);

}