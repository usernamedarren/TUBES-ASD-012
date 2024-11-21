#include "console.h"

int main()
{
    Queue Q; CreateQueue(&Q);
    ArrayDin arr; arr = MakeArrayDin();
    requestStore(arr, &Q);
    bioweapon(&Q);
    supplyStore(&arr, &Q);
    supplyStore(&arr, &Q);
    listStore(arr);
    removeStore(&arr);
    listStore(arr);
}