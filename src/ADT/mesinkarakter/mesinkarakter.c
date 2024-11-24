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
    int newIdx = 5; 

    while (filename[idx] != '\0') {
        path[newIdx] = filename[idx];
        newIdx++;
        idx++;
    }
    path[newIdx] = '\0';

    pita = fopen(path, "r");
    if (pita == NULL) {
        *success = false;
        //printf(File open failed.\n");
    } else {
        *success = true;
        //printf("File successfully opened.\n");
        ADV(); 
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
    //printf("karakter yang dibaca '%c'\n", currentChar); 
    if (currentChar == MARK || retval == EOF) {
        EOP = true;
        //printf("End of file or MARK reached.\n"); 
    } else {
        EOP = false;
    }
}

void printchar(char c) {
    if (pita != NULL) {
        fprintf(pita, "%c", c);
    }
}

void printstring(const char *str) {
    if (pita != NULL) {
        fprintf(pita, "%s", str);
    }
}

void printint(int value) {
    if (pita != NULL) {
        fprintf(pita, "%d", value);
    }
}

