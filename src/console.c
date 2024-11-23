#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "console.h"

char *listKataInggris[LIST_SIZE] = {
    "AGENT", "AUDIO", "BLACK", "BUYER", "CRASH", 
    "CLAIM", "DELAY", "ENTRY", "FORTH", "GROUP", 
    "GHOST", "HAPPY", "HORSE", "HEAVY", "IDEAL", 
    "IMAGE", "JUICE", "JUDGE", "KNOWN", "KNEES", 
    "LOCAL", "LOBBY", "MONEY", "MEDIA", "NORTH", 
    "NAILS", "OTHER", "OFTEN", "PAPER", "PLANE", 
    "QUEEN", "RUSTY", "ROUTE", "SNAIL", "SLOTH",  
    "TULIP", "TODAY", "UNDER", "UNION", "VALID",   
    "VALUE", "WATER", "WRONG", "WHALE", "ZEBRA", 
    "EXCEL", "AXIOM", "INDEX", "CRAZE", "DOZER"
};

char *listKataIndo[LIST_SIZE] = {
    "ABSEN", "ATASI", "BENCI", "BUNGA", "CEMAS", 
    "CINTA", "DAPUR", "DOSEN", "EMBER", "GELAS", 
    "HALUS", "HASIL", "INDAH", "INSAN", "JAMUR", 
    "JARAK", "JENUH", "JUMPA", "KECIL", "KERAS", 
    "LEMAK", "LIHAT", "LAMPU", "MERAH", "MENIT", 
    "MOBIL", "NANTI", "NYALA", "ORGAN", "ONCOM", 
    "PAHIT", "PATUH", "PINTA", "RAKIT", "RUSAK", 
    "RINDU", "SAKIT", "SEDIA", "SEMUT", "TANAH",   
    "TELUR", "UJIAN", "GANDA", "GRAHA", "DUNIA", 
    "GITAR", "IRAMA", "HABIS", "ANGIN", "BELAH"
};

int RNG (int min, int max) {
    return(rand() % (max - min + 1) + min); // nilai random berada pada rentang value minimal dan maksimal sesuai yang diinginkan
}

boolean isCharInKata (char c, char *kata) {
    for (int i = 0; kata[i] != '\0'; i++) {
        if (c == kata[i]) {
            return true;
        }
    }
    return false;
}

int idxCharInKata (char c, char *kata) {
    for (int i = 0; kata[i] != '\0'; i++) {
        if (c == kata[i]) {
            return i;
        }
    }
}

