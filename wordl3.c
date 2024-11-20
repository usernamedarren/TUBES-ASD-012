#include <stdio.h>
#include "wordl3.h"

Word listKataInggris[LIST_SIZE] = {
    {"AGENT", 5}, {"AUDIO", 5}, {"BLACK", 5}, {"BUYER", 5}, {"CRASH", 5}, 
    {"CLAIM", 5}, {"DELAY", 5}, {"ENTRY", 5}, {"FORTH", 5}, {"GROUP", 5}, 
    {"GHOST", 5}, {"HAPPY", 5}, {"HORSE", 5}, {"HEAVY", 5}, {"IDEAL", 5}, 
    {"IMAGE", 5}, {"JUICE", 5}, {"JUDGE", 5}, {"KNOWN", 5}, {"KNEES", 5}, 
    {"LOCAL", 5}, {"LOBBY", 5}, {"MONEY", 5}, {"MEDIA", 5}, {"NORTH", 5}, 
    {"NAILS", 5}, {"OTHER", 5}, {"OFTEN", 5}, {"PAPER", 5}, {"PLANE", 5}, 
    {"QUEEN", 5}, {"RUSTY", 5}, {"ROUTE", 5}, {"SNAIL", 5}, {"SLOTH", 5},  
    {"TULIP", 5}, {"TODAY", 5}, {"UNDER", 5}, {"UNION", 5}, {"VALID", 5},   
    {"VALUE", 5}, {"WATER", 5}, {"WRONG", 5}, {"WHALE", 5}, {"ZEBRA", 5}, 
    {"EXCEL", 5}, {"AXIOM", 5}, {"INDEX", 5}, {"CRAZE", 5}, {"DOZER", 5} 
};

Word listKataIndo[LIST_SIZE] = {
    {"ABSEN", 5}, {"ATASI", 5}, {"BENCI", 5}, {"BUNGA", 5}, {"CEMAS", 5}, 
    {"CINTA", 5}, {"DAPUR", 5}, {"DOSEN", 5}, {"EMBER", 5}, {"GELAS", 5}, 
    {"HALUS", 5}, {"HASIL", 5}, {"INDAH", 5}, {"INSAN", 5}, {"JAMUR", 5}, 
    {"JARAK", 5}, {"JENUH", 5}, {"JUMPA", 5}, {"KECIL", 5}, {"KERAS", 5}, 
    {"LEMAK", 5}, {"LIHAT", 5}, {"LAMPU", 5}, {"MERAH", 5}, {"MENIT", 5}, 
    {"MOBIL", 5}, {"NANTI", 5}, {"NYALA", 5}, {"ORGAN", 5}, {"ONCOM", 5}, 
    {"PAHIT", 5}, {"PATUH", 5}, {"PINTA", 5}, {"RAKIT", 5}, {"RUSAK", 5}, 
    {"RINDU", 5}, {"SAKIT", 5}, {"SEDIA", 5}, {"SEMUT", 5}, {"TANAH", 5},   
    {"TELUR", 5}, {"UJIAN", 5}, {"GANDA", 5}, {"GRAHA", 5}, {"DUNIA", 5}, 
    {"GITAR", 5}, {"IRAMA", 5}, {"HABIS", 5}, {"ANGIN", 5}, {"BELAH", 5} 
};

boolean checkSame(Word kataTebakan, Word kataJawaban) {
    int count = 0;
    for (int i = 0; i < WORD_LENGTH; i++) {
        if (kataTebakan.TabWord[i] == kataJawaban.TabWord[i]) {
            count++;
        }
    }

    if (count == 5) {
        return true;
    } else {
        return false; 
    }
} 

boolean isCharIn (char c, Word W) {
    for (int i = 0; i < WORD_LENGTH; i++) {
        if (c == W.TabWord[i]) {
            return true;
        }
    }
    return false;
}

boolean isIdxIn (IdxType idx, TabInt idxArr) {
    for (int i = 0; i < NbElmt(idxArr); i++) {
        if (idx == idxArr.TI[i]) {
            return true;
        }
    }
    return false;
}

