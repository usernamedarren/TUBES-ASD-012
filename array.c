#include <stdio.h>
#include "array.h"
#include "boolean.h"

void MakeEmpty (TabInt *T){
  (*T).Neff = 0;
}

int NbElmt (TabInt T){
  return T.Neff;
}

int MaxNbEl (TabInt T){
  return IdxMax;
}

IdxType GetFirstIdx (TabInt T){
  return IdxMin;
}

IdxType GetLastIdx (TabInt T){
  return T.Neff-1;
}

ElTypeInt GetElmt (TabInt T, IdxType i){
  return T.TI[i];
}

void SetTab (TabInt Tin, TabInt *Tout){
	(*Tout).Neff = Tin.Neff;
  for (int i = GetFirstIdx(Tin); i <= GetLastIdx(Tin); i++) {
		(*Tout).TI[i] = Tin.TI[i];
  }
}

void SetEl (TabInt *T, IdxType i, ElTypeInt v){
	(*T).TI[i] = v;

	if (i >= (*T).Neff) {
    (*T).Neff = i + 1;
  }
}

void SetNeff (TabInt *T, IdxType N){
  (*T).Neff = N;
}


boolean IsIdxValid (TabInt T, IdxType i){
  	return (i >= IdxMin && i <= IdxMax);
}

boolean IsIdxEff (TabInt T, IdxType i){
  	return (i >= GetFirstIdx(T) && i <= GetLastIdx(T));
}

boolean IsEmpty (TabInt T){
  	return (NbElmt(T) == 0);
}

boolean IsFull (TabInt T){
	return (T.Neff == IdxMax);
}

void TulisIsi (TabInt T){
	if(IsEmpty(T)) {
		printf("Tabel kosong\n");
	} else {
		for(int i=GetFirstIdx(T); i <= GetLastIdx(T); i++){
			printf("%d:%d\n", i-1, T.TI[i]);
		}
	}
}

TabInt PlusTab (TabInt T1, TabInt T2){
	TabInt Tout;
	
	Tout.Neff = T1.Neff;

	for(int i=GetFirstIdx(T1); i <= GetLastIdx(T1); i++) {
		Tout.TI[i] = T1.TI[i] + T2.TI[i];
	}

	return Tout;
}

TabInt MinusTab (TabInt T1, TabInt T2){
  TabInt Tout;

	Tout.Neff = T1.Neff;
	for(int i=GetFirstIdx(T1); i < GetLastIdx(T1); i++) {
		Tout.TI[i] = T1.TI[i] - T2.TI[i];
	}

	return Tout;
}


ElTypeInt ValMax (TabInt T){
	ElTypeInt max=T.TI[GetFirstIdx(T)];

	for(int i=GetFirstIdx(T); i <= GetLastIdx(T); i++) {
		if(max < T.TI[i]) {
			max = T.TI[i];
		}
	}
	return max;
}

ElTypeInt ValMin (TabInt T){
	ElTypeInt min=T.TI[GetFirstIdx(T)];

	for(int i=GetFirstIdx(T); i <= GetLastIdx(T); i++) {
		if(min > T.TI[i]) {
			min = T.TI[i];
		}
	}
	return min;
}

IdxType IdxMaxTab (TabInt T){
	for(int i=GetFirstIdx(T); i <= GetLastIdx(T); i++) {
		if(T.TI[i] == ValMax(T)){
			return i;
		}
	}
}

IdxType IdxMinTab (TabInt T){
	for(int i=GetFirstIdx(T); i <= GetLastIdx(T); i++) {
		if(T.TI[i] == ValMin(T)){
			return i;
		}
	}
}