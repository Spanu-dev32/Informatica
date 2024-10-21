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
    // Dichiarazione di file 
    FILE *puntIn = fopen(nomeFileIN, "r");
    FILE *puntPari = fopen("pari.txt", "w");
    FILE *puntDispari = fopen("dispari.txt", "w");
    if (puntIn == NULL)
    {
        perror("Il file non si puo aprire: "); // Stampo l'errore se non riesco ad aprire un file 
    }
    while (!feof(puntIn))
    {
        c = fgetc(puntIn);
        if (c != ' ' && c >= '0' && c <= '9') // Verifico che il carattere c non sia uno spazio e che dev'essere compreso tra 0 e 9
        {
            int numero;
            numero = c - '0'; // Converto il numero da ascii a valore numerico
            if (numero % 2 == 0)
            {
                fprintf(puntPari, "%d ", numero); // Se pari
            }
            else
                fprintf(puntDispari, "%d ", numero); // Se dispari
        }
    }
    // Chiudo i file 
    fclose(puntIn);
    fclose(puntPari);
    fclose(puntDispari);
}