#include <stdio.h>
#include "arraybarang.h"

int main() {
    ListBarang list;
    Barang item1 = {"Pensil", 2000};
    Barang item2 = {"Penghapus", 1000};
    Barang item3 = {"Buku", 15000};

    // MakeListBarang
    list = MakeListBarang();
    printf("List barang dibuat\n");

    // IsBarangEmpty
    if (IsBarangEmpty(list)) {
        printf("List barang kosong\n");
    } else {
        printf("List barang tidak kosong\n");
    }

    // Print kapasitas list barang
    printf("\nKapasitas list: %d\n", GetBarangCapacity(list));

    // InsertBarangAt
    printf("\nMenambahkan barang:\n");
    InsertBarangAt(&list, item1, 0);
    InsertBarangAt(&list, item2, 1);
    InsertBarangAt(&list, item3, 2);

    // Print isi list
    printf("List barang berisi %d barang:\n", LengthListBarang(list));
    for (int i = 0; i < LengthListBarang(list); i++) {
        printf("%d. %s, Harga: %d\n", i + 1, (GetBarang(list, i)).name, GetBarang(list,i).harga);
    }

    // Menghapus barang pada indeks tertentu
    printf("\nMenghapus barang di indeks 1\n");
    DeleteBarangAt(&list, 1);
    printf("List barang berisi %d barang:\n", LengthListBarang(list));
    for (int i = 0; i < LengthListBarang(list); i++) {
        printf("%d. %s, Harga: %d\n", i + 1, (GetBarang(list, i)).name, GetBarang(list,i).harga);
    }

    printf("\n");

    // Dealokasi list barang
    printf("Mendealokasi list barang\n");
    DeallocateListBarang(&list);
    printf("List barang telah didealokasi\n");
    return 0;
}
