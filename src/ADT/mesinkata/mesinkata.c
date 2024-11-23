#include <stdio.h>
#include <stdlib.h>
#include "mesinkata.h"

boolean EndWord;
Word currentWord;

void ResetCurrentWord() {
    currentWord.Length = 0;
}

void IgnoreBlanks() {
    while (currentChar == BLANK)
        ADV();
}

void STARTWORD() {
    ResetCurrentWord();
    START();
    IgnoreBlanks();
    if (currentChar == MARK)
        EndWord = true;
    else
    {
        EndWord = false;
        CopyWord();
    }
}

void ADVWORD() {
    ResetCurrentWord();
    if (EOP) {
        EndWord = true;
        return;
    }
    CopyWord();
    IgnoreBlanks();
}


void CopyWord() {
    int i = 0;
    while (!EOP && (currentChar != BLANK))
    {
        if (i < NMax)
        {
            currentWord.TabWord[i] = currentChar;
            i++;
        }
        ADV();
    }
    currentWord.Length = i;
}


void STARTWORDFILE(char *filename) {
    boolean success;
    ResetCurrentWord();
    STARTFILE(filename, &success);
    if (success)
    {
        if (currentChar == MARK)
            EndWord = true;
        else
        {
            EndWord = false;
            CopyWordBlanks();
        }
    }
}


void ADVWORDFILE() {
    ADV();
    ResetCurrentWord(); 
    EndWord = false;
    if (currentChar == MARK)
        EndWord = true;
    else
    {
        EndWord = false;
        CopyWordBlanks();
    }
}



void CopyWordBlanks() {
    int i = 0;
    while (!EOP){
        if (i < NMax)
        {
            currentWord.TabWord[i] = currentChar;
            i++;
        }
        ADV();
    }
    currentWord.Length = i;
}

void STARTLINE() {
    ResetCurrentWord();
    START();
    IgnoreBlanks();
    if (currentChar == MARK) {
        EndWord = true;
    } else {
        EndWord = false;
        CopyWordBlanks();
    }
}

boolean isKataEqual(char *kata1, char *kata2)
{
    boolean same = true;
    int lengthkata1 = strlength(kata1);
    int lengthkata2 = strlength(kata2);
    int i = 0;

    if (lengthkata1 != lengthkata2){
        same = false;
    }
    else{
        while (same && i != lengthkata1){
            if (kata1[i] != kata2[i])
                same = false;
            i++;
        }
    }
    return same;
}

void displayWord(Word W, boolean newLine) {
    for (int i = 0; i < W.Length; i++) {
        printf("%c", W.TabWord[i]);
    }
    if (newLine) {
        printf("\n");
    }
}

void WordToString(Word word, char *str) {
    for (int i = 0; i < word.Length; i++) 
    {
        str[i] = word.TabWord[i];
    }
    str[word.Length] = '\0';
}

int wordtoInt(Word word) {
    int result = 0;
    for (int i = 0; i < word.Length; i++) 
    {
        // Validasi jika karakter bukan angka
        if (word.TabWord[i] < '0' || word.TabWord[i] > '9') 
        {
            //printf("ERROR: Invalid number format in Word at character '%c'\n", word.TabWord[i]);
            return -1; // Kembalikan -1 jika ada karakter bukan angka
        }
        result = result * 10 + (word.TabWord[i] - '0');
    }
    return result;
}

void printw(Word W, boolean newline) {
    for (int i = 0; i < W.Length; i++)
    {
        printf("%c", W.TabWord[i]);
    }
    if (newline)
        printf("\n");
}
int strcmp(const char *str1, const char *str2) {
    int i = 0;
    while (str1[i] && (str1[i] == str2[i])) {
        i++;
    }
    return (unsigned char)str1[i] - (unsigned char)str2[i];
}

void strcopy(char *dest, const char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}


int strlength(char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

void strconcat(char *dest, const char *src) {
    int i = strlength(dest); 
    int j = 0;
    while (src[j] != '\0') {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
}

int strcontains(const char *str1, const char *str2) {
    int i = 0;
    int j = 0;
    while (str1[i]) {
        if (str1[i] == str2[j]) {
            while (str1[i + j] && str2[j] && str1[i + j] == str2[j]) {
                j++;
            }
            if (!str2[j]) {
                return 1;
            }
        }
        i++;
    }
    return 0;
}
void input(char *x) {
    int idx = 0;
    while (1) {
        idx = 0;
        START();
        while (!IsEOP()) {
            x[idx++] = GetCC();
            ADV();
        }
        x[idx] = '\0';

        if (strlength(x) == 0) {
            printf("Input tidak boleh kosong\n");
        } else {
            break;
        }
    }
}
void inputint(int *x) {
    while (1) {
        char inputstr[100];
        int valid = 1;

        input(inputstr);
        for (int i = 0; i < strlength(inputstr); i++) {
            if (inputstr[i] < '0' || inputstr[i] > '9') {
                valid = 0;
                break;
            }
        }
        if (valid) {
            *x = atoi(inputstr);
            break;
        } else {
            printf("Input harus berupa angka\n");
        }
    }
}
