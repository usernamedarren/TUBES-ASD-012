#include "console.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{

    Queue Q; ListBarang B; ListUser U; CreateQueue(&Q); B=MakeListBarang(); MakeEmpty(&U);
    int menu=1,user_id=-1;
    boolean isCommandHelp = false;
    int helpInstructed = 4;         
    clearterminal();
    printf("+ ================================================================================================= +\n");
    printf("|                 Selamat datang di PURRMART, sebuah sistem jual beli ke Borma!                     |\n");
    printf("+ ================================================================================================= +\n");
    artpurrmart();
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
            STARTWORD2();
            char sentance[100],command[100],txt[100];int idx=0,idx2= -1; WordToString(currentWord,sentance);
            while (sentance[idx]!='\0')
            {
                if (sentance[idx]==' ') 
                {
                    idx2=0;
                    command[idx]='\0';
                    idx++;
                }
                if (idx2== -1) {
                    command[idx]=sentance[idx];
                    idx++;
                } else {
                    txt[idx2]=sentance[idx];
                    idx2++; idx++;
                }
            }
            txt[idx2]='\0';
            if (isKataEqual(sentance, "START") || isKataEqual(sentance,"start") || isKataEqual(sentance,"1"))
            {
                clearterminal();
                artstart();
                start(&B,&U);
                menu=2;
            }
            else if (isKataEqual(command,"LOAD") || isKataEqual(command,"load") || isKataEqual(command,"2"))
            {
                clearterminal();
                artload();
                if (validtxt(txt)) 
                {
                    int bisa=1;
                    Load(txt,&B,&U,&bisa);
                    if (bisa) 
                    {
                        printf("File konfigurasi aplikasi berhasil dibaca. PURRMART berhasil dijalankan.\n");
                        menu=2;
                    }
                    else menu=1;
                }
                else printf("file harus berakhir dengan .txt\n");
            }
            else if (isKataEqual(sentance,"QUIT") || isKataEqual(sentance,"quit") || isKataEqual(sentance,"3"))
            {
                clearterminal();
                artquit();
                printf("terima kasih telah bermain PURRMART\n");
                break;
            } 
            else if (isKataEqual(sentance,"HELP") || isKataEqual(sentance,"help")) 
            {
                clearterminal();
                Help(menu);
                isCommandHelp = true;
                helpInstructed = -1;
            } 
            else {
                clearterminal();
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
                clearterminal();
                artregister();
                registeruser(&U);
            }
            else if (isKataEqual(command,"LOGIN") || isKataEqual(command,"login") || isKataEqual(command,"2"))
            {
                clearterminal();
                artlogin();
                login(&U,&user_id);
                if (user_id!=-1) {
                    menu=3;
                }
                else menu=2;
            }
            else if (isKataEqual(command,"QUIT") || isKataEqual(command,"quit") || isKataEqual(command,"3"))
            {
                clearterminal();
                artquit();
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
                clearterminal();
                printf("command tidak valid\n");
            }
        }

        else if (menu==3)
        {
            Help(helpInstructed);
            helpInstructed = 4;
            printf("\n");
            printf("Masukkan command (kata langsung/angka): ");
            STARTWORD2();
            char sentance[100]; WordToString(currentWord,sentance); char command[100],command2[100];
            int idx=0,idx2=0;
            while (1) {
                if (idx==idx2)
                {
                    command[idx]=sentance[idx];
                    command2[idx2]=sentance[idx];
                    idx++; idx2++;
                }
                if (sentance[idx]=='\0') break;
                if (sentance[idx]==' ') idx--;
                else if (idx2>idx)
                {
                    command2[idx2]=sentance[idx2];
                    idx2++;
                    if (sentance[idx2]==' ') break;
                    if (sentance[idx2]=='\0') break;
                }
            }
            if (idx<idx2) idx++;
            command[idx]='\0'; 
            command2[idx2]='\0';
            idx++; idx2++;
            if (isKataEqual(sentance,"PROFILE") || isKataEqual(sentance,"profile") || isKataEqual(sentance,"1"))
            {
                clearterminal();
                artprofile();
                profile(U,user_id);
            }
            else if (isKataEqual(sentance,"WORK") || isKataEqual(sentance,"work") || isKataEqual(sentance,"2"))
            {
                clearterminal();
                artwork();
                work(user_id,&U);
            }
            else if (isKataEqual(sentance,"WORK CHALLENGE") || isKataEqual(sentance,"work challenge") || isKataEqual(sentance,"3"))
            {

                clearterminal();
                artworkchallenge();
                workChallenge(user_id,&U);
            }
            else if (isKataEqual(sentance,"STORE LIST") || isKataEqual(sentance,"store list") || isKataEqual(sentance,"4"))
            {
                clearterminal();
                artstorelist();
                listStore(B);
            }
            else if (isKataEqual(sentance,"STORE REQUEST") || isKataEqual(sentance,"store request") || isKataEqual(sentance,"5"))
            {
                clearterminal();
                artstorerequest();
                requestStore(B,&Q);
            }
            else if (isKataEqual(sentance,"STORE SUPPLY") || isKataEqual(sentance,"store supply") || isKataEqual(sentance,"6"))
            {
                clearterminal();
                artstoresupply();
                supplyStore(&B,&Q);
            }
            else if (isKataEqual(sentance,"STORE REMOVE") || isKataEqual(sentance,"store remove") || isKataEqual(sentance,"7"))
            {
                clearterminal();
                artstoreremove();
                removeStore(&B);
            }
            else if (isKataEqual(sentance,"BIO WEAPON") || isKataEqual(sentance,"bio weapon") || isKataEqual(sentance,"8"))
            {
                clearterminal();
                artbioweapon();
                bioweapon(&Q,B);
            }
            else if (isKataEqual(command2,"CART ADD") || isKataEqual(command2,"cart add") || isKataEqual(command,"9"))
            {
                clearterminal();
                artcartadd();
                if (isKataEqual(command,"9")) idx2=idx;
                char name[100],temp[100]; int qty,idx3=idx2,space=0;
                while (sentance[idx2]!= '\0')
                {
                    if (sentance[idx2]==' ') space++;
                    idx2++;
                }
                idx2=idx3; idx3=0;
                while (space!=0)
                {
                    name[idx3++]=sentance[idx2++];
                    if (sentance[idx2]==' ') space--;
                    if (sentance[idx2]=='\0') break;
                }
                name[idx3]='\0'; idx2++; idx3=0;
                while (sentance[idx2]!= '\0')
                {
                    temp[idx3++]=sentance[idx2++];
                }
                temp[idx3]='\0'; stringtoint(temp,&qty);
                cartAdd(&U.TI[user_id].keranjang, name, qty, B);
            }
            else if (isKataEqual(command2,"CART REMOVE") || isKataEqual(command2,"cart remove") || isKataEqual(command,"10"))
            {
                clearterminal();
                artcartremove();
                if (isKataEqual(command,"9")) idx2=idx;
                char name[100],temp[100]; int qty,idx3=idx2,space=0;
                while (sentance[idx2]!= '\0')
                {
                    if (sentance[idx2]==' ') space++;
                    idx2++;
                }
                idx2=idx3; idx3=0;
                while (space!=0)
                {
                    name[idx3++]=sentance[idx2++];
                    if (sentance[idx2]==' ') space--;
                    if (sentance[idx2]=='\0') break;
                }
                name[idx3]='\0'; idx2++; idx3=0;
                while (sentance[idx2]!= '\0')
                {
                    temp[idx3++]=sentance[idx2++];
                }
                temp[idx3]='\0'; stringtoint(temp,&qty);
                cartRemove(&U.TI[user_id].keranjang, name, qty);
            }
            else if (isKataEqual(sentance,"CART SHOW") || isKataEqual(sentance,"cart show") || isKataEqual(sentance,"11"))
            {
                clearterminal();
                artcartshow();
                cartShow(U.TI[user_id].keranjang, B);
            }
            else if (isKataEqual(sentance,"CART PAY") || isKataEqual(sentance,"cart pay") || isKataEqual(sentance,"12"))
            {
                clearterminal();
                artcartpay();
                cartPay(&U.TI[user_id].keranjang, B, &U.TI[user_id], &U.TI[user_id].riwayat_pembelian);
            }
            else if (isKataEqual(command,"HISTORY") || isKataEqual(command,"history") || isKataEqual(command,"13"))
            {
                clearterminal();
                arthistory();
                char temp[100]; int i,idx2=0;
                while (sentance[idx]!= '\0')
                {
                    temp[idx2++]=sentance[idx++];
                }
                temp[idx2]='\0'; stringtoint(temp,&i);
                history(U.TI[user_id].riwayat_pembelian, i);
            }
            else if (isKataEqual(sentance,"WISHLIST ADD") || isKataEqual(sentance,"wishlist add") || isKataEqual(sentance,"14"))
            {
                clearterminal();
                artwishlistadd();
                wishlistadd(&U,user_id,B);
            }
            else if (isKataEqual(command2,"WISHLIST SWAP") || isKataEqual(command2,"wishlist swap") || isKataEqual(command,"15"))
            {
                clearterminal();
                artwishlistswap();
                if (isKataEqual (command,"15")) idx2=idx;
                char temp2[100],temp[100]; int i,j,idx3=0;
                while (sentance[idx2]!= ' ')
                {
                    temp[idx3++]=sentance[idx2++];
                    if (sentance[idx2]=='\0') break;
                }
                temp[idx3]='\0'; idx2++; idx3=0; stringtoint(temp,&i);
                while (sentance[idx2]!= '\0')
                {
                    temp2[idx3++]=sentance[idx2++];
                }
                temp2[idx3]='\0'; stringtoint(temp2,&j);
                wishlistswap(&U,user_id,i,j);
            }
            else if (isKataEqual(command,"16"))
            {
                clearterminal();
                artwishlistremove();

                char temp[100]; int i,idx2=0;
                while (sentance[idx]!= '\0')
                {
                    temp[idx2++]=sentance[idx++];
                }
                temp[idx2]='\0'; stringtoint(temp,&i);
                wishlistremoveid(&U,user_id,i);
            }
            else if (isKataEqual(command2,"WISHLIST REMOVE") || isKataEqual(command2,"wishlist remove") || isKataEqual(command,"17"))
            {
                if (sentance[idx2-1]=='\0' || isKataEqual(command,"17"))
                {
                    clearterminal();
                    artwishlistremove();
                    wishlistremovename(&U,user_id);
                } else
                {
                    clearterminal();
                    artwishlistremove();
                    char temp[100]; int i,idx3=0;
                    while (sentance[idx2]!= '\0')
                    {
                        temp[idx3++]=sentance[idx2++];
                    }
                    temp[idx3]='\0'; stringtoint(temp,&i);
                    wishlistremoveid(&U,user_id,i);
                }
            }
            else if (isKataEqual(sentance,"WISHLIST CLEAR") || isKataEqual(sentance,"wishlist clear") || isKataEqual(sentance,"18"))
            {
                clearterminal();
                artwishlistclear();
                wishlistclear(&U,user_id);
            }
            else if (isKataEqual(sentance,"WISHLIST SHOW") || isKataEqual(sentance,"wishlist show") || isKataEqual(sentance,"19"))
            {
                clearterminal();
                artwishlistshow();
                wishlistshow(U,user_id);
            }
            else if (isKataEqual(sentance,"LOGOUT") || isKataEqual(sentance,"logout") || isKataEqual(sentance,"20"))
            {
                clearterminal();
                artlogout();
                logout(&user_id,U);
                menu=2;
            }
            else if (isKataEqual(command,"SAVE") || isKataEqual(command,"save") || isKataEqual(command,"21"))
            {
                clearterminal();
                artsave();
                char temp[100]; int i,idx2=0;
                while (sentance[idx]!= '\0')
                {
                    temp[idx2++]=sentance[idx++];
                }
                temp[idx2]='\0';
                if (validtxt(temp)) Save(B,U,temp);
                else printf("file harus berakhir dengan .txt\n");
            
            }
            else if (isKataEqual(sentance,"QUIT") || isKataEqual(sentance,"quit") || isKataEqual(sentance,"22"))
            {
                clearterminal();
                artquit();
                quit(B,U);
                break;
            } 
            else if (isKataEqual(sentance,"HELP") || isKataEqual(sentance,"help")) 
            {
                
                clearterminal();
                Help(menu);
                isCommandHelp = true;
                helpInstructed = -1;
            } 
            else {
                clearterminal();
                printf("command tidak valid\n");
            }
        } 
        if (!isCommandHelp) 
        {
           wait();
           clearterminal(); 
        }
    }
}