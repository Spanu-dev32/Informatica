/* Beretta Alessio
	Scrivere un programma C che definisca la struttura “persona” composta da nome, cognome, indirizzo, provincia e data di nascita.
	 Si richieda all’utente di inserire tutti i dati e si stampino a video. 
*/

#include "stdio.h"

#define N 128

struct Indirizzo {
	char citta[N];
	char via[N];
	int civico;
	
};

struct Data {
	int giorno;
	int mese;
	int anno;
};

struct Persona {
	char nome[N];
	char cognome[N];
	struct Indirizzo Indirizzo1;
	struct Data Data1;
};

void chiediInformazioni(Persona*, Data*, Indirizzo*);

int main () {
	struct Persona Persona1;
	struct Data Data1;
	struct Indirizzo Indirizzo1;
	// Avvaloro record 
	chiediInformazioni(&Persona1,&Data1,&Indirizzo1);	
	// Stampa record
	printf("Nome e cognome %s %s\n", Persona1.nome, Persona1.cognome);
	printf("Data di nascita: %d/%d/%d\n", Persona1.Data1.giorno, Persona1.Data1.mese, Persona1.Data1.anno);
	printf("Indirizzo: Via %s %d, %s", Persona1.Indirizzo1.via, Persona1.Indirizzo1.civico, Persona1.Indirizzo1.citta);
}


void chiediInformazioni(Persona* Persona1, Data* Data1, Indirizzo* Indirizzo1) {
	printf("Come ti chiami?\n");
	scanf("%s",Persona1->nome);
	printf("Qual'e' il tuo cognome?\n");
	scanf("%s",Persona1->cognome);
	printf("Inserisci il giorno in cui sei nato:\n");
	scanf("%d",&Persona1->Data1.giorno);
	printf("Inserisci il mese in cui sei nato:\n");
	scanf("%d",&Persona1->Data1.mese);
	printf("Inserisci l'anno in cui sei nato:\n");
	scanf("%d",&Persona1->Data1.anno);
	printf("Inserisci la citta in cui abiti:\n");
	scanf("%s",Persona1->Indirizzo1.citta);
	printf("Inserisci la via dove abiit:\n");
	scanf("%s",Persona1->Indirizzo1.via);
	printf("Inserisci il civico dove vivi:\n");
	scanf("%d",&Persona1->Indirizzo1.civico);
	}
