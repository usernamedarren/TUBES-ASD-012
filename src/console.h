#ifndef CONSOLE_H
#define CONSOLE_H

#include "ADT/arraybarang/arraybarang.h"
#include "ADT/circular_queue/circular_queue.h"
#include "ADT/mesinkarakter/mesinkarakter.h"
#include "ADT/mesinkata/mesinkata.h"
#include "ADT/arrayuser/arrayuser.h"

void Load(char *filename, ListBarang *itemlist, ListUser *userlist);
void Help(const char *menu);
void listStore(ListBarang A);
void requestStore(ListBarang A, Queue *Q);
void supplyStore(ListBarang *A, Queue *Q);
void removeStore(ListBarang *A);
void dna_to_rna(char *string);
char* rna_to_protein (char *string,int idx);
void bioweapon(Queue *Q, ListBarang A);
void Save(ListBarang itemlist, ListUser userlist);



#endif