#ifndef WORDL3_H
#define WORDL3_H

#include "boolean.h"
#include "mesinkata.h"
#include "queue.h"
#include "array.h"
#include "RNG.h"

#define LIST_SIZE 50
#define WORD_LENGTH 5
#define KATATEBAKAN_UNDEF '#'
#define KATAJAWABAN_UNDEF ' '

extern Word listKataInggris[LIST_SIZE];
extern Word listKataIndo[LIST_SIZE];


boolean checkSame(Word kataTebakan, Word kataJawaban);
/* Mengecek apakah kataTebakan = kataJawaban */

Word duplicateWord (Word W);
/* Memberikan output duplikat kata W
   I.S. : W terdefinisi dan bisa kosong
   F.S. : Terbentuk kata baru yang merupakan hasil duplikasi kata W*/

boolean isCharIn (char c, Word W);
/* Mengecek apakah karakter c ada di dalam kata W */

boolean isIdxIn (IdxType idx, TabInt idxArr); 
/* Mengecek apakah suatu index terdapat di dalam array yang berisi index
   I.S. : idxArr sembarang
   F.S. : Mengembalikan true jika idx berada di idxArr dan false bila idx tidak ada di idxArr */

void wordl3 (Word kataJawaban);
/* Menjalankan program permainan wordl3, yaitu permainan tebak kata 5 karakter
   Proses: Pemain memiliki 5 (lima) kesempatan untuk menebak kata yang benar. Pada setiap giliran, program akan mencetak ulang kata yang dimasukan, tetapi dengan penanda tertentu. Huruf yang benar dan berada pada tempat yang tepat dicetak biasa. Huruf yang benar, tetapi berada di tempat yang salah diberi tanda '*' setelah hurufnya. Huruf yang tidak ada sama sekali pada kata diberi tanda '%' setelah hurufnya 
   I.S.: KataJawaban berupa kata valid; */

#endif