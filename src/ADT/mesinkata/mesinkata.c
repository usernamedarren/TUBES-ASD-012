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

void STARTWORD2() {
    ResetCurrentWord();
    START();
    IgnoreBlanks();
    if (currentChar == MARK)
        EndWord = true;
    else
    {
        EndWord = false;
        CopyWord2();
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

void CopyWord2() {
    int i = 0;
    while ((currentChar != MARK))
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

int wordtoInt(Word word) 
{
    int result = 0;
    for (int i = 0; i < word.Length; i++) 
    {
        if (word.TabWord[i] < '0' || word.TabWord[i] > '9') 
        {
            return -1; 
        }
        result = result * 10 + (word.TabWord[i] - '0');
    }
    return result;
}

void stringtoint(char *x, int *res)
{
    *res = 0;
    for (int i = 0; x[i] != '\0'; i++) 
    {
        if (x[i] < '0' || x[i] > '9') 
        {
            *res = -1;
            return;
        }
        *res = *res * 10 + (x[i] - '0');
    }
}

void strcopy(char *str1, const char *str2) 
{
    int i = 0;
    while (str2[i] != '\0') 
    {
        str1[i] = str2[i];
        i++;
    }
    str1[i] = '\0';
}


int strlength(char *str) 
{
    int length = 0;
    while (str[length] != '\0') 
    {
        length++;
    }
    return length;
}

void strconcat(char *str1, const char *str2) 
{
    int i = strlength(str1); 
    int j = 0;
    while (str2[j] != '\0') 
    {
        str1[i] = str2[j];
        i++;
        j++;
    }
    str1[i] = '\0';
}

int strcmp(const char *str1, const char *str2) 
{
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i]) 
    {
        i++;
    }
    return str1[i] - str2[i];
}

boolean strcontains(const char *str1, const char *str2) 
{
    int i = 0;
    int j = 0;
    while (str1[i]!='\0') 
    {
        if (str1[i] == str2[j]) 
        {
            while (str1[i + j]!='\0' && str2[j]!='\0' && str1[i + j] == str2[j]) 
            {
                j++;
            }
            if (str2[j]=='\0') 
            {
                return 1;
            }
        }
        i++;
    }
    return 0;
}
void input(char *x) 
{
    int idx = 0;
    while (1) 
    {
        idx = 0;
        START();
        while (!IsEOP()) 
        {
            x[idx++] = GetCC();
            ADV();
        }
        x[idx] = '\0';

        if (strlength(x) == 0) 
        {
            printf("Input tidak boleh kosong\n");
            printf("Masukkan ulang: ");
        } else 
        {
            break;
        }
    }
}

void inputint(int *x) 
{
    while (1) 
    {
        char inputstr[100];
        int valid = 1;

        input(inputstr);
        for (int i = 0; i < strlength(inputstr); i++) 
        {
            if (inputstr[i] < '0' || inputstr[i] > '9') 
            {
                valid = 0;
                break;
            }
        }
        if (valid) 
        {
            *x = atoi(inputstr);
            break;
        } 
        else 
        {
            printf("Input harus berupa angka\n");
            printf("Masukkan ulang: ");
        }
    }
}

void inputUsernamePassword(char *x)
{
    int idx = 0,spasi=0;
    while (1) 
    {
        idx = 0;
        START();

        while (!IsEOP()) 
        {
            char ch = GetCC();
            if (ch == ' ') 
            {
                printf("Input nama/password tidak valid\n");
                printf("Masukkan ulang: ");
                idx = 0; spasi=1;
                break;
            }
            x[idx++] = ch;
            ADV();
        }
        x[idx] = '\0';
        if (strlength(x)!=0) 
        {
            break;
        } 
        else if (strlength(x) == 0 && spasi==0) 
        {
            printf("Input tidak boleh kosong\n");
            printf("Masukkan ulang: ");
        }
        spasi=0;
    }
}


