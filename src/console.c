#include "console.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *listKataInggris[LIST_SIZE] = {
    "AGENT", "AUDIO", "BLACK", "BUYER", "CRASH", 
    "CLAIM", "DELAY", "ENTRY", "FORTH", "GROUP", 
    "GHOST", "HAPPY", "HORSE", "HEAVY", "IDEAL", 
    "IMAGE", "JUICE", "JUDGE", "KNOWN", "KNEES", 
    "LOCAL", "LOBBY", "MONEY", "MEDIA", "NORTH", 
    "NAILS", "OTHER", "OFTEN", "PAPER", "PLANE", 
    "QUEEN", "RUSTY", "ROUTE", "SNAIL", "SLOTH",  
    "TULIP", "TODAY", "UNDER", "UNION", "VALID",   
    "VALUE", "WATER", "WRONG", "WHALE", "ZEBRA", 
    "EXCEL", "AXIOM", "INDEX", "CRAZE", "DOZER"
};

char *listKataIndo[LIST_SIZE] = {
    "ABSEN", "ATASI", "BENCI", "BUNGA", "CEMAS", 
    "CINTA", "DAPUR", "DOSEN", "EMBER", "GELAS", 
    "HALUS", "HASIL", "INDAH", "INSAN", "JAMUR", 
    "JARAK", "JENUH", "JUMPA", "KECIL", "KERAS", 
    "LEMAK", "LIHAT", "LAMPU", "MERAH", "MENIT", 
    "MOBIL", "NANTI", "NYALA", "ORGAN", "ONCOM", 
    "PAHIT", "PATUH", "PINTA", "RAKIT", "RUSAK", 
    "RINDU", "SAKIT", "SEDIA", "SEMUT", "TANAH",   
    "TELUR", "UJIAN", "GANDA", "GRAHA", "DUNIA", 
    "GITAR", "IRAMA", "HABIS", "ANGIN", "BELAH"
};

Pekerjaan pekerjaan[] = {
    {"Evil Lab Assistant", 100, 14},
    {"OWCA Hiring Manager", 4200, 21},
    {"Cikapundunginator Caretaker", 7000, 30},
    {"Mewing Specialist", 10000, 22},
    {"Inator Connoisseur", 997, 15}
};

/* ************************************************************************************************** */
/* ****************************************** GENERAL *********************************************** */
/* ************************************************************************************************** */

/* HELP */
void Help(int menu) {
    if (menu == 1) {
        printf("+ ============================================================================== +\n");
        printf("|                               WELCOME TO PURRMART                              |\n");
        printf("+ ============================================================================== +\n");
        printf("|  1. [START] -> Untuk masuk sesi baru                                           |\n");
        printf("|  2. [LOAD]  -> Untuk memulai sesi berdasarkan file konfigurasi                 |\n");
        printf("|  3. [QUIT]  -> Untuk keluar dari program                                       |\n");
        printf("+ ============================================================================== +\n");
        printf("|                               WELCOME TO PURRMART                              |\n");
        printf("+ ============================================================================== +\n");
    } else if (menu == 2) {
        printf("+ ============================================================================== +\n");
        printf("|                             PURRMART'S LOGIN MENU                              |\n");
        printf("+ ============================================================================== +\n");
        printf("|  1. [REGISTER] -> Untuk melakukan pendaftaran akun baru                        |\n");
        printf("|  2. [LOGIN]    -> Untuk masuk ke dalam akun dan memulai sesi                   |\n");
        printf("|  3. [QUIT]     -> Untuk keluar dari program                                    |\n");
        printf("+ ============================================================================== +\n");
    } else if (menu == 3) {
        printf("+ ============================================================================== +\n");
        printf("|                             PURRMART'S MAIN MENU                               |\n");
        printf("+ ============================================================================== +\n");
        printf("|  1. [PROFILE]           -> Untuk melihat dan mengedit profil Anda              |\n");
        printf("|  2. [WORK]              -> Untuk bekerja                                       |\n");
        printf("|  3. [WORK CHALLENGE]    -> Untuk mengerjakan challenge                         |\n");
        printf("|  4. [STORE LIST]        -> Untuk melihat barang-barang di toko                 |\n");
        printf("|  5. [STORE REQUEST]     -> Untuk meminta penambahan barang                     |\n");
        printf("|  6. [STORE SUPPLY]      -> Untuk menambahkan barang dari permintaan            |\n");
        printf("|  7. [STORE REMOVE]      -> Untuk menghapus barang                              |\n");
        printf("|  8. [BIO WEAPON]        -> Untuk membuat bioweapon                             |\n");
        printf("|  9. [CART ADD]          -> Untuk menambahkan barang ke keranjang               |\n");
        printf("| 10. [CART REMOVE]       -> Untuk menghapus barang dari keranjang               |\n");
        printf("| 11. [CART SHOW]         -> Untuk menampilkan isi keranjang                     |\n");
        printf("| 12. [CART PAY]          -> Untuk melakukan pembayaran keranjang                |\n");
        printf("| 13. [HISTORY]           -> Untuk melihat riwayat pembelian                     |\n");
        printf("| 14. [WISHLIST ADD]      -> Untuk menambahkan barang ke wishlist                |\n");
        printf("| 15. [WISHLIST SWAP i j] -> Untuk menukar barang di wishlist                    |\n");
        printf("| 16. [WISHLIST REMOVE i] -> Untuk menghapus barang di wishlist sesuai indeks    |\n");
        printf("| 17. [WISHLIST REMOVE]   -> Untuk menghapus barang di wishlist sesuai nama      |\n");
        printf("| 18. [WISHLIST CLEAR]    -> Untuk menghapus semua barang dari wishlist          |\n");
        printf("| 19. [WISHLIST SHOW]     -> Untuk melihat isi wishlist                          |\n");
        printf("| 20. [LOGOUT]            -> Untuk keluar dari sesi                              |\n");
        printf("| 21. [SAVE]              -> Untuk menyimpan state ke dalam file                 |\n");
        printf("| 22. [QUIT]              -> Untuk keluar dari program                           |\n");
        printf("+ ============================================================================== +\n");

    } else if (menu ==4)
    {
        printf("+ ================================================================================================= +\n");
        printf("| Ketikkan 'HELP' untuk mendapatkan informasi mengenai apa saja yang bisa Anda lakukan di PURRMART! |\n");
        printf("+ ================================================================================================= +\n");
    }
}

