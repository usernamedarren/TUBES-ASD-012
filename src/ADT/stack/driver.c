#include "stack.h"
#include <stdio.h>

int main ()
{
    Stack S; CreateEmptyStack (&S);
    infotypeStack X; X.namaBarang="Buku"; X.totalHarga=10000;
    PushStack (&S, X);
    printf("%s\n",InfoTop(S).namaBarang);
    printf("%d\n",InfoTop(S).totalHarga);
    PopStack(&S, &X);
    if (IsEmptyStack(S)) printf("Stack kosong");
}