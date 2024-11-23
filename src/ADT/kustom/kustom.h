#ifndef KUSTOM_H
#define KUSTOM_H

typedef struct {
  char name[100];
  int harga;
} Barang;

typedef struct {
  char name[100];
  char password[100];
  int uang;
} User;

typedef struct {
    char nama[100]; /* container penyimpan nama pekerjaan, indeks yang dipakai [0..NMax-1] */
    int pendapatan;
    int durasi;
} Pekerjaan;

#endif