/* Beretta Alessio
Scrivi un programma che conta i caratteri, le parole e le righe presenti in un file di testo (non gli spazi, tabulazioni e a capo)
*/

#include "stdio.h"
#include "errno.h"

int main()
{
  int caratteri=0,parole=1,righe=1; // Dichiarazione di variabili faccio partire parole e righe uguale a 1 perchè in un file ci son per forza una parola e una riga 
  char nomeFileIN[] = "frase.txt"; // Posizione del file 
  char c;
  FILE *puntIn = fopen(nomeFileIN, "r");
  if(puntIn == NULL) {
    perror("Il file non si puo aprire: "); // Se il file non si può aprire
  }
  while ((c = fgetc(puntIn)) != EOF) 
  {
    if(c != ' ' && c != '\t' && c != '\n') { // Se non è uguale a uno spazio, tabulazione o a capo aumento i caratteri
        caratteri++;
    }
    if(c==' ' || c=='\n') { // Se è uguale a uno spazio o andare a capo aumento le paorle 
        parole++;
        }
    if(c =='\n') { // Se è uguale all'andare a capo aumento le righe 
        righe++;
    }
  }
    fclose(puntIn);
    printf("Ci sono: %d caratteri, %d parole, %d frasi\n",caratteri,parole,righe);
}