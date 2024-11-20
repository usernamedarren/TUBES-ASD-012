#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "RNG.h"

int RNG (int min, int max) {
    srand(time(NULL)); // menetapkan nilai seed dengan waktu yang berubah tiap detik
    return(rand() % (max - min + 1) + min); // nilai random berada pada rentang value minimal dan maksimal sesuai yang diinginkan
}