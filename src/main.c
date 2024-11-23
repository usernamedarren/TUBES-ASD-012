#include "console.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    Queue Q; ListBarang B; ListUser U; CreateQueue(&Q); MakeListBarang(&B); MakeEmpty(&U);
    int menu=1;
    while (1)
    {
        Help(menu);
        if (menu==1)
        {
            printf("Masukkan input: ");
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
                if (bisa==1) menu=2;
                else menu=1;
            }
            else if (strcmp(command,"QUIT")==0||strcmp(command,"quit")==0||strcmp(command,"3")==0)
            {
                quit(B,U);
                break;
            } else {
                printf("Input tidak valid\n");
            }
        }
        else if (menu==2)
        {
            printf("Masukkan input: ");
            char command[100];
            input(command);
            if (strcmp(command,"REGISTER")==0||strcmp(command,"register")==0||strcmp(command,"1")==0)
            {
                printf("Register\n");
            }
            else if (strcmp(command,"LOGIN")==0||strcmp(command,"login")==0||strcmp(command,"2")==0)
            {
                printf("Login\n");
                menu=3;
            }
            else if (strcmp(command,"QUIT")==0||strcmp(command,"quit")==0||strcmp(command,"3")==0)
            {
                quit(B,U);
                break;
            } else {
                printf("Input tidak valid\n");
            }
        }
        else if (menu==3)
        {
            printf("Masukkan input: ");
            char command[100];
            input(command);
            if (strcmp(command,"WORK")==0||strcmp(command,"work")==0||strcmp(command,"1")==0)
            {
                work();
            }
            else if (strcmp(command,"WORK CHALLENGE")==0||strcmp(command,"work challenge")==0||strcmp(command,"2")==0)
            {
                workChallenge();
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
                printf("Logout\n");
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
            } else {
                printf("Input tidak valid\n");
            }
        }   
    }
    
}