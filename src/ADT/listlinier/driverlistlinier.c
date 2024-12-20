#include "listlinier.h"
#include <stdio.h>

int main () {
    List wishlist;
    CreateEmptyList(&wishlist);

    printf("Apakah wishlist kosong? %s\n", IsEmptyList(wishlist) ? "Ya" : "Tidak");


    printf("Menambahkan elemen ke wishlist...\n");
    InsVLast(&wishlist, "Adam");
    InsVLast(&wishlist, "Darren");
    InsVLast(&wishlist, "Ferro");
    InsVFirst(&wishlist, "Jenni");

    printf("Isi wishlist:\n");
    PrintInfo(wishlist);

    printf("Jumlah elemen dalam wishlist: %d\n", NbElmtList(wishlist));

    infotypelist target = "Adam";
    address_list p = SearchList(wishlist, target);
    if (p != NilList) {
        printf("Elemen '%s' ditemukan dalam wishlist.\n", target);
    } else {
        printf("Elemen '%s' tidak ditemukan dalam wishlist.\n", target);
    }


    infotypelist a;
    DelVFirst(&wishlist, &a);
    printf("Elemen '%s' dihapus dari wishlist.\n", a);

    printf("Isi wishlist setelah penghapusan elemen pertama:\n");
    PrintInfo(wishlist);


    printf("Membalikkan isi wishlist...\n");
    InversList(&wishlist);

    printf("Isi wishlist setelah dibalik:\n");
    PrintInfo(wishlist);


    List wishlist2;
    CreateEmptyList(&wishlist2);

    printf("Menambahkan elemen ke wishlist kedua...\n");
    InsVLast(&wishlist2, "Samuel");
    InsVLast(&wishlist2, "Jason");

    printf("Isi wishlist kedua:\n");
    PrintInfo(wishlist2);

    List wishlist3;
    Konkat1(&wishlist, &wishlist2, &wishlist3);

    printf("Isi wishlist gabungan:\n");
    PrintInfo(wishlist3);

    printf("Jumlah elemen dalam wishlist gabungan: %d\n", NbElmtList(wishlist3));

    return 0;
}