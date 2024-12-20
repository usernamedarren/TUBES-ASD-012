#include "../../boolean.h"

#ifndef ARRAY_USER_H
#define ARRAY_USER_H


#include "../kustom/kustom.h"

#define IdxMax 100
#define IdxMin 1
#define IdxUndef -999 

typedef struct
	{
		User TI [IdxMax-IdxMin+1]; 
		int Neff; 
	} ListUser;


void MakeEmpty (ListUser *T);

int NbElmt (ListUser T);

int MaxNbEl ();

int GetFirstIdx ();

int GetLastIdx (ListUser T);

User GetElmt (ListUser T, int i);

void SetTab (ListUser Tin, ListUser *Tout);

void SetEl (ListUser *T, int i, User v);

void SetNeff (ListUser *T, int N);

boolean IsIdxValid (int i);

boolean IsIdxEff (ListUser T, int i);

boolean IsUsersEmpty (ListUser T);

boolean IsUsersFull (ListUser T);

void InsertLastUser(ListUser *userlist, User user);

void DeleteLastUser(ListUser *T);


#endif