#ifndef __MESINKARAKTER_H__
#define __MESINKARAKTER_H__

#include "../../boolean.h"

#define MARK '\n' 

extern char currentChar; 
extern boolean EOP;

void RESETPITA();
/* I.S. : sembarang
   F.S. : pita berada di posisi awal file
          Jika pita belum dibuka, fungsi tidak melakukan apa-apa */

void STARTFILE(char *file_name, boolean *success);
/* Membaca pita dari file
   I.S. : Nama file valid, file berada di direktori "../data/"
   F.S. : currentChar adalah karakter pertama dalam pita
          Jika file tidak dapat dibuka, success = false */

void WRITEFILE(char * filename, boolean *success);

char GetCC();

boolean IsEOP();

void START();
/* Membaca pita dari stdin
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama dalam pita
          EOP menyala jika currentChar = MARK */

void ADV();
/* Memajukan pembacaan pita
   I.S. : currentChar adalah karakter saat ini
   F.S. : currentChar adalah karakter berikutnya
          Jika mencapai MARK atau EOF, EOP menyala */

#endif