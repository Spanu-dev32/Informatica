/* Beretta Alessio
	Implementare le seguenti funzioni:
	void caricaTab(Studente t[]): Carica la tabella chiedendo dati all'utente o generandoli casualmente.
	void stampaTab(Studente t[]): Stampa la tabella allineando correttamente i dati.
	int ricercCog(Studente t[], char cog[]): Cerca uno studente per cognome, restituendo l'indice (o -1 se non trovato).
	int stampaMedia(Studente t[]): Stampa la media voti per ogni studente e conta quante medie sono = 6.
	int studenti10(Studente t[]): Conta gli studenti con almeno un voto pari a 10.
	void formattaCogn(Studente t[]): Scrivi in maiuscolo la prima lettera del campo cognome e minuscole tutte le altre per tutti i record della tabella
*/

#include "stdio.h"
#include "string.h"
#include "time.h"
#include "stdlib.h"

#define DIM_COGN 20
#define NUM_VOTI 5
#define NUM_STUD 5

// Struttura per la data
typedef struct Data
{
	int giorno;
	int mese;
	int anno;
} Data;

// Struttura per lo studente
typedef struct Studente
{
	char cognome[DIM_COGN];
	Data data_nascita;
	int voti[NUM_VOTI];
} Studente;

void caricaTab(Studente t[]);
void stampaTab(Studente t[]);
int ricercCog(Studente t[], char[]);
int stampaMedia(Studente t[]);
int studenti10(Studente t[]);
void randomVoti(Studente t[]);
void formattaCogn(Studente t[]);

int main()
{
	srand(time(NULL));
	char cog[DIM_COGN], k;
	int media, voto;
	Studente studente[NUM_STUD];
	caricaTab(studente);
	// Formatto il cognome
	formattaCogn(studente);
	stampaTab(studente);
	printf("\n");
	// Ricerca Cognome
	printf("Inserisci il cognome dell'alunno che vuoi cercare:\n");
	scanf("%s", cog);
	k = ricercCog(studente, cog);
	if (k == -1)
	{
		printf("Cognome non trovato!\n");
	}
	else
		printf("Cognome trovato all'indice: %d\n", k);
	printf("\n");
	// Calcolo Media se = 6
	media = stampaMedia(studente);
	printf("\n");
	printf("Gli studenti che hanno una media sopra al 6 sono: %d\n", media);
	// Calcolo studente con almeno un voto 10
	voto = studenti10(studente);
	printf("Gli studenti che hanno un voto pari a 10 sono: %d\n", voto);
}

// Carica la tabella chiedendo dati all'utente o generandoli casualmente.
void caricaTab(Studente t[])
{
	for (int i = 0; i < NUM_STUD; i++)
	{
		printf("Inserisci il cognome dell'alunno:\n");
		scanf("%s", t[i].cognome);
		printf("Inserisci il giorno di nascita:");
		scanf("%d", &t[i].data_nascita.giorno);
		printf("Inserisci il mese di nascita:");
		scanf("%d", &t[i].data_nascita.mese);
		printf("Inserisci l'anno di nascita:");
		scanf("%d", &t[i].data_nascita.anno);
		randomVoti(t);
	}
}

// Stampa la tabella allineando correttamente i dati.
void stampaTab(Studente t[])
{
	printf("%-20s %-10s %+19s\n", "Cognome", "Data N.", "Voti");
	printf("--------------------------------------------\n");
	printf("\n");
	for (int i = 0; i < NUM_STUD; i++)
	{
		printf("%-20s %02d/%02d/%04d\t", t[i].cognome, t[i].data_nascita.giorno, t[i].data_nascita.mese, t[i].data_nascita.anno);
		printf("\t");
		for (int j = 0; j < NUM_VOTI; j++)
		{ // Ciclo for per i voti
			printf("%3d ", t[i].voti[j]);
		}
		printf("\n");
	}
}

// Cerca uno studente per cognome, restituendo l'indice (o -1 se non trovato).
int ricercCog(Studente t[], char cog[])
{
	int risultato;
	for (int i = 0; i < NUM_STUD; i++)
	{
		risultato = strcmp(t[i].cognome, cog);
		if (risultato == 0)
		{
			return i;
		}
	}
	return -1;
}

// Stampa la media voti per ogni studente e conta quante medie sono = 6.
int stampaMedia(Studente t[])
{
	int contatore = 0;
	float media;
	printf("Le medie degli alunni sono:\n");
	for (int i = 0; i < NUM_STUD; i++)
	{
		float somma = 0;
		for (int j = 0; j < NUM_VOTI; j++)
		{
			somma = somma + t[i].voti[j];
		}
		media = somma / NUM_VOTI;
		printf("%s : %.2f\n", t[i].cognome, media);
		if (media >= 6)
		{
			contatore++;
		}
	}
	return contatore;
}
// Conta gli studenti con almeno un voto pari a 10.
int studenti10(Studente t[])
{
	int contatore = 0;
	for (int i = 0; i < NUM_STUD; i++)
	{
		for (int j = 0; j < NUM_VOTI; j++)
		{
			if (t[i].voti[j] == 10)
			{
				contatore++;
				break;
			}
		}
	}
	return contatore;
}
// Genero i voti random che partono da 1 a 10
void randomVoti(Studente t[])
{
	for (int i = 0; i < NUM_STUD; i++)
	{
		for (int j = 0; j < NUM_VOTI; j++)
		{
			t[i].voti[j] = rand() % 10 + 1;
		}
	}
}

// Scrivi in maiuscolo la prima lettera del campo cognome e minuscole tutte le altre per tutti i record della tabella
void formattaCogn(Studente t[])
{
	int k = 0;
	for (int i = 0; i < NUM_STUD; i++)
	{
		if (t[i].cognome[0] >= 'a' && t[i].cognome[0] <= 'z')
		{
			t[i].cognome[0] -= 32;
		}
		k = 0;
		while (t[i].cognome[k] != '\0')
		{
			k++;
			if (t[i].cognome[k] >= 'A' && t[i].cognome[k] <= 'Z')
			{
				t[i].cognome[k] += 32;
			}
		}
	}
}
