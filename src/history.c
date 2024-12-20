#include "history.h"

void history (Stack riwayat, int N) {
    if (IsEmptyStack(riwayat)) {
        printf("Kamu belum membeli barang apapun!\n");
    } else {
        printf("Riwayat pembelian barang: \n");
        if (N > Top(riwayat)) {
            N = Top(riwayat);
        }
        for (int i = 0; i < N; i++) {
            printf("%d. %s %d", i+1, riwayat.T[N-i].namaBarang, riwayat.T[N-i].totalHarga);
        }
    }
}