/* QUIT */
void quit(ListBarang itemlist, ListUser userlist) {
    char answer[100];
    printf("apakah anda ingin menyimpan sesi sekarang? (y/n): ");
    while (1)
    {
        input(answer);
        if (isKataEqual(answer, "y") || isKataEqual(answer, "n"))
        {
            break;
        }
        else
        {
            printf("Input tidak valid\n");
            printf("apakah anda ingin menyimpan sesi sekarang? (y/n): ");
        }
    }
    if (isKataEqual(answer, "y")) {
        char name[50];
        printf("Masukan nama file untuk menyimpan: ");
        input (name);
        Save(itemlist, userlist,name);
    }
    else if (isKataEqual(answer, "n")) {
    }
    printf("Terima kasih telah bermain PURRMART\n");
}

/* CLEAR TERMINAL */
void clearterminal() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

/* WAIT */
void wait() {
    time_t startTime = time(NULL);
    time_t endTime = startTime + 4;
    while (time(NULL) < endTime) {
        if (time(NULL) > startTime) {
            printf(". ");
            fflush(stdout);
            startTime = time(NULL);
        }
    }
    printf("\n");
}


/* ************************************************************************************************** */
/* *************************************** WELCOME MENU ********************************************* */
/* ************************************************************************************************** */

/* START */
void start(ListBarang *itemlist, ListUser *userlist) {
    int bisa=1;
    Load("default.txt", itemlist, userlist, &bisa);
    printf("File konfigurasi aplikasi berhasil dibaca. PURRMART berhasil dijalankan.\n");
}

/* LOAD */
void Load(char *filename, ListBarang *itemlist, ListUser *userlist, int *bisa) {
    boolean success=true;
    STARTFILE(filename, &success);
    if (!success) {
        printf("ERROR: Failed to open file %s\n", filename);
        *bisa = 0;
        return;
    }

    CopyWord();

    int jumlahBarang = wordtoInt(currentWord);
    if (jumlahBarang < 0) {
        return;
    }

    // Handle barang
    for (int i = 0; i < jumlahBarang; i++) {
        ADV(); 

        ADVWORD();
        int harga = wordtoInt(currentWord);
        if (harga < 0) {
            continue;
        }

        ADVWORD();
        char namaBarang[100];
        int nameLength = 0; 
        for (int j = 0; j < currentWord.Length; j++) {
            namaBarang[nameLength++] = currentWord.TabWord[j];
        }

        while (!EOP && currentChar != '\n') { 
            namaBarang[nameLength++] = ' '; 
            ADVWORD();
            for (int j = 0; j < currentWord.Length; j++) {
                namaBarang[nameLength++] = currentWord.TabWord[j];
            }
        }
        namaBarang[nameLength] = '\0'; 

        Barang barangBaru;
        barangBaru.harga = harga;
        strcopy(barangBaru.name, namaBarang);
        InsertBarangAt(itemlist, barangBaru, i);
        *bisa = 1;
    }

    ADV();
    CopyWord();

    int jumlahUser = wordtoInt(currentWord);
    if (jumlahUser < 0) {
        return;
    }

    // Handle user
    for (int i = 0; i < jumlahUser; i++) {
        ADV(); 

        if (EOP) { 
            break;
        }

        ADVWORD();
        int uang = wordtoInt(currentWord);
        if (uang < 0) {
            continue;
        }

        ADVWORD();
        char namapengguna[100];
        WordToString(currentWord, namapengguna);
      
        ADVWORD();
        char password[100];
        WordToString(currentWord, password);

        User penggunaBaru;
        penggunaBaru.uang = uang;
        strcopy(penggunaBaru.name, namapengguna);
        strcopy(penggunaBaru.password, password);

        ADV();
        // Membaca riwayat pembelian (Stack)
        CreateEmptyStack(&penggunaBaru.riwayat_pembelian);
        CreateEmptyMap(&penggunaBaru.keranjang);
        ADVWORD();
        int countRiwayat = wordtoInt(currentWord);
        for (int j = 0; j < countRiwayat; j++) {
            ADV();
            ADVWORD();
            infotypeStack riwayat;
            riwayat.namaBarang = (char*)malloc(100 * sizeof(char)); 
            if (riwayat.namaBarang == NULL) {
                printf("Gagal mengalokasikan memori untuk namaBarang\n");
                return;
            }
            riwayat.totalHarga = wordtoInt(currentWord);
            ADVWORD();
            int nameLength = 0;
            for (int k = 0; k < currentWord.Length; k++) {
                riwayat.namaBarang[nameLength++] = currentWord.TabWord[k];
            }

            while (!EOP && currentChar != '\n') {
                riwayat.namaBarang[nameLength++] = ' ';
                ADVWORD();
                for (int k = 0; k < currentWord.Length; k++) {
                    riwayat.namaBarang[nameLength++] = currentWord.TabWord[k];
                }
            }
            riwayat.namaBarang[nameLength] = '\0'; // Jangan lupa menambahkan karakter null di akhir string

            PushStack(&penggunaBaru.riwayat_pembelian, riwayat);
        }
        ADV();
        // Membaca wishlist (List)
        CreateEmptyList(&penggunaBaru.wishlist);
        ADVWORD();
        int countWishlist = wordtoInt(currentWord);
        for (int j = 0; j < countWishlist; j++) {
            ADV();
            ADVWORD();
            char wishlistItem[100];
            int nameLength = 0;
            for (int k = 0; k < currentWord.Length; k++) {
                wishlistItem[nameLength++] = currentWord.TabWord[k];
            }

            while (!EOP && currentChar != '\n') {
                wishlistItem[nameLength++] = ' ';
                ADVWORD();
                for (int k = 0; k < currentWord.Length; k++) {
                    wishlistItem[nameLength++] = currentWord.TabWord[k];
                }
            }
            wishlistItem[nameLength] = '\0'; 

            InsVLast(&penggunaBaru.wishlist, wishlistItem);
        }

        InsertLastUser(userlist, penggunaBaru);
    }
}
/* ************************************************************************************************** */
/* ***************************************** LOGIN MENU ********************************************* */
/* ************************************************************************************************** */

