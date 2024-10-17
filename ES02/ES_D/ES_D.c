/* Beretta Alessio
Scrivi un programma che legge il file numeri.txt (cifre numeriche ascii)
composto da una sequenza di numeri di una cifra separati da uno spazio bianco e successivamente scrive 2 file, pari.txt e dispari.txt,
nei quali dovrai inserire i numeri che hai letto a seconda del loro valore pari o dispari
*/

#include "stdio.h"
#include "errno.h"

int main()
{
    char nomeFileIN[] = "numeri.txt";
    int c;
    FILE *puntIn = fopen(nomeFileIN, "r");
    FILE *puntPari = fopen("pari.txt", "w");
    FILE *puntDispari = fopen("dispari.txt", "w");
    if (puntIn == NULL)
    {
        perror("Il file non si puo aprire: ");
    }
    while (!feof(puntIn))
    {
        c = fgetc(puntIn);
        if (c != ' ' && c >= '0' && c <= '9')
        {
            int numero;
            numero = c - '0';
            if (numero % 2 == 0)
            {
                fprintf(puntPari, "%d ", numero);
            }
            else
                fprintf(puntDispari, "%d ", numero);
        }
    }
    fclose(puntIn);
    fclose(puntPari);
    fclose(puntDispari);
}