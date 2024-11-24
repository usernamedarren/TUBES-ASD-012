#ifndef CONSOLE_H
#define CONSOLE_H

#include "ADT/arraybarang/arraybarang.h"
#include "ADT/circular_queue/circular_queue.h"
#include "ADT/mesinkarakter/mesinkarakter.h"
#include "ADT/mesinkata/mesinkata.h"
#include "ADT/arrayuser/arrayuser.h"
#include "ADT/kustom/kustom.h"

#define LIST_SIZE 50
#define MAX_ATTEMPTS 6
#define WORD_LENGTH 5
#define KATATEBAKAN_UNDEF '#'
#define KATAJAWABAN_UNDEF ' '

extern char *listKataInggris[LIST_SIZE];
extern char *listKataIndo[LIST_SIZE];

/* **** GENERAL **** */
/* HELP */
void Help(int menu);

/* QUIT */
void quit(ListBarang itemlist, ListUser userlist);

/* CLEAR TERMINAL */
void clearterminal();

/* WAIT */
void wait ();


/* **** WELCOME MENU **** */
/* START */
void start(ListBarang *itemlist, ListUser *userlist);

/* LOAD */
void Load(char *filename, ListBarang *itemlist, ListUser *userlist, int *bisa);


/* **** LOGIN MENU **** */
/* LOGIN */
void login(ListUser *userlist, int *user_id);

/* REGISTER */
void registeruser(ListUser *userlist);


/* **** MAIN MENU **** */
/* LOGOUT */
void logout(int *user_id, ListUser userlist);

/* WORK */
void work(int user_id, ListUser *userlist);

/* WORK CHALLENGE */
int RNG(int min, int max); /* Mengembalikan angka random dengan rentang min hingga max */
boolean isCharInKata (char c, char *kata); /* Mengecek apakah karakter c ada di dalam kata W */
int idxCharInKata (char c, char *kata);  /* Mengembalikan index ketika ditemukannya c di dalam kata */
void wordl3 (char* kataJawaban, int user_id, ListUser *userlist);
void tebakAngka(int randomNum,int user_id, ListUser *userlist);
void workChallenge(int user_id, ListUser *userlist);

/* STORE LIST */
void listStore(ListBarang A);

/* STORE REQUEST */
void requestStore(ListBarang A, Queue *Q);

/* STORE SUPPLY */
void supplyStore(ListBarang *A, Queue *Q);

/* STORE REMOVE */
void removeStore(ListBarang *A);

/* BIO WEAPON */
void dna_to_rna(char *string);
char* rna_to_protein (char *string,int idx);
void bioweapon(Queue *Q, ListBarang A);

/* SAVE */
void Save(ListBarang itemlist, ListUser userlist);

#endif