void wordl3(char *kataJawaban) {
    char kataTebakan[WORD_LENGTH + 1]; // space terakhir untuk \0 sebagai null terminator
    char copyKataTebakan[WORD_LENGTH + 1]; // copyKataTebakan dan copyKataJawaban untuk dimodifikasi nantinya
    char copyKataJawaban[WORD_LENGTH + 1];
    char results[MAX_ATTEMPTS][WORD_LENGTH * 3 + 1]; // menyimpan hasil dari berbagai percobaan
    char currentResult[WORD_LENGTH * 3 + 1]; // menyimpan hasil dari percobaan saat ini
    boolean tebakanBenar = false;
    int attempts = 0;

    while (tebakanBenar == false && attempts < 6) {
        printf("MASUKKAN KATA TEBAKAN ANDA: ");
        input(kataTebakan);
        attempts++;
        strcopy(copyKataTebakan, kataTebakan);
        strcopy(copyKataJawaban, kataJawaban); // membuat copyKataJawaban yang nantinya akan di modify
        // mengecek karakter yang berada di posisi sama terlebih dahulu
        for (int i = 0; copyKataTebakan[i] != '\0'; i++) {
            if (copyKataJawaban[i] == copyKataTebakan[i]) {
                currentResult[i * 3] = kataTebakan[i];
                currentResult[i * 3 + 1] = ' ';
                currentResult[i * 3 + 2] = ' '; 
                copyKataTebakan[i] = KATATEBAKAN_UNDEF;
                copyKataJawaban[i] = KATAJAWABAN_UNDEF;
            }
        }

        for (int i = 0; copyKataTebakan[i] != '\0'; i++) {
            // mengecek karakter yang ada di kata jawaban namun berada di posisi berbeda
            if (isCharInKata(copyKataTebakan[i], copyKataJawaban)) {
                currentResult[i * 3] = copyKataTebakan[i];
                currentResult[i * 3 + 1] = '*';
                currentResult[i * 3 + 2] = ' ';
                copyKataJawaban[idxCharInKata(copyKataTebakan[i], kataJawaban)] = KATAJAWABAN_UNDEF;

            // karakter tidak berada di kata jawaban
            } else if (!isCharInKata(copyKataTebakan[i], copyKataJawaban) && copyKataTebakan[i] != KATATEBAKAN_UNDEF) { 
                currentResult[i * 3] = copyKataTebakan[i];
                currentResult[i * 3 + 1] = '%';
                currentResult[i * 3 + 2] = ' ';
            }
        }

        currentResult[WORD_LENGTH * 3] = '\0';
        strcopy(results[attempts-1], currentResult); // mengisi hasil dari percobaan saat ini ke hasil semua percobaan

        // untuk memberikan display WORDL399
        for (int i = 0; i < MAX_ATTEMPTS; i++) {
            if (i < attempts) {
                printf("%s\n", results[i]);
            } else {
                printf("_  _  _  _  _\n");
            }
        }

        // bila kata tebakan = kata jawaban
        if (isKataEqual(kataTebakan, kataJawaban)) {
            printf("SELAMAT TEBAKANMU BENAR! +650 RUPIAH TELAH DITAMBAHKAN KE AKUN ANDA!");
            tebakanBenar = true;
        }
    }
    
    // percobaan berakhir dan kata jawaban tidak berhasil ditebak
    if (tebakanBenar == false) {
        printf("BOO! ANDA KALAH\n");
        printf("JAWABAN YANG TEPAT ADALAH ");
        printf("%s", kataJawaban);
    }
}

void tebakAngka(int angkaJawaban) {
    int angkaTebakan;
    boolean tebakanBenar = false;
    int coinHadiah = 600;
    int attempts = 0;

    while (tebakanBenar == false && attempts < 10) {
        printf("Tebak angka: ");
        inputint(&angkaTebakan);
        attempts += 1;
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
    }

    if (tebakanBenar == false) {
        printf("Boo! Anda kalah");
    }
}

void workChallenge() {
    char* kataJawaban;
    int bahasa;
    int pickChallenge;

    srand(time(NULL)); // menetapkan nilai seed dengan waktu yang berubah tiap detik

    printf("Daftar challenge yang tersedia:\n");
    printf("1. Tebak Angka (biaya main=200)\n");   
    printf("2. WORDL399 (biaya main = 500)\n");
    printf("Masukkan challenge yang hendak dimainkan: ");
    inputint(&pickChallenge);
    printf("\n");

    if (pickChallenge == 1) {
        tebakAngka(RNG(1, 100));
    } else if (pickChallenge == 2) {
        printf("KATA TERSEDIA DALAM 2 BAHASA YAITU: \n");
        printf("1. English\n");
        printf("2. Bahasa Indonesia\n");
        printf("PILIH BAHASA DARI KATA YANG INGIN ANDA TEBAK: ");
        inputint(&bahasa);
        printf("\n");
        printf("SELAMAT DATANG DI WORDL3! ANDA MEMILIKI 6 KESEMPATAN UNTUK MENJAWAB DENGAN BENAR!\n");
        if (bahasa == 1) { 
            kataJawaban = listKataInggris[RNG(0,49)];
        } else if (bahasa == 2) {
            kataJawaban = listKataIndo[RNG(0, 49)];
        }   
        for (int i = 0; i < 6; i++) {
            printf("_  _  _  _  _ \n");
        }
        wordl3(kataJawaban);
    }
}