/* REGISTER */
void registeruser(ListUser *userlist) {
    User newUser;
    printf("username: ");
    inputUsernamePassword(newUser.name);
    printf("password: ");
    inputUsernamePassword(newUser.password);
    for (int i = 0; i < userlist->Neff; i++) 
    {
        if (isKataEqual(userlist->TI[i].name, newUser.name)) 
        {
            printf("Username sudah terdaftar. Silakan gunakan username lain.\n");
            return;
        }
    }
    newUser.uang = 0;
    CreateEmptyList(&newUser.wishlist);
    CreateEmptyStack(&newUser.riwayat_pembelian);
    CreateEmptyMap(&newUser.keranjang);
    InsertLastUser(userlist, newUser);
    printf("Akun dengan username %s telah berhasil dibuat. Silakan LOGIN untuk melanjutkan.\n", newUser.name);
}

/* LOGIN */
void login(ListUser *userlist, int *user_id) {
    if (*user_id != -1) {
        printf("Anda masih tercatat sebagai %s. Silakan LOGOUT terlebih dahulu.\n", userlist->TI[*user_id].name);
        return;
    }
    char username[100], password[100];
    printf("username: ");
    inputUsernamePassword(username);
    for (int i = 0; i < userlist->Neff; i++) {
        if (isKataEqual(userlist->TI[i].name, username)) {
            printf("password: ");
            inputUsernamePassword(password);
            if (isKataEqual(userlist->TI[i].password, password)) {
                printf("Login berhasil. Selamat datang ke PURRMART, %s!\n", username);
                *user_id = i;
                return;
            } else {
                printf("Password salah. Silahkan coba lagi.\n");
                return;
            }
        }
    }
    printf("Username tidak ditemukan. Silakan coba lagi.\n");
}


/* ************************************************************************************************** */
/* ***************************************** MAIN MENU ********************************************* */
/* ************************************************************************************************** */

/* LOGOUT */
void logout(int *user_id, ListUser userlist) {
    if (*user_id == -1) {
        printf("Silahkan LOGIN terlebih dahulu.\n");
        return;
    }
    printf("%s telah logout dari sistem PURRMART. Silakan REGISTER/LOGIN kembali untuk melanjutkan.\n", userlist.TI[*user_id].name);
    *user_id = -1;
}

/* WORK */

void work(int user_id, ListUser *userlist) {

    char inputwork[100];

    printf("Daftar pekerjaan:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d. ", i + 1);
        printf("%s (pendapatan=%d, durasi=%ds)\n",pekerjaan[i].nama,pekerjaan[i].pendapatan,pekerjaan[i].durasi);
    }

    // Memilih pekerjaan
    printf("\nMasukkan pekerjaan yang dipilih: ");
    input(inputwork); 
    boolean jobOngoing = false; 
    for (int i = 0; i < 5; i++) { 
        if (isKataEqual(inputwork, pekerjaan[i].nama)) {
            jobOngoing = true; 
            printf("\nAnda sedang bekerja sebagai ");
            printf("%s", pekerjaan[i].nama);
            printf("... harap tunggu.\n");

            time_t startTime = time(NULL); 
            time_t endTime = startTime + pekerjaan[i].durasi; 
            while (time(NULL) < endTime) {
            }

            printf("Pekerjaan selesai, +%d rupiah telah ditambahkan ke akun Anda.\n", pekerjaan[i].pendapatan);
            userlist->TI[user_id].uang += pekerjaan[i].pendapatan;
            break; 
        }
    }

    for (int i = 0; i < 5; i++) {
        if (inputwork[0] == '1' + i) {
            jobOngoing = true;
            printf("\nAnda sedang bekerja sebagai ");
            printf("%s", pekerjaan[i].nama);
            printf("... harap tunggu.\n");

            time_t startTime = time(NULL);
            time_t endTime = startTime + pekerjaan[i].durasi;
            while (time(NULL) < endTime) {
            }
            printf("Pekerjaan selesai, +%d rupiah telah ditambahkan ke akun Anda.\n", pekerjaan[i].pendapatan);
            userlist->TI[user_id].uang += pekerjaan[i].pendapatan;
            break;
        }
    }

    if (!jobOngoing) {
        printf("\nPekerjaan tidak ditemukan. Pastikan input sesuai dengan daftar pekerjaan.\n");
    }
}

/* WORK CHALLENGE */
int RNG (int min, int max) {
    return(rand() % (max - min + 1) + min);
}

boolean isCharInKata (char c, char *kata) {
    for (int i = 0; kata[i] != '\0'; i++) {
        if (c == kata[i]) {
            return true;
        }
    }
    return false;
}

