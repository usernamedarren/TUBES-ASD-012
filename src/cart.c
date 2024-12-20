#include "cart.h"

void cartAdd (Map *M, char *nama, int kuantitas, ListBarang listb) {
    if (getBarangIndex(listb, nama) == -1) {
        printf("Barang tidak ada di toko!\n");
    } else {
        InsertMap(M, nama, kuantitas);
        printf("Berhasil menambahkan %d %s ke keranjang belanja!\n", kuantitas, nama);
    }
}

void cartRemove (Map *M, char *nama, int kuantitas) {
    if (!IsMemberMap(*M, nama)) {
        printf("Barang tidak ada di keranjang belanja!\n");
    } else {
        int idx = idxMap(*M, nama);
        if (kuantitas > Elements(*M)[idx].Value) {
            printf("Tidak berhasil mengurangi, hanya terdapat %d %s pada keranjang!\n", Elements(*M)[idx].Value, nama);
        } else if (kuantitas < Elements(*M)[idx].Value) {
            Elements(*M)[idx].Value -= kuantitas;
            printf("Berhasil mengurangi %d %s dari keranjang belanja!\n", kuantitas, nama);
        } else { // bila kuantitas barang di keranjang dihapus sepenuhnya
            DeleteMap(M, nama);
            printf("Berhasil mengurangi %d %s dari keranjang belanja!\n", kuantitas, nama);
        }
    }
}

void cartShow (Map M, ListBarang listb) {
    if (IsEmptyMap(M)) {
        printf("Keranjang kamu kosong!\n");
    } else {
        printf("Berikut adalah isi keranjangmu.\n");
        int totalHargaCart = 0;
        printf("Kuantitas     Nama         Total\n");
        for (int i = 0; i < Count(M); i++) {
            int idxBarang = getBarangIndex(listb, Elements(M)[i].Key);
            int hargaBarang = listb.A[idxBarang].harga;
            int totalHargaBarang = Elements(M)[i].Value*hargaBarang;
            totalHargaCart += totalHargaBarang;
            printf("%-13d %-12s %d\n", Elements(M)[i].Value, Elements(M)[i].Key, totalHargaBarang);
        }
        printf("total biaya yang harus dikeluarkan adalah %d.\n", totalHargaCart);
    }
}

void cartPay (Map M, ListBarang listb, User *user, Stack riwayat) {
    if (IsEmptyMap(M)) {
        printf("Keranjang kamu kosong!\n");
    } else {
        char *confirm;
        int totalHargaCart = 0;
        infotypeStack max_Barang;
        max_Barang.totalHarga = -1;

        printf("Kamu akan membeli barang-barang berikut.");
        printf("Kuantitas     Nama         Total\n");
        for (int i = 0; i < Count(M); i++) {
            int idxBarang = getBarangIndex(listb, Elements(M)[i].Key);
            int hargaBarang = listb.A[idxBarang].harga;
            int totalHargaBarang = Elements(M)[i].Value*hargaBarang;
            totalHargaCart += totalHargaBarang;
            if (totalHargaBarang > max_Barang.totalHarga) {
                max_Barang.totalHarga = totalHargaBarang;
                max_Barang.namaBarang = Elements(M)[i].Key;
            } else if (totalHargaBarang == max_Barang.totalHarga) {
                if (strcmp(Elements(M)[i].Key, max_Barang.namaBarang) > 0) {
                    max_Barang.namaBarang = Elements(M)[i].Key;
                }
            }
            printf("%-13d %-12s %d\n", Elements(M)[i].Value, Elements(M)[i].Key, totalHargaBarang);
        }

        printf("total biaya yang harus dikeluarkan adalah %d, Apakah Anda jadi membeli?\n", totalHargaCart);
        printf("(Ya/Tidak): ");
        input(confirm);
        printf("\n\n");

        if (isKataEqual(confirm, "Ya")) {
            if (user->uang < totalHargaCart) {
                printf("Uang kamu hanya %d, tidak cukup untuk membeli barang-barang di keranjang!\n", user->uang);
            } else {
                user->uang -= totalHargaCart;
                PushStack(&riwayat, max_Barang);
                printf("Selamat kamu telah membeli barang-barang tersebut!\n");
            }
        }
    }
}