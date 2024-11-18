#include "storeList.h"

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
