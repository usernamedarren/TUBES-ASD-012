#include "console.h"
#include <stdio.h>
#include <stdlib.h>

void Help(const char *menu) {
    printf("====================Help====================\n");

    if (strcmp(menu, "welcome") == 0) {
        printf("=====[ Welcome Menu Help PURRMART]=====");
        printf("1. START -> Untuk masuk sesi baru\n");
        printf("2. LOAD -> Untuk memulai sesi berdasarkan file konfigurasi\n");
        printf("3. QUIT -> Untuk keluar dari program\n");
    } else if (strcmp(menu, "login") == 0) {
        printf("=====[ Login Menu Help PURRMART]=====");
        printf("1. REGISTER -> Untuk melakukan pendaftaran akun baru\n");
        printf("2. LOGIN -> Untuk masuk ke dalam akun dan memulai sesi\n");
        printf("3. QUIT -> Untuk keluar dari program\n");
    } else if (strcmp(menu, "main") == 0) {
        printf("=====[ Menu Help PURRMART]=====\n");
        printf("1. WORK -> Untuk bekerja\n");
        printf("2. WORK CHALLENGE -> Untuk mengerjakan challenge\n");
        printf("3. STORE LIST -> Untuk melihat barang-barang di toko\n");
        printf("4. STORE REQUEST -> Untuk meminta penambahan barang\n");
        printf("5. STORE SUPPLY -> Untuk menambahkan barang dari permintaan\n");
        printf("6. STORE REMOVE -> Untuk menghapus barang\n");
        printf("7. LOGOUT -> Untuk keluar dari sesi\n");
        printf("8. SAVE -> Untuk menyimpan state ke dalam file\n");
        printf("9. QUIT -> Untuk keluar dari program\n");
    } else {
        printf("Menu tidak dikenali. Harap pilih menu yang valid.\n");
    }
}

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
}

