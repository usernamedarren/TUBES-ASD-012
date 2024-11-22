#ifndef CONSOLE_H
#define CONSOLE_H

#include "boolean.h"
#include "ADT/mesinkar/mesinkarakter.h"
#include "ADT/mesinkata/mesinkata.h"
#include "ADT/queueChar/queueChar.h"
#include "ADT/array/array.h"
#include "ADT/str/str.h"

#define LIST_SIZE 50
#define MAX_ATTEMPTS 6
#define WORD_LENGTH 5
#define KATATEBAKAN_UNDEF '#'
#define KATAJAWABAN_UNDEF ' '

extern char listKataInggris[LIST_SIZE] [WORD_LENGTH];
extern char listKataIndo[LIST_SIZE] [WORD_LENGTH];

int RNG(int min, int max);
/* Mengembalikan angka random dengan rentang di antara min dan max */

int charToInt (char c);
/* Melakukan casting sebuah char menjadi int */

boolean isCharIn (char c, char *kata);
/* Mengecek apakah karakter c ada di dalam kata W */

void wordl3 (char* kataJawaban);
/* Menjalankan program permainan wordl3, yaitu permainan tebak kata 5 karakter
   Proses: Pemain memiliki 5 (lima) kesempatan untuk menebak kata yang benar. Pada setiap giliran, program akan mencetak ulang kata yang dimasukan, tetapi dengan penanda tertentu. Huruf yang benar dan berada pada tempat yang tepat dicetak biasa. Huruf yang benar, tetapi berada di tempat yang salah diberi tanda '*' setelah hurufnya. Huruf yang tidak ada sama sekali pada kata diberi tanda '%' setelah hurufnya 
   I.S.: KataJawaban berupa kata valid; */

void tebakAngka(int randomNum);
/* Challenge Tebak Angka merupakan permainan yang meminta pemain menebak sebuah angka yang ditentukan oleh program.
Proses: Pemain memiliki 10 (sepuluh) kesempatan untuk menebak angka yang benar. Program akan memberikan feedback apakah angka tebakan lebih besar, lebih kecil, atau sama dengan angka target. Jumlah kesempatan yang dipakai oleh pengguna akan mengurangi uang hadiah yang didapatkan. */

void workChallenge();
/* Pemain membutuhkan uang dengan jumlah tertentu untuk bisa memainkan challenge. Uang yang dibayarkan untuk bermain challenge tidak akan dikembalikan, meskipun pemain kalah dalam permainan. Terdapat dua challenge yang dapat dipilih yaitu tebak angka & wordl3 */


#endif