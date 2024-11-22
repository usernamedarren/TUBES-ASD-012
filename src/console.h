#ifndef WORK_H
#define WORK_H

#include "ADT/mesinkar/mesinkarakter.h"
#include "ADT/mesinkata/mesinkata.h"
#include "boolean.h"

#define Nmax 50

typedef struct {
    Word nama[Nmax]; /* container penyimpan nama pekerjaan, indeks yang dipakai [0..NMax-1] */
    int pendapatan;
    int durasi;
} Pekerjaan;

boolean isWordSame (Word W1, Word W2);
/* Mengecek kesamaan antar 2 kata yaitu W1 dan W2
   I.S. : W1 dan W2 terdefinisi
   F.S. : W1 == W2 atau W1 != W2 */

void displayKerja (Pekerjaan Kerja);
/* Menampilkan nama suatu pekerjaan
   I.S. : Kerja terdefinisi
   F.S. : Nama kerja ditampilkan */

void work();
/*  
    Fungsi work menjalankan pekerjaan sesuai yang diinginkan 
    oleh pengguna. Setiap pekerjaan memiliki waktu tunggu yang 
    berbeda-beda dan dengan nominal pendapatan yang berbeda-beda 
    pula. Selama pengguna sedang bekerja, maka sistem tidak bisa 
    digunakan hingga pekerjaan selesai dilakukan. Setelah pekerjaan 
    selesai dilakukan, pengguna akan mendapatkan uang sesuai nominal
    pendapatan dari pekerjaan yang dilakukan 
*/

#endif