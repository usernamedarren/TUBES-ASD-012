#include "console.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    Queue Q; ListBarang B; ListUser U; CreateQueue(&Q); B=MakeListBarang(); MakeEmpty(&U);
    int menu=1,user_id=-1;
    boolean isCommandHelp = false;
    clearterminal(); 
    printf("      ___         ___         ___         ___         ___         ___         ___      ___      \n"); 
    printf("     /\\  \\       /\\__\\       /\\  \\       /\\  \\       /\\__\\       /\\  \\       /\\  \\    /\\  \\     \n");     
    printf("    /::\\  \\     /:/  /      /::\\  \\     /::\\  \\     /::|  |     /::\\  \\     /::\\  \\   \\:\\  \\    \n");     
    printf("   /:/\\:\\  \\   /:/  /      /:/\\:\\  \\   /:/\\:\\  \\   /:|:|  |    /:/\\:\\  \\   /:/\\:\\  \\   \\:\\  \\   \n");     
    printf("  /::\\~\\:\\  \\ /:/  /  ___ /::\\~\\:\\  \\ /::\\~\\:\\  \\ /:/|:|__|__ /::\\~\\:\\  \\ /::\\~\\:\\  \\  /::\\  \\  \n");     
    printf(" /:/\\:\\ \\:\\__/:/__/  /\\__/:/\\:\\ \\:\\__/:/\\:\\ \\:\\__/:/ |::::\\__/:/\\:\\ \\:\\__/:/\\:\\ \\:\\__\\/:/\\:\\__\\ \n");     
    printf(" \\/__\\:\\/:/  \\:\\  \\ /:/  \\/_|::\\/:/  \\/_|::\\/:/  \\/__/~~/:/  \\/__\\:\\/:/  \\/_|::\\/:/  /:/  \\/__/ \n");
    printf("      \\::/  / \\:\\  /:/  /   |:|::/  /   |:|::/  /      /:/  /     \\::/  /   |:|::/  /:/  /      \n");
    printf("       \\/__/   \\:\\/:/  /    |:|\\/__/    |:|\\/__/      /:/  /      /:/  /    |:|\\/__/\\/__/       \n");
    printf("                \\::/  /     |:|  |      |:|  |       /:/  /      /:/  /     |:|  |              \n");
    printf("                 \\/__/       \\|__|       \\|__|       \\/__/       \\/__/       \\|__|              \n");     
    printf("\n");
    printf("+ ================================================================================================= +\n");
    printf("|                 Selamat datang di PURRMART, sebuah sistem jual beli ke Borma!                     |\n");
    printf("| Ketikkan 'HELP' untuk mendapatkan informasi mengenai apa saja yang bisa Anda lakukan di PURRMART! |\n");
    printf("+ ================================================================================================= +\n");
    while (1)
    {
        if (menu==1)
        {
            printf("Masukkan command (kata langsung/angka): ");
            char command[100];
            input(command);
            if (strcmp(command,"START")==0||strcmp(command,"start")==0||strcmp(command,"1")==0)
            {
                start(&B,&U);
                menu=2;
            }
            else if (strcmp(command,"LOAD")==0||strcmp(command,"load")==0||strcmp(command,"2")==0)
            {
                char filename[100];
                printf("Masukkan nama file: ");
                input(filename);
                int bisa=1;
                Load(filename,&B,&U,&bisa);
                if (bisa==1) 
                {
                    menu=2;
                    printf("File konfigurasi aplikasi berhasil dibaca. PURRMART berhasil dijalankan.\n");}
                else menu=1;
            }
            else if (strcmp(command,"QUIT")==0||strcmp(command,"quit")==0||strcmp(command,"3")==0)
            {
                quit(B,U);
                break;
            } 
            else if (strcmp(command,"HELP")==0||strcmp(command,"help")==0) 
            {
                Help(menu);
                isCommandHelp = true;
            } 
            else {
                printf("command tidak valid\n");
            }
        }

        else if (menu==2)
        {
            printf("Masukkan command (kata langsung/angka): ");
            char command[100];
            input(command);
            if (strcmp(command,"REGISTER")==0||strcmp(command,"register")==0||strcmp(command,"1")==0)
            {
                registeruser(&U);
            }
            else if (strcmp(command,"LOGIN")==0||strcmp(command,"login")==0||strcmp(command,"2")==0)
            {
                login(&U,&user_id);
                if (user_id!=-1) {
                    menu=3;
                }
                else menu=2;
            }
            else if (strcmp(command,"QUIT")==0||strcmp(command,"quit")==0||strcmp(command,"3")==0)
            {
                quit(B,U);
                break;
            }
            else if (strcmp(command,"HELP")==0||strcmp(command,"help")==0) 
            {
                Help(menu);
                isCommandHelp = true;
            }  
            else {
                printf("command tidak valid\n");
            }
        }

        else if (menu==3)
        {
            printf("Masukkan command (kata langsung/angka): ");
            char command[100];
            input(command);
            if (strcmp(command,"WORK")==0||strcmp(command,"work")==0||strcmp(command,"1")==0)
            {
                work(user_id,&U);
            }
            else if (strcmp(command,"WORK CHALLENGE")==0||strcmp(command,"work challenge")==0||strcmp(command,"2")==0)
            {
                workChallenge(user_id,&U);
            }
            else if (strcmp(command,"STORE LIST")==0||strcmp(command,"store list")==0||strcmp(command,"3")==0)
            {
                listStore(B);
            }
            else if (strcmp(command,"STORE REQUEST")==0||strcmp(command,"store request")==0||strcmp(command,"4")==0)
            {
                requestStore(B,&Q);
            }
            else if (strcmp(command,"STORE SUPPLY")==0||strcmp(command,"store supply")==0||strcmp(command,"5")==0)
            {
                supplyStore(&B,&Q);
            }
            else if (strcmp(command,"STORE REMOVE")==0||strcmp(command,"store remove")==0||strcmp(command,"6")==0)
            {
                removeStore(&B);
            }
            else if (strcmp(command,"BIO WEAPON")==0||strcmp(command,"bio weapon")==0||strcmp(command,"7")==0)
            {
                bioweapon(&Q,B);
            }
            else if (strcmp(command,"LOGOUT")==0||strcmp(command,"logout")==0||strcmp(command,"8")==0)
            {
                logout(&user_id,U);
                menu=2;
            }
            else if (strcmp(command,"SAVE")==0||strcmp(command,"save")==0||strcmp(command,"9")==0)
            {
                Save(B,U);
            }
            else if (strcmp(command,"QUIT")==0||strcmp(command,"quit")==0||strcmp(command,"10")==0)
            {
                quit(B,U);
                break;
            } 
            else if (strcmp(command,"HELP")==0||strcmp(command,"help")==0) 
            {
                Help(menu);
                isCommandHelp = true;
            } 
            else {
                printf("command tidak valid\n");
            }
        } 
        if (!isCommandHelp) {
            wait();
            clearterminal(); 
        }
    }
}