int idxCharInKata (char c, char *kata) {
    for (int i = 0; kata[i] != '\0'; i++) {
        if (c == kata[i]) {
            return i;
        }
    }
    return -1;
}

void wordl3(char *kataJawaban, int user_id, ListUser *userlist) {
    char kataTebakan[WORD_LENGTH + 1]; // space terakhir untuk \0 sebagai null terminator
    char copyKataTebakan[WORD_LENGTH + 1]; // copyKataTebakan dan copyKataJawaban untuk dimodifikasi nantinya
    char copyKataJawaban[WORD_LENGTH + 1];
    char results[MAX_ATTEMPTS][WORD_LENGTH * 3 + 1]; // menyimpan hasil dari berbagai percobaan
    char currentResult[WORD_LENGTH * 3 + 1]; // menyimpan hasil dari percobaan saat ini
    boolean tebakanBenar = false;
    int attempts = 0;

    while (tebakanBenar == false && attempts < 6) {
        printf("MASUKKAN KATA TEBAKAN ANDA: ");
        input(kataTebakan);
        if (strlength(kataTebakan) == 5) {
            attempts++;
            strcopy(copyKataTebakan, kataTebakan);
            strcopy(copyKataJawaban, kataJawaban); // membuat copyKataJawaban yang nantinya akan di modify
            // mengecek karakter yang berada di posisi sama terlebih dahulu
            for (int i = 0; copyKataTebakan[i] != '\0'; i++) {
                if (copyKataJawaban[i] == copyKataTebakan[i]) {
                    currentResult[i * 3] = kataTebakan[i];
                    currentResult[i * 3 + 1] = ' ';
                    currentResult[i * 3 + 2] = ' '; 
                    copyKataTebakan[i] = KATATEBAKAN_UNDEF;
                    copyKataJawaban[i] = KATAJAWABAN_UNDEF;
                }
            }

            for (int i = 0; copyKataTebakan[i] != '\0'; i++) {
                // mengecek karakter yang ada di kata jawaban namun berada di posisi berbeda
                if (isCharInKata(copyKataTebakan[i], copyKataJawaban)) {
                    currentResult[i * 3] = copyKataTebakan[i];
                    currentResult[i * 3 + 1] = '*';
                    currentResult[i * 3 + 2] = ' ';
                    copyKataJawaban[idxCharInKata(copyKataTebakan[i], kataJawaban)] = KATAJAWABAN_UNDEF;

                // karakter tidak berada di kata jawaban
                } else if (!isCharInKata(copyKataTebakan[i], copyKataJawaban) && copyKataTebakan[i] != KATATEBAKAN_UNDEF) { 
                    currentResult[i * 3] = copyKataTebakan[i];
                    currentResult[i * 3 + 1] = '%';
                    currentResult[i * 3 + 2] = ' ';
                }
            }

            currentResult[WORD_LENGTH * 3] = '\0';
            strcopy(results[attempts-1], currentResult); // mengisi hasil dari percobaan saat ini ke hasil semua percobaan

            // untuk memberikan display WORDL399
            for (int i = 0; i < MAX_ATTEMPTS; i++) {
                if (i < attempts) {
                    printf("%s\n", results[i]);
                } else {
                    printf("_  _  _  _  _\n");
                }
            }

            // bila kata tebakan = kata jawaban
            if (isKataEqual(kataTebakan, kataJawaban)) {
                printf("SELAMAT TEBAKANMU BENAR! +900 RUPIAH TELAH DITAMBAHKAN KE AKUN ANDA!\n");
                tebakanBenar = true;
                userlist->TI[user_id].uang += 900;
            }
        } else {
            printf("Input yang Anda masukkan salah, kata hanya terdiri dari 5 karakter\n");
        }
    }
    
    // percobaan berakhir dan kata jawaban tidak berhasil ditebak
    if (tebakanBenar == false) {
        printf("BOO! ANDA KALAH\n");
        printf("JAWABAN YANG TEPAT ADALAH ");
        printf("%s\n", kataJawaban);
    }
}

void tebakAngka(int angkaJawaban, int user_id, ListUser *userlist) {
    int angkaTebakan;
    boolean tebakanBenar = false;
    int coinHadiah = 600;
    int attempts = 0;

    while (tebakanBenar == false && attempts < 10) {
        printf("Tebak angka: ");
        inputint(&angkaTebakan);
        attempts += 1;
        if (angkaTebakan > angkaJawaban) {
            printf("Tebakanmu lebih besar!\n\n");
            coinHadiah -= 50;
        } else if (angkaTebakan < angkaJawaban) {
            printf("Tebakanmu lebih kecil!\n\n");
            coinHadiah -= 50;
        } else { // Tebakan benar
            printf("Tebakanmu benar! +%d rupiah telah ditambahkan ke akun Anda.\n", coinHadiah);
            tebakanBenar = true;
            userlist->TI[user_id].uang += coinHadiah;
        }
    }

    if (tebakanBenar == false) {
        printf("Boo! Anda kalah");
    }
}