int indexIsCharIn (char c, Word W) {
    for (int i = 0; i < WORD_LENGTH; i++) {
        if (c == W.TabWord[i]) {
            return i;
        }
    }
    return -1;
}

Word duplicateWord (Word W) {
    Word duplicateKata;

    duplicateKata.Length = W.Length;
    for (int i = 0; i < W.Length; i++) {
        duplicateKata.TabWord[i] = W.TabWord[i];
    }

    return(duplicateKata);
}

void wordl3(Word kataJawaban) {
    Word copyKataJawaban;
    Word kataTebakan;
    Word copyKataTebakan;
    TabInt karakterFormat;
    TabInt simbolFormat;
    TabInt idxArray;
    Queue hasilFormat;
    IdxType countIdx;
    int jumlahTebakan = 0;
    boolean tebakanBenar = false;

    CreateQueue (&hasilFormat);
    while (tebakanBenar == false && jumlahTebakan < 6) {
        countIdx = 0;
        MakeEmpty(&idxArray);
        MakeEmpty(&karakterFormat);  
        MakeEmpty(&simbolFormat);
        copyKataJawaban = duplicateWord(kataJawaban);
        printf("Masukkan kata tebakan Anda: ");
        kataTebakan.Length = WORD_LENGTH;

        for (int i = 0; i < WORD_LENGTH; i++) {
            scanf(" %c", &kataTebakan.TabWord[i]);  
        } 

        copyKataTebakan = duplicateWord(kataTebakan);

        for (int i = 0; i < WORD_LENGTH; i++) {
            if (copyKataTebakan.TabWord[i] == copyKataJawaban.TabWord[i]) {
                SetEl(&karakterFormat, i, kataTebakan.TabWord[i]);
                SetEl(&simbolFormat, i, ' ');
                copyKataTebakan.TabWord[i] = KATATEBAKAN_UNDEF;
                copyKataJawaban.TabWord[i] = KATAJAWABAN_UNDEF;
                SetEl(&idxArray, countIdx, i);
                countIdx++;
            }
        }

        for (int i = 0; i < WORD_LENGTH; i++) {
            if (!isIdxIn(i, idxArray)) {
                SetEl(&karakterFormat, i, kataTebakan.TabWord[i]);
                if (isCharIn(copyKataTebakan.TabWord[i], copyKataJawaban)) {
                    SetEl(&simbolFormat, i, '*');
                    copyKataJawaban.TabWord[indexIsCharIn(copyKataTebakan.TabWord[i], copyKataJawaban)] = KATAJAWABAN_UNDEF;
                } else {
                    SetEl(&simbolFormat, i, '%');
                }
            }
        }
        jumlahTebakan++;

        for (int i = 0; i < WORD_LENGTH; i++) {
            enqueue(&hasilFormat, karakterFormat.TI[i]);
            enqueue(&hasilFormat, simbolFormat.TI[i]);
            enqueue(&hasilFormat, ' ');
        }
        
        printf("\nHasil tebakan:\n");
        int count = 0;
        for (int i = 0; i < length(hasilFormat); i++) {
            printf("%c", hasilFormat.buffer[i]);
            count++;
            if (count % 15 == 0 && count != 0 && count != length(hasilFormat)) {
                printf("\n");
            }
        }
        printf("\n");

        for (int i = jumlahTebakan; i < 6; i++) {
            printf("_  _  _  _  _ \n");
        }

        if (checkSame(kataTebakan, kataJawaban)) {
            tebakanBenar = true;
        }
    }

    if (checkSame(kataTebakan, kataJawaban)) {
        printf("SELAMAT TEBAKANMU BENAR! +650 RUPIAH TELAH DITAMBAHKAN KE AKUN ANDA!");
    } else {
        printf("BOO! ANDA KALAH\n");
        printf("JAWABAN YANG TEPAT ADALAH ");
        for (int i = 0; i < WORD_LENGTH; i++) {
            printf("%c", kataJawaban.TabWord[i]);
        }
    }
}
