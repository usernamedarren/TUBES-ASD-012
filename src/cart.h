#include <stdio.h>
#include "ADT/map/map.h"
#include "ADT/arraybarang/arraybarang.h"
#include "ADT/mesinkata/mesinkata.h"

void cartAdd (Map *M, char *nama, int kuantitas, ListBarang listb);

void cartRemove (Map *M, char *nama, int kuantitas);

void cartShow (Map M, ListBarang listb);

void cartPay (Map M, ListBarang listb, User *user, Stack riwayat);