/* Beretta Alessio
L'obiettivo di questo esercizio è creare un programma in linguaggio C che permetta di scrivere messaggi di log su un file di log.
*/

#include "stdio.h"
#include "errno.h"
#include "time.h"


void writeLog(FILE *, const char *);    // Funzione per scrivere sul file 



int main () {
    FILE *logFile; // Dichiarazione del file 
    logFile = fopen("log.txt", "a");
    if(logFile == NULL) {
        perror("Il file non si apre!");
        return 1;
    }
    writeLog(logFile,"Prima prova del programma"); 
    writeLog(logFile,"Altra prova del programma parte 2");
    // Puoi chiamare writeLog() con altri messaggi
    return 0;

    fclose(logFile);
}



void writeLog(FILE *logFile, const char *message) {
    // Otteniamo il timestamp corrente
    time_t currentTime; // Prendo il tempo attuale 
    struct tm *localTime;
    time(&currentTime); // Con questa funzione ritorno il tempo se tempo non è NULL 
    localTime = localtime(&currentTime); // Ritorno nella struct localTime il tmepo attuale!

    // Scriviamo il messaggio di log nel formato desiderato
    fprintf(logFile, "[%04d-%02d-%02d %02d:%02d:%02d] %s\n",
            localTime->tm_year + 1900, localTime->tm_mon + 1, localTime->tm_mday, 
            localTime->tm_hour, localTime->tm_min, localTime->tm_sec, message); // Prendo i local time giorno,mese,anno,ore,minuti,secondi dalla struct tm 
}
