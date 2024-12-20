#include <stdio.h>
#include "map.h"

int main() {
    Map M;
    CreateEmptyMap(&M);

    printf("Apakah map kosong? ");
    if (IsEmptyMap(M)) {
        printf("Ya\n\n");
    } else {
        printf("Tidak\n\n");
    }

    printf("Mengisi map...\n\n");
    InsertMap(&M, "Item1", 10);
    InsertMap(&M, "Item2", 20);
    InsertMap(&M, "Item3", 30);

    printf("Isi map:\n");
    for (int i = 0; i < Count(M); i++) {
        printf("Nama: %s - Kuantitas: %d\n", M.Elements[i].Key, M.Elements[i].Value);
    }

    printf("\nApakah Item2 berada di dalam map? ");
    if (IsMemberMap(M, "Item2")) {
        printf("Ya\n");
    } else {
        printf("Tidak\n");
    }

    printf("\nMenghapus Item2\n");
    DeleteMap(&M, "Item2");

    printf("\nIsi map:\n");
    for (int i = 0; i < Count(M); i++) {
        printf("Nama: %s - Kuantitas: %d\n", M.Elements[i].Key, M.Elements[i].Value);
    }

    printf("Apakah map kosong? ");
    if (IsEmptyMap(M)) {
        printf("Ya\n\n");
    } else {
        printf("Tidak\n\n");
    }

    return 0;
}