#ifndef CONSOLE_H
#define CONSOLE_H

#include "ADT/arraydin/arraydin.h"
#include "ADT/circular_queue/circular_queue.h"
#include "ADT/kustom/kustom.h"
#include "ADT/str/str.h"

void listStore(ArrayDin A);
void requestStore(ArrayDin A, Queue *Q);
void supplyStore(ArrayDin *A, Queue *Q);
void removeStore(ArrayDin *A);
void dna_to_rna(char *string);
char* rna_to_protein (char *string,int idx);
void bioweapon(Queue *Q);

#endif