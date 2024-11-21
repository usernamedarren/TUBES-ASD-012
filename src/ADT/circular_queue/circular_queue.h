/* MODUL CIRCULAR QUEUE */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi statik */
/* Implementasi Queue menggunakan circular buffer (Alternatif III) */

#ifndef __circular_queue_h__
#define __circular_queue_h__
#include "../../boolean.h"
#include "../str/str.h"
#define IDX_UNDEF -1
#define IDX_MAX 99


/* Definisi tipe elemen dan indeks pada Queue */
typedef char ElTypeChar[100]; // Mengubah tipe elemen menjadi string
typedef int IdxType;

typedef struct {
    ElTypeChar Tab[IDX_MAX + 1]; /* tabel penyimpan elemen */
    IdxType idxHead;         /* indeks elemen paling awal (terdepan) */
    IdxType idxTail;         /* indeks tempat menambah elemen baru */
} Queue;

/* ********* AKSES (Selektor) ********* */
/* Jika q adalah Queue, maka akses elemen : */
#define IDX_HEAD(q) (q).idxHead
#define IDX_TAIL(q) (q).idxTail
#define HEAD(q) (q).Tab[(q).idxHead]
#define TAIL(q) (q).Tab[(q).idxTail]

/* ********* Prototype ********* */
boolean IsEmptyQueue(Queue Q);
/* Mengirim true jika Q kosong */
/* yaitu ketika idxHead=IDX_UNDEF dan idxTail=IDX_UNDEF */
boolean IsFullQueue(Queue Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu ketika idxHead=0 dan idxTail=IDX_MAX atau idxHead=idxTail+1 ketika idxHead > idxTail */
int LengthQueue(Queue Q);
/* Mengirimkan banyaknya elemen Q, 0 jika kosong */
void CreateQueue(Queue *Q);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
void enqueue(Queue *Q, ElTypeChar X);
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, IDX_TAIL "maju" dengan mekanisme circular buffer */
void dequeue(Queue *Q, ElTypeChar *X);
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pada I.S., HEAD "maju" dengan mekanisme circular buffer */
/*      Q mungkin kosong */

#endif 