void workChallenge(int user_id, ListUser *userlist) {
    char* kataJawaban;
    int bahasa;
    int pickChallenge;

    srand(time(NULL)); // menetapkan nilai seed dengan waktu yang berubah tiap detik

    printf("Daftar challenge yang tersedia:\n");
    printf("1. Tebak Angka (biaya main=200)\n");   
    printf("2. WORDL399 (biaya main = 500)\n");
    printf("Masukkan challenge yang hendak dimainkan: ");
    inputint(&pickChallenge);

    if (pickChallenge == 1) {
        if (userlist->TI[user_id].uang < 200) {
            printf("Uang Anda tidak cukup untuk bermain challenge ini\n");
            return;
        }
        userlist->TI[user_id].uang -= 200;
        tebakAngka(RNG(1, 100), user_id, userlist);
    } else if (pickChallenge == 2) {
        if (userlist->TI[user_id].uang < 500) {
            printf("Uang Anda tidak cukup untuk bermain challenge ini\n");
            return;
        }
        userlist->TI[user_id].uang -= 500;
        printf("KATA TERSEDIA DALAM 2 BAHASA YAITU: \n");
        printf("1. English\n");
        printf("2. Bahasa Indonesia\n");
        printf("PILIH BAHASA DARI KATA YANG INGIN ANDA TEBAK: ");
        inputint(&bahasa);
        printf("\n");
        printf("SELAMAT DATANG DI WORDL3! ANDA MEMILIKI 6 KESEMPATAN UNTUK MENJAWAB DENGAN BENAR!\n");
        if (bahasa == 1) { 
            kataJawaban = listKataInggris[RNG(0,49)];
        } else if (bahasa == 2) {
            kataJawaban = listKataIndo[RNG(0, 49)];
        }   
        for (int i = 0; i < 6; i++) {
            printf("_  _  _  _  _ \n");
        }
        wordl3(kataJawaban, user_id, userlist);
    }
}

/* STORE LIST */
void listStore(ListBarang A)
{
    if (A.Neff==0)
    {
        printf("Toko kosong\n");
    }
    else
    {
        printf("Daftar barang di toko:\n");
        for (int i=0;i<A.Neff;i++)
        {
            printf("%d. %s Price: %d\n",i+1,A.A[i].name,A.A[i].harga);
        }
    }
    char n[100];
    printf("Tekan karakter apapun untuk melanjutkan: ");
    input(n);
}

/* STORE REQUEST */
void requestStore(ListBarang A, Queue *Q) {
    char name[100];
    printf("Nama barang yang diminta: ");
    input(name);
    int found = 0;

    for (int i = 0; i < A.Neff; i++) {
        if (isKataEqual(A.A[i].name, name) ) {
            found = 1;
            printf("Barang dengan nama %s telah berada dalam toko\n", name);
            break;
        }
    }

    for (int i = 0; i < LengthQueue(*Q); i++) {
        if (isKataEqual(Q->Tab[i], name)) {
            found = 1;
            printf("Barang dengan nama %s telah didalam queue\n", name);
            break;
        }
    }

    if (found == 0) {
        printf("Barang telah masuk ke dalam queue\n");
        enqueue(Q, name);
    }
}

/* SUPPLY STORE */
void supplyStore(ListBarang *A, Queue *Q)
{
    if (IsEmptyQueue(*Q))
    {
        printf("Tidak ada barang yang perlu ditambahkan\n");
    }
    else
    {
        printf("Apakah kamu ingin menambahkan %s ke dalam toko (terima/tunda/tolak): ", HEAD(*Q));
        char answer[100];
        input(answer);  
        if (isKataEqual(answer, "terima")) 
        {
            int price;
            printf("Harga barang: ");
            inputint(&price);
            Barang newBarang; newBarang.harga = price; strcopy(newBarang.name, HEAD(*Q));
            InsertBarangAt(A, newBarang, A->Neff);
            printf("%s dengan harga %d telah ditambahkan ke toko.\n", HEAD(*Q), price);
            dequeue(Q, &answer);
        }
        else if (isKataEqual(answer, "tunda"))
        {
            printf("%s telah ditunda ke antrian\n", HEAD(*Q));
            dequeue(Q, &answer);
            enqueue(Q, answer);
        }
        else if (isKataEqual(answer, "tolak"))
        {
            printf("%s telah dihapuskan dari antrian\n", HEAD(*Q));
            dequeue(Q, &answer);
        }
        else
        {
            printf("Input tidak valid\n");
        }
    }
}

/* STORE REMOVE */
void removeStore(ListBarang *A)
{
    if (IsBarangEmpty(*A))
    {
        printf("Toko kosong, tidak ada yang dapat dihapus\n");
        return;
    }
    printf("Daftar barang di toko:\n");
    for (int i=0;i<A->Neff;i++)
    {
        printf("%d. %s\n",i+1,A->A[i].name);
    }
    printf("Nama barang yang ingin dihapus: ");
    char name[100];
    input(name); 
    for (int i=0;i<A->Neff;i++)
    {
        if (isKataEqual(A->A[i].name,name))
        {
            DeleteBarangAt(A,i);
            printf("Barang dengan nama %s telah dihapus\n",name);
            break;
        }
        else if (i==A->Neff-1)
        {
            printf("Barang tidak ditemukan\n");
        }
    }
}

/* BIO WEAPON */
void dna_to_rna(char *string) {
    for (int i = 0; i < strlength(string); i++) {
        if (string[i] == 'T') {
            string[i] = 'A';
        }
        else if (string[i] == 'A') {
            string[i] = 'U';
        }
        else if (string[i] == 'C') {
            string[i] = 'G';
        }
        else if (string[i] == 'G') {
            string[i] = 'C';
        }
        else {
            string[i] = '-';
        }
    }
}

