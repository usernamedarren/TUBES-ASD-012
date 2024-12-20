#ifndef __MESINKARAKTER_H__
#define __MESINKARAKTER_H__

#include "../../boolean.h"
#include "../mesinkata/mesinkata.h"

#define MARK '\n' 

extern char currentChar; 
extern boolean EOP;

void RESETPITA();

void STARTFILE(char *file_name, boolean *success);

void WRITEFILE(char * filename, boolean *success);

char GetCC();

boolean IsEOP();

void START();

void ADV();

void printchar(char c);

void printstring(const char *str);

void printint(int value);

boolean validtxt(char *str);

#endif
