#include "arrayuser.h"
#include <stdio.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void MakeEmpty(ListUser *T)
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong */
{
    T->Neff = 0; // Set banyak elemen efektif menjadi 0
}	

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmt (ListUser T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
{
	return T.Neff;
}

/* *** Daya tampung container *** */
int MaxNbEl ()
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
	return IdxMax - IdxMin + 1;
}

/* *** Selektor INDEKS *** */
int GetFirstIdx ()
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen pertama */
{
	return 1;
}
int GetLastIdx (ListUser T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */
{
	return T.Neff;
}

/* *** Menghasilkan sebuah elemen *** */
User GetElmt(ListUser T, int i) {
    //printf("DEBUG: Accessing user at index %d\n", i); // Debug tambahan
    if (i >= IdxMin && i <= T.Neff) {
        return T.TI[i - 1]; // Pastikan mengambil elemen dari indeks yang benar
    } else {
        printf("ERROR: Index out of bounds for index %d.\n", i);
        User emptyUser = {"", "", 0}; // Kembalikan user kosong jika indeks salah
        return emptyUser;
    }
}

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
void SetTab (ListUser Tin, ListUser *Tout)
/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */
/* Assignment THsl -> Tin */
{
	(*Tout).Neff = Tin.Neff;
	for(int i = IdxMin; i <= Tin.Neff; i++){
		(*Tout).TI[i] = Tin.TI[i];
	}
}

void SetEl (ListUser *T, int i, User v)
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
{
	(*T).TI[i] = v;
	if ((*T).Neff < i){
		(*T).Neff = i+1;
	}
}

void SetNeff (ListUser *T, int N)
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */
{
	(*T).Neff = N;
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (int i)
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
	if ((i >= IdxMin) && (i <= IdxMax)){
		return true;
	} else {
		return false;
	}
}

boolean IsIdxEff (ListUser T, int i)
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
	if ((i >= IdxMin) && (i <= T.Neff)){
		return true;
	} else {
		return false;
	}
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsUsersEmpty (ListUser T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
	if (T.Neff > 0){
		return false;
	} else {
		return true;
	}
}
/* *** Test tabel penuh *** */
boolean IsUsersFull (ListUser T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
	if (T.Neff == IdxMax){
		return true;
	} else {
		return false;
	}
}

void InsertLastUser(ListUser *userlist, User user) {
    //printf("DEBUG: Current Neff before insert = %d\n", userlist->Neff); // Debug jumlah elemen sebelum insert

    if (userlist->Neff < IdxMax) {
        userlist->TI[userlist->Neff] = user; // Tambahkan elemen di indeks terakhir
        //printf("DEBUG: Adding user at index %d\n", userlist->Neff); // Debug indeks elemen baru
        //printf("DEBUG: User details -> Name: %s, Password: %s, Money: %d\n", user.name, user.password, user.money); // Debug detail user baru

        userlist->Neff++; // Tambahkan jumlah elemen efektif

        //printf("DEBUG: Current Neff after insert = %d\n", userlist->Neff); // Debug jumlah elemen setelah insert
    } else {
        //printf("ERROR: User list is full, cannot add more users.\n");
    }
}


void DeleteLastUser(ListUser *T)
/* I.S. T tidak kosong */
/* F.S. Elemen terakhir dihapus */
{
    if (T->Neff > 0) {
        T->Neff--; // Kurangi jumlah elemen efektif
    } else {
        printf("Error: List kosong.\n");
    }
}