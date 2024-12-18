#include <stdio.h>
#include "../arraybarang/arraybarang.h"
#include "../mesinkata/mesinkata.h"


void clearWishlist(ListBarang *wishlist) {
    if (IsBarangEmpty(*wishlist)) {
        printf("Wishlist kamu kosong!\n");
    } else {
        DeallocateListBarang(wishlist);
        *wishlist = MakeListBarang();
        printf("Wishlist telah dikosongkan!\n");
    }
}


// int main() {
//     ListBarang wishlist = MakeListBarang();

//     Barang barang1 = {"Laptop"};
//     Barang barang2 = {"Smartphone"};
//     Barang barang3 = {"Headphone"};
    
//     InsertBarangAt(&wishlist, barang1, 0);
//     InsertBarangAt(&wishlist, barang2, 1);
//     InsertBarangAt(&wishlist, barang3, 2);
    
//     printf("Isi wishlist sebelum dikosongkan:\n");
//     for (int i = 0; i < LengthListBarang(wishlist); i++) {
//         printf("%d. %s\n", i + 1, GetBarang(wishlist, i).name);
//     }

//     clearWishlist(&wishlist);

//     printf("\nIsi wishlist setelah dikosongkan:\n");
//     if (IsBarangEmpty(wishlist)) {
//         printf("Wishlist kosong.\n");
//     } else {
//         for (int i = 0; i < LengthListBarang(wishlist); i++) {
//             printf("%d. %s\n", i + 1, GetBarang(wishlist, i).name);
//         }
//     }

//     DeallocateListBarang(&wishlist);

//     return 0;
// }
