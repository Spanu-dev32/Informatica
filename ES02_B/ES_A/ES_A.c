/* Beretta Alessio
Scrivere e collaudare (una funzione alla volta) il programma in C che nel main richiama le seguenti funzioni: 
funzione per scrivere un file di N record con N costante posta a 10;
funzione per leggere e stampare su monitor le informazioni del file di record (si usi il controllo di fine file e non il ciclo for con N perché la funzione sia valida quale che sia il numero di record del file (quindi anche diverso da N)).
conta quante volte è presente uno studente che ha il cognome uguale alla stringa passata in output; la funzione restituisce un intero
per ogni studente visualizza il suo cognome, la media dei suoi voti, il suo voto più alto e il suo voto più basso. 
*/





#include "stdio.h"
#include "string.h"
#include "time.h"
#include "stdlib.h"
#include "errno.h"

#define N 3
#define length 50
#define V 5

typedef struct {
    char cognome[length];
    char nome[length];
    int voti[V];
} Persona;

void scriviFile(FILE *);  // Funzione per scrivere il file
void leggiFile(FILE *); // Funzione per leggere il file
int stampaMedia(int []); // Funzione per stampare la media dei voti
void randomVoti(Persona []); // Random per i voti 
int cercaCognome(FILE *, const char *); // CercaCognome

int main() {
    srand(time(NULL));
    Persona Persone[N];
     char cognomeRicerca[length];
    FILE *puntIn = fopen("prova1.dat", "wb");
    if (puntIn == NULL) {
        perror("Il file non si apre!\n");
        return 1;
    }

    // Scrittura dei record nel file
    scriviFile(puntIn);
    fclose(puntIn);

    // Riapro il file per la lettura
    puntIn = fopen("prova1.dat", "rb");
    if (puntIn == NULL) {
        perror("Impossibile riaprire il file!\n");
        return 1;
    }

    // Leggi e stampa le informazioni dal file
    leggiFile(puntIn);

    /// Ricerca cognome
    printf("Che cognome vuoi cercare?\n");
    scanf("%s",cognomeRicerca);
    int ricerca = cercaCognome(puntIn, cognomeRicerca);
    printf("Lo studente %s appare %d nel file.\n", cognomeRicerca, ricerca);

    fclose(puntIn);
}

// Genera i voti casuali da 1 a 10
void randomVoti(Persona p[]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < V; j++) {
            p[i].voti[j] = rand() % 10 + 1;
        }
    }
}

// Scrive N record nel file
void scriviFile(FILE *puntOut) {
    Persona p[N];

    // Verifica se il file è stato aperto correttamente in modalità binaria
    if (puntOut == NULL) {
        perror("Errore nell'aprire il file");
        return;
    }

    for(int i=0; i<N; i++) {
        // Avvaloro record 
        printf("Inserisci il cognome per la persona: ");
        scanf("%s", p[i].cognome);
        printf("Inserisci il nome per la persona: ");
        scanf("%s", p[i].nome);

        randomVoti(&p);
}
        // Scrivi il record nel file
        size_t scritto = fwrite(&p, sizeof(Persona), 1, puntOut);
        if (scritto != 1) {
            perror("Errore nella scrittura del file");
            break;  // Esci se ci sono errori di scrittura
        }

      

    printf("File binario scritto con successo!\n");
}

// Legge e stampa i record dal file
void leggiFile(FILE *puntIn) {
    Persona p;
    int n;
    float media;
     printf("%-20s %-20s %-25s %-6s\n", "Cognome", "Nome", "Voti", "Media");
	printf("--------------------------------------------\n");
    while ((n = fread(&p, sizeof(Persona), 1, puntIn)) > 0) {
       media = stampaMedia(p.voti);

        printf("%-20s  %-20s",p.cognome, p.nome);
        for (int j = 0; j < V; j++) {
            printf("%-4d", p.voti[j]);
        }
        printf("%6.2f\n", media);
    }
}

// Calcola la media dei voti
int stampaMedia(int voti[]) {
    int somma = 0;
    for (int j = 0; j < V; j++) {
        somma += voti[j];
    }
    return somma / V;
}

// Conta quante volte un cognome appare nel file
int cercaCognome(FILE *puntIn, const char *cognome) {
    Persona p;
    int conta = 0;

    fseek(puntIn, 0, SEEK_SET);       // Riporto il puntatore all'inizio del file perchè mi trovo alla fine del file 
    while (fread(&p, sizeof(Persona), 1, puntIn) > 0) {
        if (strcmp(p.cognome, cognome) == 0) {
            conta++;
        }
    }

    return conta;
}