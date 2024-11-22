#include <stdio.h>
#include "mesinkata.h"

boolean EndWord;
Word CurrentWord;

void IgnoreBlanks(){
  while((currentChar==BLANK) && (currentChar!=MARK)){
    ADV();
  }
}

void STARTWORD(){
  START();
  IgnoreBlanks();
  if (currentChar==MARK){
      EndWord = true;
  }
  else{
      EndWord = false;
      CopyWord();
  }
}

void ADVWORD(){
  IgnoreBlanks();
  if (currentChar==MARK){
      EndWord = true;
  }
  else{
      EndWord = false;
      CopyWord();
  }
}

void CopyWord(){
  int i = 0;
  while ((currentChar != BLANK) && (currentChar != MARK) && (i < NMax)){
      CurrentWord.TabWord[i]=currentChar;
      ADV();
      i++;
  }
  CurrentWord.Length = i;
}