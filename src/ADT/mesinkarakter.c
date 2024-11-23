#include "mesinkarakter.h"

FILE *tape = NULL;
char currentChar;
int endChar = 1;

void startChar(const char *filename) {
    tape = fopen(filename, "r");
    if (tape != NULL) {
        endChar = 0;
        advanceChar();
    } else {
        fprintf(stderr, "Error: Tidak bisa membuka file %s\n", filename);
        exit(1);
    }
}

void advanceChar() {
    if (tape != NULL) {
        currentChar = fgetc(tape);
        if (currentChar == MARK) {
            closeChar();
        }
    }
}

void closeChar() {
    if (tape != NULL) {
        fclose(tape);
        tape = NULL;
        endChar = 1;
    }
}
