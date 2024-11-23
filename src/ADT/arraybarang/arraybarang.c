#include <stdlib.h>
#include "arraybarang.h"
#include "../mesinkata/mesinkata.h"


ListBarang MakeListBarang() {
    ListBarang array;
    array.A = (Barang *) malloc(InitialSize * sizeof(Barang));
    array.Capacity = InitialSize;
    array.Neff = 0;
    return array;
}

void DeallocateListBarang(ListBarang *array) {
    free(array->A);
}

boolean IsBarangEmpty(ListBarang array) {
    return array.Neff == 0;
}


int LengthListBarang(ListBarang array) {
    return array.Neff;
}


Barang GetBarang(ListBarang array, int i) {
    return array.A[i];
}


int GetBarangCapacity(ListBarang array) {
    return array.Capacity;
}


void InsertBarangAt(ListBarang *array, Barang el, int i) {
    int length = LengthListBarang(*array);
    int capacity = GetBarangCapacity(*array);

    if (length == capacity) {
        int desiredCapacity = capacity + InitialSize;
        Barang *arr = (Barang *) malloc(desiredCapacity * sizeof(Barang));
        for (int a = 0; a < length; a++) {
            arr[a] = GetBarang(*array, a);
        }
        free(array->A);
        
        array->A = arr;
        array->Capacity = desiredCapacity;
    }

    for (int a = length - 1; a >= i; a--) {
        array->A[a + 1] = array->A[a];
    }

    array->A[i] = el;
    array->Neff++;
}

void InsertLastBarang(ListBarang *array, Barang el) {
    int insertAt = LengthListBarang(*array);
    InsertBarangAt(array, el, insertAt);
}


void InsertFirstBarang(ListBarang *array, Barang el) {
    InsertBarangAt(array, el, 0);
}

void DeleteBarangAt(ListBarang *array, int i) {
    int length = LengthListBarang(*array);
    for (int a = i; a < length - 1; a++) {
        array->A[a] = array->A[a + 1];
    }
    array->Neff--;
}

void DeleteLastBarang(ListBarang *array) {
    int deleteAt = LengthListBarang(*array) - 1;
    DeleteBarangAt(array, deleteAt);
}


void DeleteFirstBarang(ListBarang *array) {
    DeleteBarangAt(array, 0);
}


void ReverseListBarang(ListBarang *array) {
    int length = LengthListBarang(*array);
    for (int i = 0; i < length / 2; i++) {
        Barang temp = array->A[i];
        array->A[i] = array->A[length - i - 1];
        array->A[length - i - 1] = temp;
    }
}


ListBarang CopyListBarang(ListBarang array) {
    ListBarang copy = MakeListBarang();
    for (int i = 0; i < array.Neff; i++) {
        InsertLastBarang(&copy, array.A[i]);
    }
    return copy;
}


boolean isBarangIn(ListBarang Barang, char *name)
{
    boolean found = false;
    int i = 0;
    while (!found && i != Barang.Neff)
    {
        if (isKataSama(name, Barang.A[i].name))
        {
            found = true;
        }
        i++;
    }
    return found;
}

int idxOfBarang(ListBarang Barang, char *name)
{
    boolean found = false;
    int i = 0;
    while (!found && i != Barang.Neff)
    {
        if (isKataSama(name, Barang.A[i].name))
        {
            found = true;
        }
        else
            i++;
    }
    return i;
}
boolean isKataSama(const char *str1, const char *str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *str1 == *str2;
}

