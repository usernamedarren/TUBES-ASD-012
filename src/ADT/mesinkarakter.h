#ifndef MESINKARAKTER_H
#define MESINKARAKTER_H

#include <stdio.h>
#include <stdlib.h>

#define MARK EOF

extern FILE *tape;
extern char currentChar;
extern int endChar;

void startChar(const char *filename);
void advanceChar();
void closeChar();

#endif
