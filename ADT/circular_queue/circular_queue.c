#include "circular_queue.h"
#include <stdio.h>

boolean IsEmptyQueue(Queue Q) {
    return (Q.idxHead == IDX_UNDEF && Q.idxTail == IDX_UNDEF);
}

boolean IsFullQueue(Queue Q) {
    return ((Q.idxHead == 0 && Q.idxTail == IDX_MAX) || (Q.idxHead == Q.idxTail + 1));
}

int LengthQueue(Queue Q) {
    if (IsEmptyQueue(Q)) {
        return 0;
    } else if (Q.idxHead <= Q.idxTail) {
        return (Q.idxTail - Q.idxHead + 1);
    } else {
        return (IDX_MAX - Q.idxHead + 1 + Q.idxTail + 1);
    }
}

void CreateQueue(Queue *Q) {
    Q->idxHead = IDX_UNDEF;
    Q->idxTail = IDX_UNDEF;
}

void enqueue(Queue *Q, ElTypeChar X) {
    if (IsEmptyQueue(*Q)) {
        Q->idxHead = 0;
        Q->idxTail = 0;
        strcopy(Q->Tab[Q->idxTail], X);
    } else {
        Q->idxTail = (Q->idxTail + 1) % (IDX_MAX + 1);
        strcopy(Q->Tab[Q->idxTail], X);
    }
}

void dequeue(Queue *Q, ElTypeChar *X) {
    strcopy(*X, Q->Tab[Q->idxHead]);
    if (Q->idxHead == Q->idxTail) {
        Q->idxHead = IDX_UNDEF;
        Q->idxTail = IDX_UNDEF;
    } else {
        Q->idxHead = (Q->idxHead + 1) % (IDX_MAX + 1);
    }
}