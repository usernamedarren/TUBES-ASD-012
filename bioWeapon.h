#ifndef BIOWEAPON_H
#define BIOWEAPON_H

#include "circular_queue.h"
#include "str.h"
#include <stdlib.h>

void dna_to_rna(char *string);

char* rna_to_protein (char *string,int idx);

void bioweapon(Queue *Q);

#endif