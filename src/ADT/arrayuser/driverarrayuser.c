#include "arrayuser.h"
#include <stdio.h>

int main() {
    ListUser userList;
    MakeEmpty(&userList);


    User akun1 = {"Darren", "Mansyl", 1000};
    InsertLastUser(&userList, akun1);
    printf("User: %s Password: %s Uang: %d\n", akun1.name, akun1.password, akun1.uang);

    User akun2 = {"Adam", "Mirza", 2000};
    InsertLastUser(&userList, akun2);
    printf("User: %s Password: %s Uang: %d\n", akun2.name, akun2.password, akun2.uang);

    printf("Banyak akun sekarang: %d\n", NbElmt(userList));

 
    User firstUser = GetElmt(userList, GetFirstIdx());
    printf("Akun Pertama ditambahkan: User: %s, Uang: %d\n", firstUser.name, firstUser.uang);

    User lastUser = GetElmt(userList, GetLastIdx(userList));
    printf("Akun Terakhir ditambahkan: User: %s, Uang: %d\n", lastUser.name, lastUser.uang);


    DeleteLastUser(&userList);
    printf("Akun dihapus\n");


    printf("Banyak akun setelah dihapus %d\n", NbElmt(userList));


    if (IsUsersEmpty(userList)) {
        printf("ListUser kosong.\n");
    } else {
        printf("ListUser tidak kosong.\n");
    }


    if (IsUsersFull(userList)) {
        printf("ListUser full\n");
    } else {
        printf("ListUser tidak full\n");
    }

    return 0;
}
