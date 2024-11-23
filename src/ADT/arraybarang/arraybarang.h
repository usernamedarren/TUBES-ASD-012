#ifndef __ARRAY_ITEMS__
#define __ARRAY_ITEMS__

#include "../mesinkata/mesinkata.h"
#include "../kustom/kustom.h"

#define boolean unsigned char
#define true 1
#define false 0

#define InitialSize 10

typedef struct {
    Barang *A;
    int Capacity;
    int Neff;
} ListBarang;

ListBarang MakeListBarang();

void DeallocateListBarang(ListBarang *array);

boolean IsBarangEmpty(ListBarang array);

int LengthListBarang(ListBarang array);

Barang GetBarang(ListBarang array, int i);

int GetBarangCapacity(ListBarang array);

void InsertBarangAt(ListBarang *array, Barang el, int i);

void DeleteBarangAt(ListBarang *array, int i);



#endif
