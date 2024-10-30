/* Beretta Alessio 4H 30/10/2024
Scrivere un programma in C che consente di cifrare o decifrare un file utilizzando l'algoritmo di Cesare.
 Il programma accetta parametri da riga di comando per specificare il file di input, il file di output, la chiave e l'azione (cifrare o decifrare).
 */

#include "stdio.h"
#include "stdlib.h"
#include "errno.h"

void cesareCrypt(FILE *, FILE *, int);
void cesareDecrypt(FILE *, FILE*, int);

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Utilizzo: %s [input_file] [output_file] [chiave] [azione (c/d)]\n", argv[0]); // Utilizzo corretto del programma in caso di errore 
        return 1;
 	   }

    // Dichiarazione delle variabili usando gli argomenti
 	  char *input_file = argv[1];
  	  char *output_file = argv[2];
  	  int chiave = atoi(argv[3]);
   	  char azione = argv[4][0];

    // Dichiarazione di file 
      FILE *puntIn =fopen(argv[1], "r");
      FILE *puntOut =fopen(argv[2], "w");

    // Controllo se ci son problemi con l'apertura del file
     if (puntIn == NULL || puntOut == NULL)
    {
        perror("Il file non si puo aprire: ");
        return 1;
    }
    // Controllo del carattere per cifrare
      if(azione == 'c' || azione == 'C') {
        cesareCrypt(puntIn,puntOut,chiave); // Se la condizione è vera, cifro
      }

      // Controllo del carattere per decifrare 
      else if(azione == 'd' || azione == 'D') {
        cesareDecrypt(puntIn,puntOut,chiave); // Se la condizione è vera, decripto
      }
      else
      printf("Usa 'c' o 'd' per cifrare o decifrare!\n"); // Se l'utente non mette il giusto carattere
}



void cesareCrypt(FILE *puntIn,FILE *puntOut,int chiave) {
    char c, cript=0;
     while (!feof(puntIn))
    {
        c = fgetc(puntIn); // Ottengo il primo carattere
        if (c != ' ')   // Controllo che non sia uno spazio 
        {
            if (c >= 'A' && c <= 'Z') // Compreso tra la A e Z maiuscola 
            {
                cript = c + chiave;
                if (cript > 'Z')
                {
                    cript = cript - 'Z' + 'A' - 1;  // Per riportare la lettera nell'alfabeto se supera il valore di 'Z'
                }
                fputc(cript, puntOut);
            }
            if (c >= 'a' && c <= 'z')
            {

                cript = c + chiave;
                if (cript > 'z')
                {
                    cript = cript - 'z' + 'a' - 1; // Per riportare la lettera nell'alfabeto se supera il valore di 'z'
                }
                fputc(cript, puntOut);
            }
        }
        else
            fputc(' ', puntOut); // In caso fosse uno spazio lo inserisco
    }
}

void cesareDecrypt(FILE *puntIn,FILE *puntDecrypt,int chiave ) {
      char c, decript=0;
     while (!feof(puntIn))
    {
        c = fgetc(puntIn); // Ottengo il primo carattere
        if (c != ' ')
        {
            if (c >= 'A' && c <= 'Z')
            {
                decript = c - chiave;
                if (decript < 'A') // Controllo se il valore è minore di 'A'
                {
                    decript = 'Z' - ('A' - decript - 1); // Lo riporto nell'alfabeto
                }
                fputc(decript, puntDecrypt);
            }
            if (c >= 'a' && c <= 'z')
            {

                decript = c - chiave;
                if (decript < 'a') // Controllo se il valore è minore di 'a'
                {
                   decript = 'z' - ('a' - decript - 1); // Riporto il valore nell'alfabeto
                }
                fputc(decript, puntDecrypt);
            }
        }
        else
            fputc(' ', puntDecrypt);
    }
}