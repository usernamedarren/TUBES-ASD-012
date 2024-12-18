#include <stdio.h>
#include "../arraybarang/arraybarang.h"
#include "../mesinkata/mesinkata.h"

/* WISHLIST SHOW */
void showWishlist(ListBarang wishlist) {
    if (IsBarangEmpty(wishlist)) {
        printf("Wishlist kamu kosong!\n");
    } else {
        printf("Isi wishlist kamu:\n");
        for (int i = 0; i < LengthListBarang(wishlist); i++) {
            printf("%d. %s\n", i + 1, GetBarang(wishlist, i).name);
        }
    }
}

/* Program untuk menguji fungsi showWishlist */
// int main() {
//     ListBarang wishlist = MakeListBarang();

//     Barang barang1 = {"Laptop"};
//     Barang barang2 = {"Smartphone"};
//     Barang barang3 = {"Headphone"};
    
//     InsertBarangAt(&wishlist, barang1, 0);
//     InsertBarangAt(&wishlist, barang2, 1);
//     InsertBarangAt(&wishlist, barang3, 2);
    
//     printf("\nMenampilkan wishlist sebelum penghapusan:\n");
//     showWishlist(wishlist);

//     printf("\nMenampilkan wishlist setelah penghapusan:\n");
//     showWishlist(wishlist);

//     DeallocateListBarang(&wishlist);

//     return 0;
// }