char* rna_to_protein (char *string, int idx) {
    char *protein = (char *)malloc((strlength(string) / 3 + 1));
    protein[0] = '\0';
    for (int i = 0; i < strlength(string); i += 3) {
        int i1 = (i + idx) % strlength(string);
        int i2 = (i + idx + 1) % strlength(string);
        int i3 = (i + idx + 2) % strlength(string);

        if (string[i1] == 'U') {
            if (string[i2] == 'U') {
                if (string[i3] == 'U' || string[i3] == 'C') {
                    strconcat(protein, "F");
                } else {
                    strconcat(protein, "L");
                }
            } else if (string[i2] == 'C') {
                strconcat(protein, "S");
            } else if (string[i2] == 'A') {
                if (string[i3] == 'U' || string[i3] == 'C') {
                    strconcat(protein, "Y");
                } else {
                    strconcat(protein, "-");
                }
            } else if (string[i2] == 'G') {
                if (string[i3] == 'U' || string[i3] == 'C') {
                    strconcat(protein, "C");
                } else {
                    strconcat(protein, "-");
                }
            }
        } else if (string[i1] == 'C') {
            if (string[i2] == 'U') {
                strconcat(protein, "L");
            } else if (string[i2] == 'C') {
                strconcat(protein, "P");
            } else if (string[i2] == 'A') {
                if (string[i3] == 'U' || string[i3] == 'C') {
                    strconcat(protein, "H");
                } else {
                    strconcat(protein, "Q");
                }
            } else if (string[i2] == 'G') {
                strconcat(protein, "R");
            }
        } else if (string[i1] == 'A') {
            if (string[i2] == 'U') {
                if (string[i3] == 'U' || string[i3] == 'C' || string[i3] == 'A') {
                    strconcat(protein, "I");
                } else {
                    strconcat(protein, "M");
                }
            } else if (string[i2] == 'C') {
                strconcat(protein, "T");
            } else if (string[i2] == 'A') {
                if (string[i3] == 'U' || string[i3] == 'C') {
                    strconcat(protein, "N");
                } else {
                    strconcat(protein, "K");
                }
            } else if (string[i2] == 'G') {
                if (string[i3] == 'U' || string[i3] == 'C') {
                    strconcat(protein, "S");
                } else {
                    strconcat(protein, "R");
                }
            }
        } else if (string[i1] == 'G') {
            if (string[i2] == 'U') {
                strconcat(protein, "V");
            } else if (string[i2] == 'C') {
                strconcat(protein, "A");
            } else if (string[i2] == 'A') {
                if (string[i3] == 'U' || string[i3] == 'C') {
                    strconcat(protein, "D");
                } else {
                    strconcat(protein, "E");
                }
            } else if (string[i2] == 'G') {
                strconcat(protein, "G");
            }
        } else {
            strconcat(protein, "-");
        }
    }
    return protein;
}

void bioweapon(Queue *Q,ListBarang A) {
    char dna[100],name[100];
    printf("Masukkan nama bioweapon: ");
    input(name);
    for (int i=0;i<A.Neff;i++)
    {
        if (isKataEqual(A.A[i].name,name))
        {
            printf("Nama bioweapon telah digunakan\n");
            return;
        }
    }
    for (int i = 0; i < LengthQueue(*Q); i++) {
        if (isKataEqual(Q->Tab[i], name)) {
            printf("Nama bioweapon telah digunakan\n");
            return;
        }
    }
    printf("Masukkan DNA: ");
    input(dna);
    dna_to_rna(dna); char kode[strlength(dna)/3+1];
    printf("Masukkan kode rahasia: ");
    input(kode);
    for (int i = 0; i < 3; i++) {
        char *kode2 = rna_to_protein(dna, i);
        if (strcontains(kode2,kode)) {
            enqueue(Q,name);
            printf("Bioweapon berhasil dimasukkan ke dalam queue\n");
            free(kode2);
            return;
        }
    }
    printf("Kode rahasia tidak ditemukan, maka senjata biologis sudah disabotase, barang ditolak!\n");
}

/* SAVE */
void Save(ListBarang daftarBarang, ListUser daftarPengguna, char *namaFile) {
    boolean success;

    if (!validtxt(namaFile)) {
        printf("File harus berakhir dengan .txt\n");
        return;
    }

    WRITEFILE(namaFile, &success);
    if (!success) {
        printf("ERROR: Gagal membuka file untuk menyimpan.\n");
        return;
    }

    // Menyimpan jumlah barang
    printint(LengthListBarang(daftarBarang));
    if (LengthListBarang(daftarBarang) > 0) {
        printchar('\n'); 
    }

    // Menyimpan data barang
    for (int i = 0; i < LengthListBarang(daftarBarang); i++) {
        Barang barang = GetBarang(daftarBarang, i);
        printint(barang.harga); 
        printchar(' ');        
        printstring(barang.name); 
        if (i != LengthListBarang(daftarBarang) - 1) {
            printchar('\n'); 
        }
    }

    if (LengthListBarang(daftarBarang) > 0 && NbElmt(daftarPengguna) > 0) {
        printchar('\n');
    }

    // Menyimpan jumlah pengguna
    printint(NbElmt(daftarPengguna));
    if (NbElmt(daftarPengguna) > 0) {
        printchar('\n'); 
    }

    // Menyimpan data pengguna
    for (int i = 0; i < NbElmt(daftarPengguna); i++) {
        User pengguna = GetElmt(daftarPengguna, i + 1);
        printint(pengguna.uang); 
        printchar(' ');          
        printstring(pengguna.name); 
        printchar(' ');          
        printstring(pengguna.password); 
        printchar('\n');
        printint(pengguna.riwayat_pembelian.TOP + 1);
        if (pengguna.riwayat_pembelian.TOP + 1 > 0) {
            printchar('\n'); 
        }
        for (int j = 0; j <= pengguna.riwayat_pembelian.TOP; j++) {
            printint(pengguna.riwayat_pembelian.T[j].totalHarga); 
            printchar(' '); 
            printstring(pengguna.riwayat_pembelian.T[j].namaBarang); 
            if (j != pengguna.riwayat_pembelian.TOP) {
                printchar('\n'); 
            }
        }
        printchar('\n');
        printint(NbElmtList(pengguna.wishlist));
        if (NbElmtList(pengguna.wishlist) > 0) {
            printchar('\n'); 
        }
        address_list P = First(pengguna.wishlist);
        while (P != NilList) {
            printstring(Info(P)); 
            if (Next(P) != NilList) {
                printchar('\n'); 
            }
            P = Next(P);
        }
        if (i != NbElmt(daftarPengguna) - 1) {
            printchar('\n'); 
        }
    }

    printf("Data berhasil disimpan ke file %s\n", namaFile);
}

