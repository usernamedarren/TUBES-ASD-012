#include "storeRequest.h"
#include <stdio.h>
#include <string.h>

void requestStore(ArrayDin A, Queue *Q) {
    char name[100];
    printf("Nama barang yang diminta: \n");
    scanf("%s", name);
    int found = 0;

    for (int i = 0; i < A.Neff; i++) {
        if (strcmp(A.isi[i].name, name) == 0) {
            enqueue(Q, A.isi[i].name);
            found = 1;
            printf("Barang dengan nama %s telah dimasukkan ke dalam toko\n", name);
            break;
        }
    }

    for (int i = 0; i < LengthQueue(*Q); i++) {
        if (strcmp(Q->Tab[i], name) == 0) {
            found = 1;
            printf("Barang dengan nama %s telah didalam queue\n", name);
            break;
        }
    }

    if (found == 0) {
        enqueue(Q, name);
    }
}