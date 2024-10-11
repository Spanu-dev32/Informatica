/* Beretta Alessio
	Data una struct
	struct tempo {
	   int seconds;
	   int minutes;
	   int hours;
	};
	Scrivere una funzione che passati due tempi ne calcoli la differenza
	void diffBetweenTimePeriod(struct tempo t1, struct tempo t2, struct tempo *diff);
*/

#include "stdio.h"
struct tempo {
		int seconds;
		int minutes;
		int hours;
}typedef tempo;

void diffBetweenTimePeriod(tempo start,tempo end,tempo*diff);	// Funzione per la differenza tempo
void chiediTempo(tempo*,tempo*);	// Funzione per chiedere il tempo con i puntatori per avere un main piu pulito

int main () {
	tempo start,end,diff;
	chiediTempo(&start,&end);
	diffBetweenTimePeriod(start,end,&diff);	
	
	printf("Differenza: %d:%d:%d\n", diff.hours, diff.minutes, diff.seconds);
}

void diffBetweenTimePeriod(tempo start, tempo end, tempo* diff) {
	// Calcolo secondi
    if (start.seconds < end.seconds) {
        start.minutes--;               // Decremento i minuti
        start.seconds = start.seconds+60;            // Aggiungo 60 secondi
    }
    diff->seconds = start.seconds - end.seconds;

    // Calcolo dei minuti 
    if (start.minutes < end.minutes) {
        start.hours--;                 // Decremento le ore
        start.minutes = start.minutes+60;          // Aggiungo 60 minuti
    }
    diff->minutes = start.minutes - end.minutes;

	// Calcolo delle ore 
    diff->hours = start.hours - end.hours;
}


void chiediTempo(tempo* start, tempo* end) {  // Puntatori per modificare i valori originali

    printf("Inserisci le ore iniziali: ");
    scanf("%d", &start->hours);  
    printf("Inserisci i minuti iniziali: ");
    scanf("%d", &start->minutes);
    printf("Inserisci i secondi iniziali: ");
    scanf("%d", &start->seconds);

    printf("Inserisci le ore finali: ");
    scanf("%d", &end->hours);
    printf("Inserisci i minuti finali: ");
    scanf("%d", &end->minutes);
    printf("Inserisci i secondi finali: ");
    scanf("%d", &end->seconds);
}
