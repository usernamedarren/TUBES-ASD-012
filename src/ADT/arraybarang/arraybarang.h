#ifndef __ARRAY_ITEMS__
#define __ARRAY_ITEMS__

#define boolean unsigned char
#define true 1
#define false 0
#define NMax 100

#define InitialSize 10

typedef struct {
  char name[NMax];
  int harga;
} Barang;

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

void InsertLastBarang(ListBarang *array, Barang el);

void InsertFirstBarang(ListBarang *array, Barang el);

void DeleteBarangAt(ListBarang *array, int i);

void DeleteLastBarang(ListBarang *array);

void DeleteFirstBarang(ListBarang *array);

void ReverseListBarang(ListBarang *array);

ListBarang CopyListBarang(ListBarang array);

boolean isBarangIn(ListBarang Barang, char *name);

int idxBarang(ListBarang Barang, char *name);

boolean isKataSama(const char *str1, const char *str2);

#endif
