#include <stdio.h>
#include "circular_queue.h"

int main() {
    Queue q;
    ElTypeString kata1 = "Alstrukdat";
    ElTypeString kata2 = "Keren";
    ElTypeString kata3 = "Banget";
    ElTypeString kata4 = "Kak";
    ElTypeString kataDeq;

    // CreateQueue
    CreateQueue(&q);
    printf("Queue q dibuat\n");

    // IsEmptyQueue
    if (IsEmptyQueue(q)) {
        printf("Queue q kosong\n");
    } else {
        printf("Queue q tidak kosong\n");
    }

    printf("\n");

    // enqueue
    enqueue(&q, kata1); 
    enqueue(&q, kata2);
    enqueue(&q, kata3);
    enqueue(&q, kata4);
    for (int i = 0; i < LengthQueue(q); i++) {
        printf("kata pada indeks %d: %s\n", i, q.Tab[i]);
    } 
    printf("\n");
    printf("Head dari queue q setelah di-enqueue adalah kata %s berada pada indeks ke-%d\n", HEAD(q), IDX_HEAD(q));
    printf("Tail dari queue q setelah di-enqueue adalah kata %s berada pada indeks ke-%d\n", TAIL(q), IDX_TAIL(q));
    printf("\n");
    
    // IsFullQueue
    if (IsFullQueue(q)) {
        printf("Queue q penuh\n");
    } else {
        printf("Queue q tidak penuh dan memiliki panjang %d\n", LengthQueue(q));
    }

    // dequeue
    dequeue(&q, &kataDeq); 
    for (int i = 0; i < LengthQueue(q); i++) {
        printf("kata pada indeks %d: %s\n", i, q.Tab[i]);
    } 
    printf("\n");
    printf("Kata yang di-dequeue adalah %s\n", kataDeq);
    printf("Head dari queue q setelah di-dequeue adalah kata %s berada pada indeks ke-%d\n", HEAD(q), IDX_HEAD(q));
    printf("Tail dari queue q setelah di-dequeue adalah kata %s berada pada indeks ke-%d\n", TAIL(q), IDX_TAIL(q));
    return 0;
}