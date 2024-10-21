/* Beretta Alessio
Scrivere le funzioni cesareCrypt e cesareDecrypt che criptano o decriptano un file in input di una chiave key, usando l’algoritmo di Cesare.
*/

#include "stdio.h"
#include "errno.h"


void cesareCrypt(FILE *, FILE *, int);
void cesareDecrypt(FILE *, FILE*, int);
int main()
{
    char nomeFileIN[] = "key.txt";
    char c, cript;
    int chiave = 3;
    FILE *puntIn = fopen(nomeFileIN, "r"); // Dichiarazione del file di input
    FILE *puntOut = fopen("out.txt", "w"); // Dichiarazione del file di output
    FILE *puntCript = fopen("cript.txt", "r"); // Dichiarazione del file in cui ci sarà la frase da decriptare

    // Condizione se il file non si riesce ad aprire
    if (puntIn == NULL || puntOut == NULL ||puntCript == NULL)
    {
        perror("Il file non si puo aprire: ");
    }
    // Stampo la frase criptata
    fprintf(puntOut,"La frase criptata e':\n");
    cesareCrypt(puntIn,puntOut,chiave); // Funzione per criptare la frase
    fprintf(puntOut,"\n");
    // Stampo la frase decriptata
    fprintf(puntOut,"La frase decriptata e':\n");
    cesareDecrypt(puntCript,puntOut,chiave); // Funzione per decriptare la frase
    
    // Chiusura dei file 
    fclose(puntIn);
    fclose(puntOut);
    fclose(puntCript);
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