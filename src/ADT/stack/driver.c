#include <stdio.h>
#include "stack.h"

int main() {
    Stack S;
    infotypeStack item;
    infotypeStack poppedItem;

    CreateEmptyStack(&S);
    printf("Apakah Stack kosong? ");
    if (IsEmptyStack(S)) {
        printf("Ya\n\n");
    } else {
        printf("Tidak\n\n");
    }

    printf("Mengisi stack...\n");

    item.namaBarang = "Item1";
    item.totalHarga = 100;
    PushStack(&S, item);

    item.namaBarang = "Item2";
    item.totalHarga = 200;
    PushStack(&S, item);

    item.namaBarang = "Item3";
    item.totalHarga = 300;
    PushStack(&S, item);

    for (int i = 0; i <= Top(S); i++) {
        printf("Nama: %s - Harga: %d\n", S.T[i].namaBarang, S.T[i].totalHarga);
    }
    printf("Total biaya: %d\n\n", S.totalBiaya);

    PopStack(&S, &poppedItem);
    printf("Pop Item3\n");

    printf("Item yang tersisa di stack:\n");
    for (int i = 0; i <= Top(S); i++) {
        printf("Nama: %s - Harga: %d\n", S.T[i].namaBarang, S.T[i].totalHarga);
    }
    printf("Total biaya: %d\n\n", S.totalBiaya);

    printf("Apakah Stack kosong? ");
    if (IsEmptyStack(S)) {
        printf("Ya\n");
    } else {
    }

    return 0;
}
