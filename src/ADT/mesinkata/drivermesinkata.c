#include <stdio.h>
#include "mesinkata.h"

int main() {
    // 1. Test ResetCurrentWord
    ResetCurrentWord();
    if (currentWord.Length == 0) {
        printf("berhasil\n");
    } else {
        printf("gagal\n");
    }

    // 2. Test IgnoreBlanks
    char lala[] = " Hello\n";
    START();
    IgnoreBlanks();
    printf("huruf pertama setelah spasi adalah: %c\n", currentChar);

    // 3. Test STARTWORD
    printf("masukkan 2 kata:\n");
    STARTWORD();
    printf("kata pertama ");
    displayWord(currentWord, true);

    // 4. Test ADVWORD
    ADVWORD();
    printf("Kata kedua: ");
    displayWord(currentWord, true);

    // 5. Test CopyWord
    CopyWord();
    printf("kata yang dicopy ");
    displayWord(currentWord, true);

    // 6. Test STARTWORDFILE
    char filename[] = "tes.txt";
    STARTWORDFILE(filename);
    printf("kata pertama dari file ");
    displayWord(currentWord, true);

    // 7. Test ADVWORDFILE
    ADVWORDFILE();
    printf("kata selanjutnya ");
    displayWord(currentWord, true);

    // 8. Test CopyWordBlanks
    printf("Masukkan 2 kata dengan spasi\n");
    START();
    CopyWordBlanks();
    printf("kata yang terbaca ");
    displayWord(currentWord, true);

    // 9. Test isKataEqual
    char kata1[] = "amir";
    char kata2[] = "amir";
    char kata3[] = "ahmad";
    printf("isKataEqual(kata1, kata2): %d\n", isKataEqual(kata1, kata2)); 
    printf("isKataEqual(kata1, kata3): %d\n", isKataEqual(kata1, kata3)); 

    // 10. Test displayWord
    printf("display kata: ");
    displayWord(currentWord, true);

    // 11. Test WordToString
    char kata[100];
    WordToString(currentWord, kata);
    printf("kata yang diconvert %s\n", kata);

    // 12. Test wordtoInt
    Word angka;
    angka.Length = 3;
    angka.TabWord[0] = '1';
    angka.TabWord[1] = '2';
    angka.TabWord[2] = '3';
    int number = wordtoInt(angka);
    printf("angka: ");
    displayWord(angka, true);
    printf("kata yang diconvert: %d\n", number);

    // 13. Test strcopy
    char awal[] = "Hello";
    char copy[100];
    strcopy(copy, awal);
    printf("Source: %s, Destination: %s\n", awal, copy);

    // 14. Test strlength
    char testStr[] = "samuel";
    printf("String: %s, Length: %d\n", testStr, strlength(testStr));

    // 15. Test strconcat
    char concatStr1[100] = "jason";
    char concatStr2[] = " ferro";
    strconcat(concatStr1, concatStr2);
    printf("gabungan string %s\n", concatStr1);

    // 16. Test strcontains
    char mainStr[] = "Hello World";
    char subStr1[] = "World";
    char subStr2[] = "lololo";
    printf("apakah ada %d\n", strcontains(mainStr, subStr1)); 
    printf("apakah ada %d\n", strcontains(mainStr, subStr2)); 
    
    // 17. Test input
    char inputStr[100];
    printf("masukkan string ");
    input(inputStr);
    printf("string yang dimasukkan %s\n", inputStr);

    // 18. Test inputint
    int inputNum;
    printf("masukkan angka ");
    inputint(&inputNum);
    printf("angka yang dimasukkan %d\n", inputNum);

    // 19. Test inputUsernamePassword
    char username[100];
    printf("masukkan password tanpa spasi");
    inputUsernamePassword(username);
    printf("passsword yang dimasukkan %s\n", username);

    return 0;
}
