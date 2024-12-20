#ifndef MESINKATA_H
#define MESINKATA_H

#include "../mesinkarakter/mesinkarakter.h"
#include "../../boolean.h"
#define NMax 100
#define BLANK ' '

typedef struct {
   char TabWord[NMax]; 
   int Length;         
} Word;


extern boolean EndWord;
extern Word currentWord;


void ResetCurrentWord();


void IgnoreBlanks();


void STARTWORD();


void STARTWORDFILE(char *filename);


void ADVWORD();

void STARTWORD2();

void ADVWORDFILE();

void CopyWord();

void CopyWordBlanks();

void STARTLINE();

boolean isKataEqual(char *kata1, char *kata2);

void displayWord(Word W, boolean newLine);

void WordToString(Word word, char *str);

int wordtoInt(Word word);

int strcmp(const char *str1, const char *str2);

void strcopy(char *dest, const char *src);

int strlength(char *str);

void strconcat(char *dest, const char *src);

boolean strcontains(const char *str1, const char *str2);

void input(char *x);

void inputint (int *x);

void inputUsernamePassword(char *x);

void CopyWord2();

void stringtoint(char *x, int *res);

#endif
