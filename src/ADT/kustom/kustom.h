#ifndef KUSTOM_H
#define KUSTOM_H

#include <stdio.h>
#include <stdlib.h>


typedef struct {
    char name[100]; // Nama barang
    int price;          // Harga barang
} Barang;

typedef struct {
  char name[100];
  char password[100];
  int money;
} User;

#endif