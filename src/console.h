#ifndef CONSOLE_H
#define CONSOLE_H

#include "ADT/arraybarang/arraybarang.h"
#include "ADT/circular_queue/circular_queue.h"
#include "ADT/mesinkarakter/mesinkarakter.h"
#include "ADT/mesinkata/mesinkata.h"
#include "ADT/arrayuser/arrayuser.h"
#include "ADT/kustom/kustom.h"

void start(ListBarang *itemlist, ListUser *userlist);
void Load(char *filename, ListBarang *itemlist, ListUser *userlist, int *bisa);
void Help(int menu);
void listStore(ListBarang A);
void requestStore(ListBarang A, Queue *Q);
void supplyStore(ListBarang *A, Queue *Q);
void removeStore(ListBarang *A);
void dna_to_rna(char *string);
char* rna_to_protein (char *string,int idx);
void bioweapon(Queue *Q, ListBarang A);
void Save(ListBarang itemlist, ListUser userlist);
void quit(ListBarang itemlist, ListUser userlist);
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