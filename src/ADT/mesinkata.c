#include "mesinkata.h"

Word currentWord;
int endWord = 1;

void ignoreBlank() {
    while (currentChar == BLANK || currentChar == NEWLINE) {
        advanceChar();
    }
}

void startWord() {
    ignoreBlank();
    if (currentChar != MARK) {
        currentWord.length = 0;
        while (currentChar != BLANK && currentChar != NEWLINE && currentChar != MARK) {
            currentWord.contents[currentWord.length] = currentChar;
            currentWord.length++;
            advanceChar();
        }
        currentWord.contents[currentWord.length] = '\0';
        endWord = 0;
    }
}

void advanceWord() {
    ignoreBlank();
    if (currentChar != MARK) {
        currentWord.length = 0;
        while (currentChar != BLANK && currentChar != NEWLINE && currentChar != MARK) {
            currentWord.contents[currentWord.length] = currentChar;
            currentWord.length++;
            advanceChar();
        }
        currentWord.contents[currentWord.length] = '\0';
    } else {
        endWord = 1;
    }
}
