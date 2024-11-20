#include <stdio.h>
#include "mesinkarakter.h"

char currentChar;
boolean EOP;

void START() {
    scanf("%c", &currentChar);
    EOP = (currentChar == MARK);
}

void ADV() {
    if (!EOP) {
        scanf("%c", &currentChar);
        EOP = (currentChar == MARK);
    }
}

char GetCC() {
    return currentChar;
}

boolean IsEOP() {
    return EOP;
}