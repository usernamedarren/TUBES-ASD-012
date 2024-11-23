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


void DeleteBarangAt(ListBarang *array, int i) {
    int length = LengthListBarang(*array);
    for (int a = i; a < length - 1; a++) {
        array->A[a] = array->A[a + 1];
    }
    array->Neff--;
}




