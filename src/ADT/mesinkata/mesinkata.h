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
/* I.S. : currentWord sembarang
   F.S. : currentWord kosong (Length = 0) */


void IgnoreBlanks();
/* I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */


void STARTWORD();
/* I.S. : currentChar sembarang
   F.S. : EndWord = true jika input kosong,
          EndWord = false jika ada kata pertama */

/* Memulai pembacaan kata dari file */
void STARTWORDFILE(char *filename);
/* I.S. : Nama file valid
   F.S. : EndWord = true jika file kosong atau gagal dibuka,
          EndWord = false jika ada kata pertama */

void ADVWORD();
/* I.S. : currentChar adalah karakter pertama dari kata berikutnya
   F.S. : currentWord berisi kata terakhir yang berhasil diakuisisi,
          EndWord = true jika currentChar = MARK */


void ADVWORDFILE();
/* I.S. : currentChar adalah karakter pertama dari kata berikutnya
   F.S. : currentWord berisi kata terakhir yang berhasil diakuisisi,
          EndWord = true jika currentChar = MARK */


void CopyWord();
/* I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang diakuisisi,
          currentChar berada di BLANK atau MARK */


void CopyWordBlanks();
/* I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang diakuisisi,
          currentChar berada di MARK */

/* Memulai pembacaan satu baris penuh dari input user */
void STARTLINE();
/* I.S. : currentChar sembarang
   F.S. : EndWord = true jika input kosong,
          EndWord = false jika ada kata pertama */


boolean isKataEqual(char *kata1, char *kata2);
/* I.S. : W1 dan W2 terdefinisi
   F.S. : Mengembalikan true jika W1 = W2, false jika tidak */


void displayWord(Word W, boolean newLine);
/* I.S. : W terdefinisi
   F.S. : Isi kata ditampilkan ke layar, jika newLine = true maka tambahkan newline */

void WordToString(Word word, char *str);
/* Mengubah Word menjadi string */

int wordtoInt(Word word);
/* I.S. : W terdefinisi
   F.S. : Mengembalikan nilai integer dari W */

void printw(Word W, boolean newline);

int strcmp(const char *str1, const char *str2);

void strcopy(char *dest, const char *src);

int strlength(char *str);

void strconcat(char *dest, const char *src);

boolean strcontains(const char *str1, const char *str2);

void input(char *x);

void inputint (int *x);

void inputUsernamePassword(char *x);

#endif
