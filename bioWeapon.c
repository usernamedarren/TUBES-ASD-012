#include "bioWeapon.h"

void dna_to_rna(char *string) {
    for (int i = 0; i < strlength(string); i++) {
        if (string[i] == 'T') {
            string[i] = 'A';
        }
        else if (string[i] == 'A') {
            string[i] = 'U';
        }
        else if (string[i] == 'C') {
            string[i] = 'G';
        }
        else if (string[i] == 'G') {
            string[i] = 'C';
        }
    }
}

char* rna_to_protein (char *string, int idx) {
    char *protein = (char *)malloc((strlength(string) / 3 + 1));
    protein[0] = '\0';
    for (int i = 0; i < strlength(string); i += 3) {
        int i1 = (i + idx) % strlength(string);
        int i2 = (i + idx + 1) % strlength(string);
        int i3 = (i + idx + 2) % strlength(string);

        if (string[i1] == 'U') {
            if (string[i2] == 'U') {
                if (string[i3] == 'U' || string[i3] == 'C') {
                    strconcat(protein, "F");
                } else {
                    strconcat(protein, "L");
                }
            } else if (string[i2] == 'C') {
                strconcat(protein, "S");
            } else if (string[i2] == 'A') {
                if (string[i3] == 'U' || string[i3] == 'C') {
                    strconcat(protein, "Y");
                } else {
                    strconcat(protein, "-");
                }
            } else if (string[i2] == 'G') {
                if (string[i3] == 'U' || string[i3] == 'C') {
                    strconcat(protein, "C");
                } else {
                    strconcat(protein, "-");
                }
            }
        } else if (string[i1] == 'C') {
            if (string[i2] == 'U') {
                strconcat(protein, "L");
            } else if (string[i2] == 'C') {
                strconcat(protein, "P");
            } else if (string[i2] == 'A') {
                if (string[i3] == 'U' || string[i3] == 'C') {
                    strconcat(protein, "H");
                } else {
                    strconcat(protein, "Q");
                }
            } else if (string[i2] == 'G') {
                strconcat(protein, "R");
            }
        } else if (string[i1] == 'A') {
            if (string[i2] == 'U') {
                if (string[i3] == 'U' || string[i3] == 'C' || string[i3] == 'A') {
                    strconcat(protein, "I");
                } else {
                    strconcat(protein, "M");
                }
            } else if (string[i2] == 'C') {
                strconcat(protein, "T");
            } else if (string[i2] == 'A') {
                if (string[i3] == 'U' || string[i3] == 'C') {
                    strconcat(protein, "N");
                } else {
                    strconcat(protein, "K");
                }
            } else if (string[i2] == 'G') {
                if (string[i3] == 'U' || string[i3] == 'C') {
                    strconcat(protein, "S");
                } else {
                    strconcat(protein, "R");
                }
            }
        } else if (string[i1] == 'G') {
            if (string[i2] == 'U') {
                strconcat(protein, "V");
            } else if (string[i2] == 'C') {
                strconcat(protein, "A");
            } else if (string[i2] == 'A') {
                if (string[i3] == 'U' || string[i3] == 'C') {
                    strconcat(protein, "D");
                } else {
                    strconcat(protein, "E");
                }
            } else if (string[i2] == 'G') {
                strconcat(protein, "G");
            }
        }
    }
    return protein;
}

void bioweapon(Queue *Q) {
    char dna[100],name[100];
    printf("Masukkan nama bioweapon: \n");
    scanf("%s",name);
    printf("Masukkan DNA: \n");
    scanf("%s",dna);
    dna_to_rna(dna);
    char kode[strlength(dna)/3+1];
    printf("Kode rahasia: \n");
    scanf("%s",kode);
    for (int i = 0; i < 3; i++) {
        char *kode2 = rna_to_protein(dna, i);
        if (strcontains(kode,kode2)==0) {
            enqueue(Q,name);
            printf("Bioweapon berhasil dimasukkan ke dalam queue\n");
            free(kode2);
            return;
        }
    }
    printf("Kode rahasia tidak ditemukan, maka senjata biologis sudah disabotase, barang ditolak!\n");
}
