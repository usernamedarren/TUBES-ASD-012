#ifndef KUSTOM_H
#define KUSTOM_H

#include "../map/map.h"
#include "../stack/stack.h"
#include "../listlinier/listlinier.h"

typedef struct {
  char name[100];
  int harga;
} Barang;

typedef struct {
  char name[100];
  char password[100];
  int uang;
  Map keranjang;
  Stack riwayat_pembelian;
  List wishlist;
} User;

typedef struct {
    char nama[100]; 
    int pendapatan;
    int durasi;
} Pekerjaan;

#endif