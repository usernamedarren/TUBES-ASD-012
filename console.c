#include "console.h"
#include <stdio.h>
#include <stdlib.h>

void listStore(ArrayDin A)
{
    if (A.Neff==0)
    {
        printf("Toko kosong\n");
    }
    else
    {
        printf("Daftar barang di toko:\n");
        for (int i=0;i<A.Neff;i++)
        {
            printf("%d. %s Price: %d\n",i+1,A.isi[i].name,A.isi[i].price);
        }
    }
}

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

void supplyStore(ArrayDin *A, Queue *Q)
{
    if (IsEmptyQueue(*Q))
    {
        printf("Tidak ada barang yang perlu ditambahkan\n");
    }
    else
    {
        printf("Apakah kamu ingin menambahkan %s ke dalam toko (terima/tunda/tolak)\n",HEAD(*Q));
        char answer[100];
        scanf("%s",answer);
        if (strcmp(answer, "terima") == 0) 
        {
            int price;
            printf("Harga barang: \n");
            scanf("%d",&price);
            InsertAt(A,HEAD(*Q),Length(*A),price);
            printf("%s dengan harga %d telah ditambahkan ke toko.\n",HEAD(*Q),price);
            dequeue(Q,&answer);
        }
        else if (strcmp(answer, "tunda") == 0)
        {
            printf("%s telah ditunda ke antrian\n",HEAD(*Q));
            dequeue(Q,&answer);
            enqueue(Q,answer);
        }
        else if (strcmp(answer, "tolak") == 0)
        {
            printf("%s telah dihapuskan dari antrian\n",HEAD(*Q));
            dequeue(Q,&answer);
        }
        else
        {
            printf("Input tidak valid\n");
        }
    }
} 

void removeStore(ArrayDin *A)
{
    if (IsEmpty(*A))
    {
        printf("Toko kosong, tidak ada yang dapat dihapus\n");
        return;
    }
    char name[100];
    printf("Nama barang yang ingin dihapus: \n");
    scanf("%s",name);
    for (int i=0;i<A->Neff;i++)
    {
        if (strcmp(A->isi[i].name,name)==0)
        {
            DeleteAt(A,i);
            printf("Barang dengan nama %s telah dihapus\n",name);
            break;
        }
        else if (i==A->Neff-1)
        {
            printf("Barang tidak ditemukan\n");
        }
    }
}

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
