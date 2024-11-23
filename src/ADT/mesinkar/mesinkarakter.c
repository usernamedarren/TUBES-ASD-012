#include "mesinkarakter.h"
#include <stdio.h>
#include <stdlib.h>

char currentChar;
boolean EOP;

static FILE *pita = NULL;
static int retval;

void RESETPITA() {
    if (pita != NULL) {
        rewind(pita);
    }
}

void STARTFILE(char *filename, boolean *success) {
    static char path[200] = "save/";
    int idx = 0;
    int newIdx = 5; // Mulai setelah "save/"

    while (filename[idx] != '\0') {
        path[newIdx] = filename[idx];
        newIdx++;
        idx++;
    }
    path[newIdx] = '\0';

    //printf("DEBUG: Attempting to open file at path: %s\n", path);

    pita = fopen(path, "r");
    if (pita == NULL) {
        *success = false;
        //printf("DEBUG: File open failed.\n");
    } else {
        *success = true;
        //printf("DEBUG: File successfully opened.\n");
        ADV(); // Mulai membaca karakter pertama
    }
}


void WRITEFILE(char *filename, boolean *success) {
    static char path[200] = "save/";
    int idx = 0;
    int newIdx = 5;

    while (filename[idx] != '\0') {
        path[newIdx] = filename[idx];
        newIdx++;
        idx++;
    }
    path[newIdx] = '\0';


    pita = fopen(path, "w");
    if (pita == NULL) {
        *success = false;
        //printf("ERROR: Gagal membuka file untuk menulis: %s\n", path);
    } else {
        *success = true;
    }
}

char GetCC(){
    return currentChar;
}

boolean IsEOP(){
    return currentChar == MARK;
}

void START() {
    RESETPITA();
    pita = stdin;

    EOP = false;
    ADV();
}

void ADV() {
    retval = fscanf(pita, "%c", &currentChar);
    //printf("DEBUG: Read character '%c'\n", currentChar); // Tambahkan debug di sini
    if (currentChar == MARK || retval == EOF) {
        EOP = true;
        //printf("DEBUG: End of file or MARK reached.\n"); // Tambahkan debug di sini
    } else {
        EOP = false;
    }
}
