#include "storeRemove.h"

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