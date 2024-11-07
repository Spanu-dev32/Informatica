/* Beretta Alessio
Scrivere e collaudare (una funzione alla volta) il programma in C che nel main richiama le seguenti funzioni:
funzione per scrivere un file di N record con N costante posta a 10;
funzione per leggere e stampare su monitor le informazioni del file di record (si usi il controllo di fine file e non il ciclo for con N perché la funzione sia valida quale che sia il numero di record del file (quindi anche diverso da N)).
conta quante volte è presente uno studente che ha il cognome uguale alla stringa passata in output; la funzione restituisce un intero
per ogni studente visualizza il suo cognome, la media dei suoi voti, il suo voto più alto e il suo voto più basso.
*/

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define N 3
#define LENGTH 50
#define V 5

typedef struct {
    char cognome[LENGTH];
    char nome[LENGTH];
    int voti[V];
    float media;
} Persona;

void scriviFile(FILE *puntOut); // Funzione per scrivere il file
void stampaFile(FILE *puntIn); // Funzione per stampare il file
int cercaCognome(FILE *puntIn, const char *cognome); // Funzione per cercare il cognome 
void stampaVoti(Persona p); // Funzione per stampare il voto minimo, max 
void stampaMedia(Persona p); // Funzione per stampare la media 
void correggiRecord(FILE *); // Corregge il record se il voto della persona è inferiore al 4, mettendolo a 4 

int main() {
    srand(time(NULL));
    char cognomeRicerca[LENGTH];
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
    stampaFile(puntIn);
    
    // Ricerca cognome
    printf("Che cognome vuoi cercare?\n");
    scanf("%s", cognomeRicerca);
    
    int ricerca = cercaCognome(puntIn, cognomeRicerca);
    printf("Lo studente %s appare %d nel file.\n", cognomeRicerca, ricerca);
    // Correggi Record
    correggiRecord(puntIn);
    stampaFile(puntIn);
    
    fclose(puntIn);
}

void scriviFile(FILE *puntOut) {
    Persona p;

    for (int i = 0; i < N; i++) {
        printf("Inserisci il cognome per la persona %d: ", i + 1);
        scanf("%s", p.cognome);
        printf("Inserisci il nome per la persona %d: ", i + 1);
        scanf("%s", p.nome);

        // Genera voti casuali
        for (int j = 0; j < V; j++) {
            p.voti[j] = rand() % 10 + 1; // Voti da 1 a 10
        }
        size_t scritto = fwrite(&p, sizeof(Persona), 1, puntOut);
        
        if (scritto != 1) {
            perror("Errore nella scrittura del file\n");
        }
    }
    
    printf("File scritto correttamente!\n");
}

void stampaFile(FILE *puntIn) {
    Persona p;

    printf("%-20s %-20s %-25s %-6s\n", "Cognome", "Nome", "Voti", "Media");
    printf("--------------------------------------------\n");

    while (fread(&p, sizeof(Persona), 1, puntIn) > 0) {
        printf("%-20s %-20s ", p.cognome, p.nome);
        
        for (int j = 0; j < V; j++) {
            printf("%-4d", p.voti[j]);
        }
        
        stampaVoti(p); // Stampa massimo e minimo voti
        stampaMedia(p); // Stampa media voti
        printf("\n");
    }
}

void stampaMedia(Persona p) {
    int somma = 0;
    
    for (int i = 0; i < V; i++) {
        somma += p.voti[i];
    }
    
    p.media = (float)somma / V; // 
    
    printf("La media è uguale a %.2f\n", p.media); // Stampa la media
}

int cercaCognome(FILE *puntIn, const char *cognome) {
    Persona p;
    int conta = 0;

    fseek(puntIn, 0, SEEK_SET); // Riporta il puntatore all'inizio del file
    
    while (fread(&p, sizeof(Persona), 1, puntIn) > 0) {
        if (strcmp(p.cognome, cognome) == 0) {
            conta++;
        }
    }

    return conta;
}

void stampaVoti(Persona p) {
    int votoMax = p.voti[0];
    int votoMin = p.voti[0];
    // Calcolo del voto massimo, minimo e la somma per la media
    for (int j = 1; j < V; j++) {
        if (p.voti[j] > votoMax) {
            votoMax = p.voti[j];
        }
        if (p.voti[j] < votoMin) {
            votoMin = p.voti[j];
        }
    }
    // Stampa dei risultati
    printf("Voto più alto: %d\n", votoMax);
    printf("Voto più basso: %d\n", votoMin);
}

// Correggi i record con voti inferiori a 4
void correggiRecord(FILE *puntIn)
{
    FILE *puntOut = fopen("prova1.dat", "r+b");
    if (puntOut == NULL)
    {
        perror("Impossibile aprire il file per la modifica");
        return;
    }

    Persona p;
    while (fread(&p, sizeof(Persona), 1, puntIn) > 0)
    {
        for (int i = 0; i < V; i++)
        {
            if (p.voti[i] < 4)
            {
                p.voti[i] = 4; // Correggi il voto
            }
        }
        fseek(puntOut, -sizeof(Persona), SEEK_CUR);
        fwrite(&p, sizeof(Persona), 1, puntOut);
    }
    fclose(puntOut);
}
