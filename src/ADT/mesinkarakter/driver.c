#include <stdio.h>
#include "mesinkarakter.h"

int main() {
    char *inputFile = "default.txt";   
    char *outputFile = "output.txt"; 
    boolean berhasil;

    static FILE *pita = NULL;
    static int retval;

    
    printf("Buka file input\n");
    STARTFILE(inputFile, &berhasil);
    if (berhasil) {
        printf("File '%s' berhasil dibuka\n", inputFile);
        printf("Isi file input:\n");
        while (!IsEOP()) {
            printf("%c", GetCC()); 
            ADV();                 
        }
        printf("\n\n");
    } else {
        printf("File gagal dibuka\n\n", inputFile);
    }

    WRITEFILE(outputFile, &berhasil);
    if (berhasil) {
        printf("file berhasil di-write\n");
        printstring("fufufafafa\n");
        printchar('-');
        printint(182135);
        printf("Data berhasil ditulis ke file '%s'\n", outputFile);
    } else {
        printf("Gagal membuka file '%s' untuk ditulis\n", outputFile);
    }

    if (pita != NULL) {
        fclose(pita);
        pita = NULL;
    }
}
