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
    } else {
        *success = true;
        ADV(); 
    }
}

boolean validtxt(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '.' && str[i + 1] == 't' && str[i + 2] == 'x' && str[i + 3] == 't')
        {
            return true;
        }
        i++;
    }
    return false;
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
    if (currentChar == MARK || retval == EOF) {
        EOP = true;
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

