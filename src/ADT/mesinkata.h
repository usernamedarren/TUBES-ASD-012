#ifndef MESINKATA_H
#define MESINKATA_H

#include "mesinkarakter.h"

#define BLANK ' '
#define NEWLINE '\n'
#define MAX_WORD_LENGTH 100

typedef struct {
    char contents[MAX_WORD_LENGTH];
    int length;
} Word;

extern Word currentWord;
extern int endWord;

void ignoreBlank();
void startWord(); 
void advanceWord();

#endif
