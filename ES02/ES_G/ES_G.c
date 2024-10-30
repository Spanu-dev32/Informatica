/* Beretta Alessio 4H 30/10/2024
Scrivi  un  programma  che  esegue  la  copia  di  un  file  di  testo.
Il  programma  legge  carattere per carattere il contenuto del file “file_src” e lo ricopia nel file “file_dst”. “file_src” e “file_dst” vanno passati al main come parametri. 
Gestire eventuali errori o utilizzi non corretti del programma
*/



#include "stdio.h"
#include "stdlib.h"
#include "errno.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Utilizzo: %s [input_file] [output_file]\n", argv[0]); // Stampo l'utilizzo corretto del programma 
        return 1;
 	   }
//  Dichiarazione dei file
 	  FILE *input_file =fopen(argv[1], "r"); 
  	  FILE *output_file =fopen(argv[2], "w");

//  Condizione se i file non si possono aprire
    if(input_file  == NULL || output_file == NULL)   {
        perror("Il file non si puo aprire:!");
        return 1;
    }

    char c;
    // Scorro il file finche non arrivo alla fine 
    while ((c=fgetc(input_file)) != EOF) {
        fputc(c,output_file);
    }

// Chiusura dei file
    fclose(input_file);
    fclose(output_file);
}