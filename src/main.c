#include "console.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    Queue Q; ListBarang B; ListUser U; CreateQueue(&Q); B=MakeListBarang(); MakeEmpty(&U);
    int menu=1,user_id=-1;
    boolean isCommandHelp = false;
    int helpInstructed = 4;         
    printf("+ ================================================================================================= +\n");
    printf("|                 Selamat datang di PURRMART, sebuah sistem jual beli ke Borma!                     |\n");
    printf("+ ================================================================================================= +\n");
    printf("      ___         ___           ___           ___           ___           ___           ___            ___                            \n"); 
    printf("     /  /\\       /__/\\         /  /\\         /  /\\         /__/\\         /  /\\         /  /\\          /  /\\                   \n");     
    printf("    /  /::\\      \\  \\:\\       /  /::\\       /  /::\\       |  |::\\       /  /::\\       /  /::\\        /  / /                  \n");     
    printf("   /  /:/\\:\\      \\  \\:\\     /  /:/\\:\\     /  /:/\\:\\      |  |:|:\\     /  /:/\\:\\     /  /:/\\:\\      /  /:/              \n");     
    printf("  /  /:/~/:/  ___  \\  \\:\\   /  /:/~/:/    /  /:/~/:/    __|__|:|\\:\\   /  /:/~/::\\   /  /:/~/:/     /  /:/                       \n");     
    printf(" /__/:/ /:/  /__/\\  \\__\\:\\ /__/:/ /:/___ /__/:/ /:/___ /__/::::| \\:\\ /__/:/ /:/\\:\\ /__/:/ /:/___  /  /::\\                    \n");     
    printf(" \\  \\:\\/:/   \\  \\:\\ /  /:/ \\  \\:\\/:::::/ \\  \\:\\/:::::/ \\  \\:\\~~\\__\\/ \\  \\:\\/:/__\\/ \\  \\:\\/:::::/ /__/:/\\:\\  \n");
    printf("  \\  \\::/     \\  \\:\\  /:/   \\  \\::/~~~~   \\  \\::/~~~~   \\  \\:\\        \\  \\::/       \\  \\::/~~~~  \\__\\/  \\:\\       \n");
    printf("   \\  \\:\\      \\  \\:\\/:/     \\  \\:\\        \\  \\:\\        \\  \\:\\        \\  \\:\\        \\  \\:\\           \\  \\:\\  \n");
    printf("    \\  \\:\\      \\  \\::/       \\  \\:\\        \\  \\:\\        \\  \\:\\        \\  \\:\\        \\  \\:\\           \\  \\:\\  \n");
    printf("     \\__\\/       \\__\\/         \\__\\/         \\__\\/         \\__\\/         \\__\\/         \\__\\/            \\__\\/         \n");     
    printf("\n");
    while (1)
    {
        isCommandHelp = false;
        if (menu==1)
        {
            Help(helpInstructed);
            helpInstructed = 4;
            printf("\n");
            printf("Masukkan command (kata langsung/angka): ");
            char command[100];
            input(command);
            if (isKataEqual(command, "START") || isKataEqual(command,"start") || isKataEqual(command,"1"))
            {
                start(&B,&U);
                menu=2;
            }
            else if (isKataEqual(command,"LOAD") || isKataEqual(command,"load") || isKataEqual(command,"2"))
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
            else if (isKataEqual(command,"QUIT") || isKataEqual(command,"quit") || isKataEqual(command,"3"))
            {
                quit(B,U);
                break;
            } 
            else if (isKataEqual(command,"HELP") || isKataEqual(command,"help")) 
            {
                clearterminal();
                Help(menu);
                isCommandHelp = true;
                helpInstructed = -1;
            } 
            else {
                printf("command tidak valid\n");
            }
        }

        else if (menu==2)
        {
            Help(helpInstructed);
            helpInstructed = 4;
            printf("\n");
            printf("Masukkan command (kata langsung/angka): ");
            char command[100];
            input(command);
            if (isKataEqual(command,"REGISTER") || isKataEqual(command,"register") || isKataEqual(command,"1"))
            {
                registeruser(&U);
            }
            else if (isKataEqual(command,"LOGIN") || isKataEqual(command,"login") || isKataEqual(command,"2"))
            {
                login(&U,&user_id);
                if (user_id!=-1) {
                    menu=3;
                }
                else menu=2;
            }
            else if (isKataEqual(command,"QUIT") || isKataEqual(command,"quit") || isKataEqual(command,"3"))
            {
                quit(B,U);
                break;
            }
            else if (isKataEqual(command,"HELP") || isKataEqual(command,"help")) 
            {
                clearterminal();
                Help(menu);
                isCommandHelp = true;
                helpInstructed = -1;
            }  
            else {
                printf("command tidak valid\n");
            }
        }

        else if (menu==3)
        {
            Help(helpInstructed);
            helpInstructed = 4;
            printf("\n");
            printf("Masukkan command (kata langsung/angka): ");
            char command[100];
            input(command);
            if (isKataEqual(command,"WORK") || isKataEqual(command,"work") || isKataEqual(command,"1"))
            {
                work(user_id,&U);
            }
            else if (isKataEqual(command,"WORK CHALLENGE") || isKataEqual(command,"work challenge") || isKataEqual(command,"2"))
            {
                workChallenge(user_id,&U);
            }
            else if (isKataEqual(command,"STORE LIST") || isKataEqual(command,"store list") || isKataEqual(command,"3"))
            {
                listStore(B);
            }
            else if (isKataEqual(command,"STORE REQUEST") || isKataEqual(command,"store request") || isKataEqual(command,"4"))
            {
                requestStore(B,&Q);
            }
            else if (isKataEqual(command,"STORE SUPPLY") || isKataEqual(command,"store supply") || isKataEqual(command,"5"))
            {
                supplyStore(&B,&Q);
            }
            else if (isKataEqual(command,"STORE REMOVE") || isKataEqual(command,"store remove") || isKataEqual(command,"6"))
            {
                removeStore(&B);
            }
            else if (isKataEqual(command,"BIO WEAPON") || isKataEqual(command,"bio weapon") || isKataEqual(command,"7"))
            {
                bioweapon(&Q,B);
            }
            else if (isKataEqual(command,"LOGOUT") || isKataEqual(command,"logout") || isKataEqual(command,"8"))
            {
                logout(&user_id,U);
                menu=2;
            }
            else if (isKataEqual(command,"SAVE") || isKataEqual(command,"save") || isKataEqual(command,"9"))
            {
                Save(B,U);
            }
            else if (isKataEqual(command,"QUIT") || isKataEqual(command,"quit") || isKataEqual(command,"10"))
            {
                quit(B,U);
                break;
            } 
            else if (isKataEqual(command,"HELP") || isKataEqual(command,"help")) 
            {
                clearterminal();
                Help(menu);
                isCommandHelp = true;
                helpInstructed = -1;
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