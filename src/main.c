#include "console.h"

int main()
{
    Queue Q; ListBarang B; ListUser U;
    CreateQueue(&Q); MakeListBarang(&B);
    Load("default.txt", &B, &U);
    requestStore(B, &Q);
    bioweapon(&Q, B);
    supplyStore(&B, &Q);
    supplyStore(&B, &Q);
    listStore(B);
    removeStore(&B);
    Save(B, U);
}