/*===================================================Milestone 2====================================================================*/

void profile (ListUser userlist,int user_id)
{
    
    printf("Nama: %s\n",userlist.TI[user_id].name);
    printf("Uang: %d\n",userlist.TI[user_id].uang);
    printf("Password: ");
    for (int i=0;i<strlength(userlist.TI[user_id].password);i++) printf("*");
    printf("\n"); printf("\n");
    char n[100];
    printf("Apakah anda ingin melihat password? (y/n): "); input(n);
    if (isKataEqual(n,"y"))
    {
        clearterminal();
        artprofile();
        printf("Nama: %s\n",userlist.TI[user_id].name);
        printf("Uang: %d\n",userlist.TI[user_id].uang);
        printf("Password: %s\n",userlist.TI[user_id].password);
    }
}

void history (Stack riwayat, int N) {
    if (N <= 0) {
        printf("Input tidak valid\n");
        return;
    }
    if (IsEmptyStack(riwayat)) {
        printf("Kamu belum membeli barang apapun!\n");
    } else {
        printf("Riwayat pembelian barang: \n");
        if (N > Top(riwayat)+1) {
            N = Top(riwayat)+1;
        }
        Stack s; CreateEmptyStack(&s);
        s=riwayat;
        int i = 0;
        while (!IsEmptyStack(s) && N > 0) {
            infotypeStack X;
            PopStack(&s,&X);
            printf("%d. %s dengan harga %d\n",i+1,X.namaBarang,X.totalHarga);
            i++;
            N--;
        }
        printf("\n");
    }
}

void cartAdd (Map *M, char *nama, int kuantitas, ListBarang B) {
    if (getBarangIndex(B, nama) == -1) {
        printf("Barang tidak ada di toko!\n");
    } else {
        if (IsMemberMap(*M, nama)) {
            int idx = idxMap(*M, nama);
            Elements(*M)[idx].Value += kuantitas;
            printf("Berhasil menambahkan %d %s ke keranjang belanja!\n", kuantitas, nama);
        } else {
            InsertMap(M, nama, kuantitas);
            printf("Berhasil menambahkan %d %s ke keranjang belanja!\n", kuantitas, nama);   
        }
    }
}

void cartRemove (Map *M, char *nama, int kuantitas) {
    if (!IsMemberMap(*M, nama)) {
        printf("Barang tidak ada di keranjang belanja!\n");
    } else {
        int idx = idxMap(*M, nama);
        if (kuantitas > Elements(*M)[idx].Value) {
            printf("Tidak berhasil mengurangi, hanya terdapat %d %s pada keranjang!\n", Elements(*M)[idx].Value, nama);
        } else if (kuantitas < Elements(*M)[idx].Value) {
            Elements(*M)[idx].Value -= kuantitas;
            printf("Berhasil mengurangi %d %s dari keranjang belanja!\n", kuantitas, nama);
        } else { // bila kuantitas barang di keranjang dihapus sepenuhnya
            DeleteMap(M, nama);
            printf("Berhasil mengurangi %d %s dari keranjang belanja!\n", kuantitas, nama);
        }
    }
}

void cartShow (Map M, ListBarang B) {
    if (IsEmptyMap(M)) {
        printf("Keranjang kamu kosong!\n");
    } else {
        printf("Berikut adalah isi keranjangmu.\n");
        int totalHargaCart = 0;
        printf("Kuantitas     Nama                 Total\n");
        for (int i = 0; i < Count(M); i++) {
            int idxBarang = getBarangIndex(B, Elements(M)[i].Key);
            int hargaBarang = B.A[idxBarang].harga;
            int totalHargaBarang = Elements(M)[i].Value*hargaBarang;
            totalHargaCart += totalHargaBarang;
            printf("%-13d %-20s %d\n", Elements(M)[i].Value, Elements(M)[i].Key, totalHargaBarang);
        }
        printf("total biaya yang harus dikeluarkan adalah %d.\n", totalHargaCart);
        char n[100];
        printf("Tekan karakter apapun untuk melanjutkan: "); input(n);
    }
}

boolean lexicalCheck (char *str1, char *str2)
{
    int idx=0;
    char temp1[100],temp2[100];
    strcopy(temp1,str1); strcopy(temp2,str2);
    while (1)
    {   
        if (temp1[idx]=='\0') return 1;
        if (temp2[idx]=='\0') return 0;

        if (temp1[idx]>=65 && temp1[idx]<=90) temp1[idx]+=32;
        if (temp2[idx]>=65 && temp2[idx]<=90) temp2[idx]+=32;

        if (temp1[idx]>temp2[idx]) return 1;
        else if (temp1[idx]==temp2[idx]) idx++;
        else return 0;
    }
}

