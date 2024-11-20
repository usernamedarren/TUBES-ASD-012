#include <stdio.h>
#include "tebak-angka.h"

void tebakAngka(int angkaJawaban) {
    int angkaTebakan;
    boolean tebakanBenar = false;
    int coinHadiah = 600;
    int jumlahTebakan = 0;

    while (tebakanBenar == false && jumlahTebakan < 10) {
        printf("Tebak angka: ");
        scanf("%d", &angkaTebakan);
        if (angkaTebakan > angkaJawaban) {
            printf("Tebakanmu lebih besar!\n\n");
            coinHadiah -= 50;
        } else if (angkaTebakan < angkaJawaban) {
            printf("Tebakanmu lebih kecil!\n\n");
            coinHadiah -= 50;
        } else { // Tebakan benar
            printf("Tebakanmu benar! +%d rupiah telah ditambahkan ke akun Anda.\n", coinHadiah);
            tebakanBenar = true;
        }
        jumlahTebakan += 1;
    }

    if (tebakanBenar == false) {
        printf("Boo! Anda kalah");
    }
}