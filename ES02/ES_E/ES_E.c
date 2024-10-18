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
    FILE *puntDecrypt = fopen("decrypt.txt", "w");

    // Condizione se il file non si riesce ad aprire
    if (puntIn == NULL)
    {
        perror("Il file non si puo aprire: ");
    }
    // cesareCrypt(puntIn,puntOut,chiave);
     cesareDecrypt(puntIn,puntDecrypt,chiave);
}



void cesareCrypt(FILE *puntIn,FILE *puntOut,int chiave) {
    char c, cript=0;
     while (!feof(puntIn))
    {
        c = fgetc(puntIn); // Ottengo il primo carattere
        if (c != ' ')
        {
            if (c >= 'A' && c <= 'Z')
            {
                cript = c + chiave;
                if (cript > 'Z')
                {
                    cript = cript - 'Z' + 'A' - 1;
                }
                fputc(cript, puntOut);
            }
            if (c >= 'a' && c <= 'z')
            {

                cript = c + chiave;
                if (cript > 'z')
                {
                    cript = cript - 'z' + 'a' - 1;
                }
                fputc(cript, puntOut);
            }
        }
        else
            fputc(' ', puntOut);
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
                if (decript < 'A')
                {
                    decript = 'Z' - ('A' - decript - 1);
                }
                fputc(decript, puntDecrypt);
            }
            if (c >= 'a' && c <= 'z')
            {

                decript = c - chiave;
                if (decript < 'a')
                {
                   decript = 'z' - ('a' - decript - 1);
                }
                fputc(decript, puntDecrypt);
            }
        }
        else
            fputc(' ', puntDecrypt);
    }
}