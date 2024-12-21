#include "stack.h"
boolean IsEmptyStack(Stack S) {
    return (Top(S) == NilStack);
}

void CreateEmptyStack(Stack *S) {
    Top(*S) = NilStack;
  
}

void PushStack(Stack *S, infotypeStack X) {
    if (IsEmptyStack(*S)) {
        Top(*S) = 0;
    } else {
        Top(*S)++;
    }
    InfoTop(*S) = X;

}

void PopStack(Stack *S, infotypeStack *X) {
    *X = InfoTop(*S);
   
    Top(*S)--;
}