void requestStore(ListBarang A, Queue *Q) {
    char name[100];
    int idx=0;
    printf("Nama barang yang diminta: \n");
    START();
    while (!IsEOP()) {
        name[idx] = GetCC();
        idx++;
        ADV();
    }
    name[idx] = '\0';    
    int found = 0;

    for (int i = 0; i < A.Neff; i++) {
        if (strcmp(A.A[i].name, name) == 0) {
            enqueue(Q, A.A[i].name);
            found = 1;
            printf("Barang dengan nama %s telah dimasukkan ke dalam toko\n", name);
            break;
        }
    }

    for (int i = 0; i < LengthQueue(*Q); i++) {
        if (strcmp(Q->Tab[i], name) == 0) {
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

void supplyStore(ListBarang *A, Queue *Q)
{
    if (IsEmptyQueue(*Q))
    {
        printf("Tidak ada barang yang perlu ditambahkan\n");
    }
    else
    {
        printf("Apakah kamu ingin menambahkan %s ke dalam toko (terima/tunda/tolak)\n", HEAD(*Q));
        char answer[100];
        int idx = 0;
        START();
        while (!IsEOP()) {
            answer[idx] = GetCC();
            idx++;
            ADV();
        }
        answer[idx] = '\0';   
        if (strcmp(answer, "terima") == 0) 
        {
            int price = 0;
            printf("Harga barang:\n");
            START();
            while (!IsEOP()) {
                if (GetCC() >= '0' && GetCC() <= '9') {
                    price = price * 10 + (GetCC() - '0');
                } else {
                    break;
                }
                ADV();
            }
            Barang newBarang; 
            newBarang.harga = price; 
            strcopy(newBarang.name, HEAD(*Q));
            InsertBarangAt(A, newBarang, A->Neff);
            printf("%s dengan harga %d telah ditambahkan ke toko.\n", HEAD(*Q), price);
            dequeue(Q, &answer);
        }
        else if (strcmp(answer, "tunda") == 0)
        {
            printf("%s telah ditunda ke antrian\n", HEAD(*Q));
            dequeue(Q, &answer);
            enqueue(Q, answer);
        }
        else if (strcmp(answer, "tolak") == 0)
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


void removeStore(ListBarang *A)
{
    if (IsBarangEmpty(*A))
    {
        printf("Toko kosong, tidak ada yang dapat dihapus\n");
        return;
    }
    char name[100];
    int idx=0;
    printf("Nama barang yang ingin dihapus: \n");
    START();
    while (!IsEOP()) {
        name[idx] = GetCC();
        idx++;
        ADV();
    }
    name[idx] = '\0';   
    for (int i=0;i<A->Neff;i++)
    {
        if (strcmp(A->A[i].name,name)==0)
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

void bioweapon(Queue *Q) {
    char dna[100],name[100];
    printf("Masukkan nama bioweapon: \n");
    int idx = 0;
    START();
    while (!IsEOP()) {
        name[idx] = GetCC();
        idx++;
        ADV();
    }
    name[idx] = '\0';   
    printf("Masukkan DNA: \n");
    idx = 0;
    START();
    while (!IsEOP()) {
        dna[idx] = GetCC();
        idx++;
        ADV();
    }
    dna[idx] = '\0'; dna_to_rna(dna); char kode[strlength(dna)/3+1];
    printf("Masukkan kode rahasia: \n");
    idx = 0;
    START();
    while (!IsEOP() ) {
        kode[idx] = GetCC();
        idx++;
        ADV();
    }
    kode[idx] = '\0';
    for (int i = 0; i < 3; i++) {
        char *kode2 = rna_to_protein(dna, i);
        if (strcontains(kode,kode2)==0) {
            enqueue(Q,name);
            printf("Bioweapon berhasil dimasukkan ke dalam queue\n");
            free(kode2);
            return;
        }
    }
    printf("Kode rahasia tidak ditemukan, maka senjata biologis sudah disabotase, barang ditolak!\n");
}

void Save(ListBarang itemlist, ListUser userlist) {
    char filename[100];    
    char fullpath[150];    
    int i, idx;            
    boolean success;

    // Meminta input nama file dari pengguna
    printf("Masukkan nama file untuk menyimpan (tanpa folder): ");
    STARTWORD(); 
    for (i = 0; i < currentWord.Length; i++) {
        filename[i] = currentWord.TabWord[i]; 
    }
    filename[currentWord.Length] = '\0'; 

    const char folder[] = "save/";
    idx = 0;
    for (i = 0; i < 5; i++) { 
        fullpath[idx++] = folder[i];
    }
    for (i = 0; filename[i] != '\0'; i++) { 
        fullpath[idx++] = filename[i];
    }
    fullpath[idx] = '\0'; 


    FILE *file = fopen(fullpath, "w");
    if (file == NULL) {
        printf("ERROR: Tidak dapat membuka file %s untuk menyimpan.\n", fullpath);
        return;
    } else {
        //printf("DEBUG: Berhasil membuka file %s untuk ditulis.\n", fullpath);
    }

    fprintf(file, "%d", LengthListBarang(itemlist)); 
    if (LengthListBarang(itemlist) > 0) {
        fprintf(file, "\n"); 
    }

    for (i = 0; i < LengthListBarang(itemlist); i++) {
        Barang item = GetBarang(itemlist, i);
        fprintf(file, "%d %s", item.harga, item.name);
        if (i != LengthListBarang(itemlist) - 1) {
            fprintf(file, "\n"); 
        }
    }

    if (NbElmt(userlist) > 0 && LengthListBarang(itemlist) > 0) {
        fprintf(file, "\n"); 
    }


    fprintf(file, "%d", NbElmt(userlist)); 
    if (NbElmt(userlist) > 0) {
        fprintf(file, "\n"); 
    }

    for (i = 0; i < NbElmt(userlist); i++) {
        User user = GetElmt(userlist, i + 1);
        fprintf(file, "%d %s %s", user.uang, user.name, user.password);
        if (i != NbElmt(userlist) - 1) {
            fprintf(file, "\n"); 
        }
    }

    fclose(file); // Tutup file
    printf("Data berhasil disimpan ke file %s\n", fullpath);
}

void Load(char *filename, ListBarang *itemlist, ListUser *userlist) {
    boolean success;
    STARTFILE(filename, &success);
    if (!success) {
        //printf("ERROR: Failed to open file %s\n", filename);
        return;
    }

    // Baca jumlah items
    CopyWord();
    // printf("DEBUG: Word read for items = ");
    // printw(currentWord, true);

    int jumlahBarang = wordtoInt(currentWord);
    if (jumlahBarang < 0) {
        // printf("ERROR: Invalid item count\n");
        return;
    }
    // printf("DEBUG: Total items = %d\n", jumlahBarang);

    // Parsing items
    for (int i = 0; i < jumlahBarang; i++) {
        ADV(); 
        //printf("DEBUG: EOF reached while reading items.\n");
        ADVWORD();
        int harga = wordtoInt(currentWord);
        if (harga < 0) {
            //printf("ERROR: Invalid harga format at item %d\n", i + 1);
            continue;
        }

        // Baca nama item (bisa memiliki spasi)
        ADVWORD();
        char namaBarang[100];
        int nameLength = 0; // Panjang nama item yang akan ditulis
        for (int j = 0; j < currentWord.Length; j++) {
            namaBarang[nameLength++] = currentWord.TabWord[j];
        }

        while (!EOP && currentChar != '\n') { // Proses nama hingga akhir baris
            namaBarang[nameLength++] = ' '; 
            ADVWORD();
            for (int j = 0; j < currentWord.Length; j++) {
                namaBarang[nameLength++] = currentWord.TabWord[j];
            }
        }
        namaBarang[nameLength] = '\0'; 

        // printf("DEBUG: Loaded item %d: name = %s, harga = %d\n", i + 1, namaBarang, harga);


        Barang barangBaru;
        barangBaru.harga = harga;
        strcopy(barangBaru.name, namaBarang);
        InsertBarangAt(itemlist, barangBaru, i);
    }


    ADV();
    CopyWord();
    // printf("DEBUG: Word read for users = ");

    int jumlahUser = wordtoInt(currentWord);
    if (jumlahUser < 0) {
        // printf("ERROR: Invalid user count\n");
        return;
    }
    // printf("DEBUG: Total users = %d\n", jumlahUser);


    for (int i = 0; i < jumlahUser; i++) {
        ADV(); 

        if (EOP) { 
            //printf("DEBUG: EOF reached while parsing user %d\n", i + 1);
            break;
        }

        ADVWORD();
        int uang = wordtoInt(currentWord);
        if (uang < 0) {
            //printf("ERROR: Invalid uang format for user %d\n", i + 1);
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

        InsertLastUser(userlist, penggunaBaru); // Pastikan pengguna ditambahkan ke list

        // Debugging tambahan
        //printf("DEBUG: Added user %d: Name = %s, Password = %s, Money = %d\n",i + 1, newUser.name, newUser.password, newUser.money);
    }

}