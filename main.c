#include "storeSupply.h"
#include "storeRemove.h"
#include "storeList.h"
#include "storeRequest.h"

int main()
{
    Queue Q; CreateQueue(&Q);
    ArrayDin arr; arr = MakeArrayDin();
    requestStore(arr, &Q);
    supplyStore(&arr, &Q);
    listStore(arr);
    removeStore(&arr);
    listStore(arr);
}