#include "storeSupply.h"

void supplyStore(ArrayDin *A, Queue *Q)
{
    if (IsEmptyQueue(*Q))
    {
        printf("Tidak ada barang yang perlu ditambahkan\n");
    }
    else
    {
        printf("Apakah kamu inging menambahkan %s ke dalam toko (terima/tunda/tolak)\n",HEAD(*Q));
        char answer[100];
        scanf("%s",answer);
        if (strcmp(answer, "terima") == 0) 
        {
            int price;
            printf("Harga barang: \n");
            scanf("%d",&price);
            InsertAt(A,HEAD(*Q),Length(*A),price);
            dequeue(Q,&answer);
        }
        else if (strcmp(answer, "tunda") == 0)
        {
            dequeue(Q,&answer);
            enqueue(Q,answer);
        }
        else if (strcmp(answer, "tolak") == 0)
        {
            dequeue(Q,&answer);
        }
        else
        {
            printf("Input tidak valid\n");
        }
    }
} 