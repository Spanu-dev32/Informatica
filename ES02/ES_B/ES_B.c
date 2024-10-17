/* Beretta Alessio
Scrivi  un  programma  che  legge  il  file  nomi.txt e  scrive  un  file  NOMI2.TXT,  dove  tutti  i  nomi  sono stati trasformati in caratteri maiuscoli.
*/

#include "stdio.h"
#include "errno.h"

int main()
{
  char nomeFileIN[] = "nomi.txt";
  char c;
  
  // Dichiarazione di file input e output
  FILE *puntIn = fopen(nomeFileIN, "r");
  FILE *puntOut = fopen("NOMI2.txt", "w");

  // Condizione se uno dei due puntatori non si possono aprire
  if(puntIn == NULL || puntOut == NULL) {
    perror("Il file non si puo aprire: ");
  }
  while (!feof(puntIn))
  {
    c = fgetc(puntIn);

    // Controllo se il carattere è in minuscolo se vero lo trasformo in maiuscolo
    if(c >= 'a' && c<= 'z') {
        c-=32;
    }
    fputc(c,puntOut); // Inserisco il carattere poi nel file di output
  }

  // Chiudo i file di input e output
    fclose(puntIn);
    fclose(puntOut);
}