#include <stdio.h>
#include <stdlib.h>
#include "work-challenge.h"

void workChallenge() {
    Word kataJawaban;
    int language;
    int pickChallenge;

    printf("Daftar challenge yang tersedia:\n");
    printf("1. Tebak Angka (biaya main=200)\n");   
    printf("2. WORDL399 (biaya main = 500)\n");
    printf("Masukkan challenge yang hendak dimainkan: ");
    scanf("%d", &pickChallenge);
    printf("\n");

    if (pickChallenge == 1) {
        tebakAngka(RNG(1, 100));
    } else if (pickChallenge == 2) {
        printf("KATA TERSEDIA DALAM 2 BAHASA YAITU: \n");
        printf("1. English\n");
        printf("2. Bahasa Indonesia\n");
        printf("PILIH BAHASA DARI KATA YANG INGIN ANDA TEBAK: ");
        scanf("%d", &language);
        printf("SELAMAT DATANG DI WORDL3! ANDA MEMILIKI 6 KESEMPATAN UNTUK MENJAWAB DENGAN BENAR!\n");
        if (language == 1) { 
            kataJawaban = listKataInggris[RNG(0,50)];
        } else if (language == 2) {
            kataJawaban = listKataIndo[29];
        }   
        for (int i = 0; i < 6; i++) {
            printf("_  _  _  _  _ \n");
        }
        wordl3(kataJawaban);
    }
}