void cartPay (Map *M, ListBarang B, User *user, Stack *riwayat) {
    if (IsEmptyMap(*M)) {
        printf("Keranjang kamu kosong!\n");
    } else {
        char *confirm;
        int totalHargaCart = 0;
        infotypeStack max_Barang;
        max_Barang.namaBarang=(char*)malloc(100 * sizeof(char)); 
        max_Barang.totalHarga = -1;

        printf("Kamu akan membeli barang-barang berikut.\n");
        printf("Kuantitas     Nama                 Total\n");
        for (int i = 0; i < Count(*M); i++) {
            int idxBarang = getBarangIndex(B, Elements(*M)[i].Key);
            int hargaBarang = B.A[idxBarang].harga;
            int totalHargaBarang = Elements(*M)[i].Value*hargaBarang;
            totalHargaCart += totalHargaBarang;
            if (totalHargaBarang > max_Barang.totalHarga) {
                max_Barang.totalHarga = totalHargaBarang;
                strcopy(max_Barang.namaBarang,Elements(*M)[i].Key);

            } else if (totalHargaBarang==max_Barang.totalHarga)
            {
                if (lexicalCheck(Elements(*M)->Key,max_Barang.namaBarang))
                {
                    max_Barang.totalHarga=totalHargaBarang;
                    strcopy(max_Barang.namaBarang,Elements(*M)[i].Key);         
                }
            }
            printf("%-13d %-20s %d\n", Elements(*M)[i].Value, Elements(*M)[i].Key, totalHargaBarang);
        }

        printf("total biaya yang harus dikeluarkan adalah %d, Apakah Anda jadi membeli?\n", totalHargaCart);
        printf("(Ya/Tidak): ");
        input(confirm);
        printf("\n");

        if (isKataEqual(confirm, "Ya")) {
            if (user->uang < totalHargaCart) {
                printf("Uang kamu hanya %d, tidak cukup untuk membeli barang-barang di keranjang!\n", user->uang);
                
            } else {
                user->uang -= totalHargaCart;
                PushStack(riwayat, max_Barang);
                printf("Selamat kamu telah membeli barang-barang tersebut!\n");
                CreateEmptyMap(M);
            }
        }
    }
}
void wishlistadd(ListUser *userlist, int user_id, ListBarang itemlist)
{
    char name[100];
    printf("Nama barang yang ingin ditambahkan ke WISHLIST: ");
    input(name);
    if (getBarangIndex(itemlist, name) == -1) {
        printf("Tidak ada barang dengan nama %s di toko\n", name);
        return;
    }
    if (SearchList(userlist->TI[user_id].wishlist,name))
    {
        printf("Barang sudah ada di WISHLIST\n");
    }
    else
    {
        InsVLast(&userlist->TI[user_id].wishlist,name);
        printf("%s telah ditambahkan ke WISHLIST\n",name);
    }
}

void wishlistswap(ListUser *userlist , int user_id,int idx1,int idx2)
{
    if (idx1<1 || idx2<1 )
    {
        printf("Penukaran barang gagal dilakukan, input tidak valid\n");
    }
    else if (IsEmptyList(userlist->TI[user_id].wishlist))
    {
        printf("Penukaran barang WISHLIST gagal dilakukan, WISHLIST kosong!\n");
    }
    else if (idx1 > NbElmtList(userlist->TI[user_id].wishlist)||idx2 > NbElmtList(userlist->TI[user_id].wishlist))
    {
        printf("Penukaran barang gagal dilakukan, hanya terdapat %d barang dalam WISHLIST\n",NbElmtList(userlist->TI[user_id].wishlist));
    }
    else
    {
        address_list P1 = First(userlist->TI[user_id].wishlist);
        address_list P2 = First(userlist->TI[user_id].wishlist);
        for (int i=0;i<idx1-1;i++)
        {
            P1 = Next(P1);
        }
        for (int i=0;i<idx2-1;i++)
        {
            P2 = Next(P2);
        }
        infotypelist temp = Info(P1);
        Info(P1) = Info(P2);
        Info(P2) = temp;
        printf("Barang pada posisi ke-%d dan ke-%d telah ditukar\n",idx1,idx2);
    }
}

void wishlistremoveid(ListUser *userlist, int user_id, int posisi)
{
    if (posisi<1)
    {
        printf("Penghapusan barang gagal dilakukan, input tidak valid\n");
    }
    else if (IsEmptyList(userlist->TI[user_id].wishlist))
    {
        printf("Penghapusan barang gagal dilakukan, WISHLIST kosong\n");
    }
    else if(posisi>NbElmtList(userlist->TI[user_id].wishlist))
    {
        printf("Penghapusan barang gagal dilakukan, hanya terdapat %d barang dalam WISHLIST\n",NbElmtList(userlist->TI[user_id].wishlist));
    }
    else if (IsEmptyList(userlist->TI[user_id].wishlist))
    {
        printf("Penghapusan barang WISHLIST gagal dilakukan, WISHLIST kosong!\n");
    }
    else
    {
        address_list P = First(userlist->TI[user_id].wishlist);
        for (int i=0;i<posisi-1;i++)
        {
            P = Next(P);
        }
        DelP(&userlist->TI[user_id].wishlist,Info(P));
        printf("Barang pada posisi ke-%d telah dihapus dari WISHLIST\n",posisi);
    }
}

void wishlistremovename(ListUser *userlist, int user_id)
{
    printf("Nama barang yang ingin dihapus dari WISHLIST: ");
    char name[100]; input(name);
    if (SearchList(userlist->TI[user_id].wishlist,name)!=NilList)
    {
        DelP(&userlist->TI[user_id].wishlist,name);
        printf("%s telah dihapus dari WISHLIST\n",name);
    }
    else
    {
        printf("Penghapusan barang WISHLIST gagal dilakukan, %s tidak ada di WISHLIST!\n",name);
    }
}

void wishlistclear(ListUser *userlist, int user_id)
{
    if (IsEmptyList(userlist->TI[user_id].wishlist))
    {
        printf("WISHLIST sudah kosong\n");
    }
    else
    {
        CreateEmptyList(&userlist->TI[user_id].wishlist);
        printf("WISHLIST telah dikosongkan\n");
    }
}

void wishlistshow(ListUser userlist, int user_id)
{
    if (IsEmptyList(userlist.TI[user_id].wishlist))
    {
        printf("WISHLIST kosong\n");
    }
    else
    {
        PrintInfo(userlist.TI[user_id].wishlist);
        char n[10];
        printf("Tekan karakter apapun untuk melanjutkan: ");
        input(n);
    }
}