#include "arraydin.h"

ArrayDin MakeArrayDin() {
    ArrayDin array;
    array.isi = (Barang *)malloc(InitialSize * sizeof(Barang));
    array.Capacity = InitialSize;
    array.Neff = 0;
    return array;
}

boolean IsEmpty(ArrayDin array) {
    return array.Neff == 0;
}

int Length(ArrayDin array) {
    return array.Neff;
}

void InsertAt(ArrayDin *array, char* el, IdxType i, int price) {
    if (array->Neff >= array->Capacity) {
        array->Capacity *= 2;
        array->isi = (Barang *)realloc(array->isi, array->Capacity * sizeof(Barang));
    }

    for (int j = array->Neff; j > i; j--) {
        array->isi[j] = array->isi[j - 1];
    }

    strcopy(array->isi[i].name, el);
    array->isi[i].price = price;
    array->Neff++;
}
void DeleteAt(ArrayDin *array, IdxType i) {
    for (int j = i; j < array->Neff - 1; j++) {
        array->isi[j] = array->isi[j + 1];
    }
    array->Neff--;
}