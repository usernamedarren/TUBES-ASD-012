#include "arrayuser.h"
#include <stdio.h>

void MakeEmpty(ListUser *T) {
    T->Neff = 0; 
}

int NbElmt(ListUser T) {
    return T.Neff;
}

int MaxNbEl() {
    return IdxMax - IdxMin + 1;
}

int GetFirstIdx() {
    return 1;
}

int GetLastIdx(ListUser T) {
    return T.Neff;
}

User GetElmt(ListUser T, int i) {
    return T.TI[i - 1];
}

void SetTab(ListUser Tin, ListUser *Tout) {
    (*Tout).Neff = Tin.Neff;
    for (int i = IdxMin; i <= Tin.Neff; i++) {
        (*Tout).TI[i - 1] = Tin.TI[i - 1];
    }
}

void SetEl(ListUser *T, int i, User v) {
    (*T).TI[i - 1] = v;
    if ((*T).Neff < i) {
        (*T).Neff = i;
    }
}

void SetNeff(ListUser *T, int N) {
    (*T).Neff = N;
}

boolean IsIdxValid (int i){
	if ((i >= IdxMin) && (i <= IdxMax)){
		return true;
	} else {
		return false;
	}
}

boolean IsIdxEff (ListUser T, int i){
	if ((i >= IdxMin) && (i <= T.Neff)){
		return true;
	} else {
		return false;
	}
}

boolean IsUsersEmpty (ListUser T){
	if (T.Neff > 0){
		return false;
	} else {
		return true;
	}
}

boolean IsUsersFull (ListUser T){
	if (T.Neff == IdxMax){
		return true;
	} else {
		return false;
	}
}

void InsertLastUser(ListUser *userlist, User user) {
    if (userlist->Neff < IdxMax) {
        userlist->TI[userlist->Neff] = user; 
        userlist->Neff++;
    } 
}

void DeleteLastUser(ListUser *T){
    if (T->Neff > 0) {
        T->Neff--; 
    } else {
        printf("Error: List kosong.\n");
    }
}