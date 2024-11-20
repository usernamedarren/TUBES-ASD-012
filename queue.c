#include <stdio.h>
#include "queue.h"

void CreateQueue(Queue *q){
  IDX_HEAD(*q) = IDX_UNDEF;
  IDX_TAIL(*q) = IDX_UNDEF;
}

boolean isEmpty(Queue q){
  return (IDX_HEAD(q) == IDX_UNDEF);
}

boolean isFull(Queue q){
  return ((IDX_TAIL(q)+1)%CAPACITY == IDX_HEAD(q));
}

int length(Queue q){
  if(isEmpty(q)){
    return 0;
  } else{
    if(IDX_TAIL(q) - IDX_HEAD(q) >= 0){
      return (IDX_TAIL(q) - IDX_HEAD(q) + 1);
    } else{
      return (CAPACITY - IDX_HEAD(q) + IDX_TAIL(q) + 1);
    }
  }
}

void enqueue(Queue *q, ElTypeChar val){
  if(isEmpty(*q)){
    IDX_TAIL(*q) = 0;
    IDX_HEAD(*q) = 0;
  } else{
    IDX_TAIL(*q) = (IDX_TAIL(*q) + 1) % CAPACITY;
  }
  TAIL(*q) = val;
}

void dequeue(Queue *q, ElTypeChar *val){

  *val = HEAD(*q);

  if(IDX_HEAD(*q) == IDX_TAIL(*q)){
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
  } else{
    IDX_HEAD(*q) = (IDX_HEAD(*q) + 1) % CAPACITY;
  }
}

void displayQueue(Queue q){
  int currentIdx = IDX_HEAD(q);
  printf("[");
  while(currentIdx != (IDX_TAIL(q) + 1) % CAPACITY){
    if(currentIdx != IDX_TAIL(q)){
      printf("%d,", (q).buffer[currentIdx]);
    } else{
      printf("%d", (q).buffer[currentIdx]);
    }
    currentIdx = (currentIdx + 1) % CAPACITY;
  }
  printf("]\n");
}