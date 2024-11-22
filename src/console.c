#include <stdio.h>
#include <time.h>
#include "console.h"

Pekerjaan kerja[] = {
    {{{"Evil", 4}, {"Lab", 3}, {"Assistant", 9}}, 100, 14},
    {{{"OWCA", 4}, {"Hiring", 6}, {"Manager", 7}}, 4200, 21},
    {{{"Cikapundunginator", 17}, {"Caretaker", 9}}, 7000, 30},
    {{{"Mewing", 6}, {"Specialist", 10}}, 10000, 22},
    {{{"Inator", 6}, {"Connoisseur", 11}}, 997, 15}

};

boolean isWordSame(Word W1, Word W2) {
    if (W1.Length != W2.Length) {
        return false;
    }
    for (int i = 0; i < W1.Length; i++) {
        if (W1.TabWord[i] != W2.TabWord[i]) {
            return false;
        }
    }
    return true;
}

void displayKerja(Pekerjaan Kerja) {
    for (int j = 0; j < 3; j++) {  
        if (Kerja.nama[j].Length == 0) { // bila tidak ada kata berikutnya dari suatu nama pekerjaan
            break;
        } 
        for (int k = 0; k < Kerja.nama[j].Length; k++) {
            printf("%c", Kerja.nama[j].TabWord[k]);
        }
        printf(" ");
    }
}

void work() {
    // Menampilkan daftar pekerjaan
    printf("Daftar pekerjaan:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d. ", i + 1);
        displayKerja(kerja[i]);
        printf("(pendapatan=%d, durasi=%ds)\n", kerja[i].pendapatan, kerja[i].durasi);
    }

    // Memilih pekerjaan
    printf("\nMasukkan pekerjaan yang dipilih: ");
    STARTWORD();
    boolean jobOngoing = false; // Tidak ada pekerjaan yang sedang dilakukan
    for (int i = 0; i < 5; i++) { // Melakukan loop sebanyak jumlah pekerjaan yang ada
        boolean isMatch = true; 
        for (int j = 0; kerja[i].nama[j].Length != 0; j++) { // bila tidak ada kata berikutnya dari suatu nama pekerjaan
            if (!isWordSame(currentWord, kerja[i].nama[j])) {
                isMatch = false; 
                break; // karena kata input tidak sama dengan nama pekerjaan, akan dicek nama pekerjaan berikutnya
            }
            ADVWORD();
        }

    // Melakukan pekerjaan
        if (isMatch) {
            jobOngoing = true; // Bila isMatch == True, maka pekerjaan akan dilakukan
            printf("\nAnda sedang bekerja sebagai ");
            displayKerja(kerja[i]);
            printf("... harap tunggu.\n");

            time_t startTime = time(NULL); // Waktu pekerjaan dimulai
            time_t endTime = startTime + kerja[i].durasi; // Waktu pekerjaan berakhir
            while (time(NULL) < endTime) {
                // Mencontohkan loading
            }

            printf("Pekerjaan selesai, +%d rupiah telah ditambahkan ke akun Anda.\n", kerja[i].pendapatan);
            break; // Berhenti mengecek pekerjaan lainnya
        }
    }

    if (!jobOngoing) {
        printf("\nPekerjaan tidak ditemukan. Pastikan input sesuai dengan daftar pekerjaan.\n");
    }
}