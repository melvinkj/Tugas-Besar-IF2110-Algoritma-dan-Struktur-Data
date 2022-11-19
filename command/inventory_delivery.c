#include <stdio.h>
#include <stdlib.h>
#include "inventory_delivery.h"


boolean isEmptyPriorityQueue(PrioQueue Q){
    return (Head(Q) == Nil && Tail(Q) == Nil);
}

void kurang_waktu_inv(PrioQueue *inventory){
    if (!isEmptyPriorityQueue(*inventory)){
        int i = Head(*inventory);
        while (i != Tail(*inventory)){
            Elmt(*inventory, i).waktu_kedaluwarsa = PrevMenit(Elmt(*inventory, i).waktu_kedaluwarsa);
            i = (i+1)%MaxEl(*inventory);
        }
        Elmt(*inventory, i).waktu_kedaluwarsa = PrevMenit(Elmt(*inventory, i).waktu_kedaluwarsa);
        i = Head(*inventory);
        int j = 1;
        while (i != Tail(*inventory)){
            if (Elmt(*inventory, i).waktu_kedaluwarsa.DD == 0 && Elmt(*inventory, i).waktu_kedaluwarsa.HH == 0 && Elmt(*inventory, i).waktu_kedaluwarsa.MM == 0){
                printf("%d. %s kedaluwarsa.. :(\n", j, Elmt(*inventory, i).nama.content);
                j++;
                Remove(inventory, Elmt(*inventory, i));
                i = Head(*inventory);
            }else{
                i = (i+1)%MaxEl(*inventory);
            }
        }
        /* i = tail*/
        if (Elmt(*inventory, i).waktu_kedaluwarsa.DD == 0 && Elmt(*inventory, i).waktu_kedaluwarsa.HH == 0 && Elmt(*inventory, i).waktu_kedaluwarsa.MM == 0){
            printf("%d. %s kedaluwarsa.. :(\n", j, Elmt(*inventory, i).nama.content);
            j++;
            Remove(inventory, Elmt(*inventory, i));
        }
    } 
}

void kurang_waktu_deliv(PrioQueue *delivery,PrioQueue *inventory){
    if (!isEmptyPriorityQueue(*delivery)){
        int i = Head(*delivery);
        while (i != Tail(*delivery)){
            Elmt(*delivery, i).lama_pengiriman = PrevMenit(Elmt(*delivery, i).lama_pengiriman);
            i = (i+1)%MaxEl(*delivery);
        }
        Elmt(*delivery, i).lama_pengiriman = PrevMenit(Elmt(*delivery, i).lama_pengiriman);
        i = Head(*delivery);
        while (i != Tail(*delivery)){
            if (Elmt(*delivery, i).lama_pengiriman.DD == 0 && Elmt(*delivery, i).lama_pengiriman.HH == 0 && Elmt(*delivery, i).lama_pengiriman.MM == 0){
                printf("%s sudah diterima oleh BNMO!\n", Elmt(*delivery, i).nama.content);
                Enqueue(inventory, Elmt(*delivery, i));
                Remove(delivery, Elmt(*delivery, i));
                i = Head(*delivery);
            }else{
                i = (i+1)%MaxEl(*delivery);
            }
        }
        /* i = tail */
        if (Elmt(*delivery, i).lama_pengiriman.DD == 0 && Elmt(*delivery, i).lama_pengiriman.HH == 0 && Elmt(*delivery, i).lama_pengiriman.MM == 0){
            Enqueue(inventory, Elmt(*delivery, i));
            Remove(delivery, Elmt(*delivery, i));
        }
    }   
}

void tidakjadibeli(PrioQueue sebelum, PrioQueue sekarang){
    /* NBELMT sebelum < NBElmt sekarang */
    PrioQueue temp1,temp2;
    MakeEmpty(&temp1, MaxEl(sebelum));
    MakeEmpty(&temp2, MaxEl(sekarang));
    copyPrioQueue(sebelum, &temp1);
    copyPrioQueue(sekarang, &temp2);
    int i,j, NBElmtsebelum = 0, NBElmtsekarang = 0;
    i = Head(temp1);
    j = Head(temp2);
    boolean found = false;
    for (NBElmtsekarang = 0; NBElmtsekarang < NBElmt(temp2); NBElmtsekarang++){
        for (NBElmtsebelum = 0; NBElmtsebelum < NBElmt(temp1); NBElmtsebelum++){
            if (Elmt(temp1, i).id == Elmt(temp2, j).id){
                found = true;
                Remove(&temp1, Elmt(temp1, i));
                break;
            }
            i = (i+1)%MaxEl(temp1);
        }
        if (!found){
            printf("%s  tidak jadi dibeli :(\n", Elmt(temp2, j).nama.content);
            // printf("id = %d  tidak jadi dibeli :(\n", Elmt(temp2, j).id);
        }
        found = false;
        i = Head(temp1);
        j = (j+1)%MaxEl(temp2);
    }
}

void jadibeli(PrioQueue sebelum, PrioQueue sekarang){
    /* NBELMT sebelum < NBElmt sekarang */
    PrioQueue temp1,temp2;
    MakeEmpty(&temp1, MaxEl(sebelum));
    MakeEmpty(&temp2, MaxEl(sekarang));
    copyPrioQueue(sebelum, &temp1);
    copyPrioQueue(sekarang, &temp2);
    int i,j, NBElmtsebelum = 0, NBElmtsekarang = 0;
    i = Head(temp1);
    j = Head(temp2);
    boolean found = false;
    for (NBElmtsekarang = 0; NBElmtsekarang < NBElmt(temp2); NBElmtsekarang++){
        for (NBElmtsebelum = 0; NBElmtsebelum < NBElmt(temp1); NBElmtsebelum++){
            if (Elmt(temp1, i).id == Elmt(temp2, j).id){
                found = true;
                Remove(&temp1, Elmt(temp1, i));
                break;
            }
            i = (i+1)%MaxEl(temp1);
        }
        if (!found){
            printf("%s  dibeli \n", Elmt(temp2, j).nama.content);
            // printf("id = %d  jadi dibeli :(\n", Elmt(temp2, j).id);
        }
        found = false;
        i = Head(temp1);
        j = (j+1)%MaxEl(temp2);
    }
}

void kembalikedelivery(PrioQueue sebelum, PrioQueue sekarang){
    /* NBElmt sebelum > NBELMT sekarang */
    PrioQueue temp1,temp2;
    MakeEmpty(&temp1, MaxEl(sebelum));
    MakeEmpty(&temp2, MaxEl(sekarang));
    copyPrioQueue(sebelum, &temp1);
    copyPrioQueue(sekarang, &temp2);
    int i,j, NBElmtsebelum = 0, NBElmtsekarang = 0;
    i = Head(temp1);
    j = Head(temp2);
    boolean found = false;
    for (NBElmtsebelum = 0; NBElmtsebelum < NBElmt(temp1); NBElmtsebelum++){
        for (NBElmtsekarang = 0; NBElmtsekarang < NBElmt(temp2); NBElmtsekarang++){
            if (Elmt(temp1, i).id == Elmt(temp2, j).id){
                found = true;
                Remove(&temp2, Elmt(temp2, i));
                break;
            }
            j = (j+1)%MaxEl(temp2);
        }
        if (!found){
            printf("%s kembali ke delivery :(\n", Elmt(temp1, i).nama.content);
            // printf("id = %d kembali ke delivery :(\n", Elmt(temp1, i).id);
        }
        found = false;
        j = Head(temp2);
        i = (i+1)%MaxEl(temp1);
    }
}

void keluardelivery(PrioQueue sebelum, PrioQueue sekarang){
    /* NBElmt sebelum > NBELMT sekarang */
    PrioQueue temp1,temp2;
    MakeEmpty(&temp1, MaxEl(sebelum));
    MakeEmpty(&temp2, MaxEl(sekarang));
    copyPrioQueue(sebelum, &temp1);
    copyPrioQueue(sekarang, &temp2);
    int i,j, NBElmtsebelum = 0, NBElmtsekarang = 0;
    i = Head(temp1);
    j = Head(temp2);
    boolean found = false;
    for (NBElmtsebelum = 0; NBElmtsebelum < NBElmt(temp1); NBElmtsebelum++){
        for (NBElmtsekarang = 0; NBElmtsekarang < NBElmt(temp2); NBElmtsekarang++){
            if (Elmt(temp1, i).id == Elmt(temp2, j).id){
                found = true;
                Remove(&temp2, Elmt(temp2, i));
                break;
            }
            j = (j+1)%MaxEl(temp2);
        }
        if (!found){
            printf("%s masuk ke inventory\n", Elmt(temp1, i).nama.content);
            // printf("id = %d masuk ke inventory :(\n", Elmt(temp1, i).id);
        }
        found = false;
        j = Head(temp2);
        i = (i+1)%MaxEl(temp1);
    }
}

void tidakjadipengolahan(PrioQueue sebelum, PrioQueue sekarang, ListStatikResep resep){
    /* NBELMT sebelum > NBElmt sekarang */

    PrioQueue temp1,temp2;
    temp1 = sebelum;
    temp2 = sekarang;
    int i,j, NBElmtsebelum = 0, NBElmtsekarang = 0;
    i = Head(temp1);
    j = Head(temp2);
    boolean found = false;
    for (NBElmtsekarang = 0; NBElmtsekarang < NBElmt(temp2); NBElmtsekarang++){
        int id = Elmt(temp2, j).id;
        int k  = 0;
        /* Mencari id pada resep untuk mendapatkan alamat rootnya */
        for (k = 0;k< listLengthResep(resep);k++){
            if (id == ROOT(ELMTR(resep, k))){
                break;
            }
        }
        /* jika ada maka kurangi child yang ada pada queue sebelum */
        /* dipastikan ada child untuk setiap root di queue sebelum */
        /* karena jika tidak ada child, tidak mungkin terbentuk root pada queue sekarang */
        if (k < listLengthResep(resep)){
            AddressTree last = CHILDNODE(ELMTR(resep, k));
            while (last != NIL){
                for (NBElmtsebelum = 0; NBElmtsebelum < NBElmt(temp1); NBElmtsebelum++){
                    if (Elmt(temp1, i).id == ROOT(last)){
                        found = true;
                        Remove(&temp1, Elmt(temp1, i));
                        i = Head(temp1);
                        break;
                    }else{
                        i = (i+1)%MaxEl(temp1);
                    }
                }
                last = NEXTNODE(last);
            }
            printf("%s tidak jadi diproses di %s :(\n", Elmt(temp2, j).nama.content, Elmt(temp2,j).lokasi_aksi.content);   
            // printf("id = %d tidak jadi diproses di %s :(\n", Elmt(temp2, j).id, Elmt(temp2,j).lokasi_aksi.content);   
        }
        j = (j+1)%MaxEl(temp2);
    }
    kembalikeinventory(temp1, temp2);
}

void jadipengolahan(PrioQueue sebelum, PrioQueue sekarang, ListStatikResep resep){
    /* NBELMT sebelum > NBElmt sekarang */

    PrioQueue temp1,temp2;
    temp1 = sebelum;
    temp2 = sekarang;
    int i,j, NBElmtsebelum = 0, NBElmtsekarang = 0;
    i = Head(temp1);
    j = Head(temp2);
    boolean found = false;
    for (NBElmtsekarang = 0; NBElmtsekarang < NBElmt(temp2); NBElmtsekarang++){
        int id = Elmt(temp2, j).id;
        int k  = 0;
        /* Mencari id pada resep untuk mendapatkan alamat rootnya */
        for (k = 0;k< listLengthResep(resep);k++){
            if (id == ROOT(ELMTR(resep, k))){
                break;
            }
        }
        /* jika ada maka kurangi child yang ada pada queue sebelum */
        /* dipastikan ada child untuk setiap root di queue sebelum */
        /* karena jika tidak ada child, tidak mungkin terbentuk root pada queue sekarang */
        if (k < listLengthResep(resep)){
            AddressTree last = CHILDNODE(ELMTR(resep, k));
            while (last != NIL){
                for (NBElmtsebelum = 0; NBElmtsebelum < NBElmt(temp1); NBElmtsebelum++){
                    if (Elmt(temp1, i).id == ROOT(last)){
                        found = true;
                        Remove(&temp1, Elmt(temp1, i));
                        i = Head(temp1);
                        break;
                    }else{
                        i = (i+1)%MaxEl(temp1);
                    }
                }
                last = NEXTNODE(last);
            }
            printf("%s diproses di %s :(\n", Elmt(temp2, j).nama.content, Elmt(temp2,j).lokasi_aksi.content);   
            // printf("id = %d jadi diproses di %s :(\n", Elmt(temp2, j).id, Elmt(temp2,j).lokasi_aksi.content);   
        }
        j = (j+1)%MaxEl(temp2);
    }
    keluarinventory(temp1, temp2);
}

void kembalikeinventory(PrioQueue sebelum, PrioQueue sekarang){
    /* NBElmt sebelum > NBELMT sekarang */
    PrioQueue temp1,temp2;
    MakeEmpty(&temp1, MaxEl(sebelum));
    MakeEmpty(&temp2, MaxEl(sekarang));
    copyPrioQueue(sebelum, &temp1);
    copyPrioQueue(sekarang, &temp2);
    int i,j, NBElmtsebelum = 0, NBElmtsekarang = 0;
    i = Head(temp1);
    j = Head(temp2);
    boolean found = false;
    for (NBElmtsebelum = 0; NBElmtsebelum < NBElmt(temp1); NBElmtsebelum++){
        for (NBElmtsekarang = 0; NBElmtsekarang < NBElmt(temp2); NBElmtsekarang++){
            if (Elmt(temp1, i).id == Elmt(temp2, j).id){
                found = true;
                Remove(&temp2, Elmt(temp2, i));
                break;
            }
            j = (j+1)%MaxEl(temp2);
        }
        if (!found){
            printf("%s tidak jadi expired :)\n", Elmt(temp1, i).nama.content);
            // printf("id = %d tidak jadi expired :)\n", Elmt(temp1, i).id);
        }
        found = false;
        j = Head(temp2);
        i = (i+1)%MaxEl(temp1);
    }
}

void keluarinventory(PrioQueue sebelum, PrioQueue sekarang){
    /* NBElmt sebelum > NBELMT sekarang */
    PrioQueue temp1,temp2;
    MakeEmpty(&temp1, MaxEl(sebelum));
    MakeEmpty(&temp2, MaxEl(sekarang));
    copyPrioQueue(sebelum, &temp1);
    copyPrioQueue(sekarang, &temp2);
    int i,j, NBElmtsebelum = 0, NBElmtsekarang = 0;
    i = Head(temp1);
    j = Head(temp2);
    boolean found = false;
    for (NBElmtsebelum = 0; NBElmtsebelum < NBElmt(temp1); NBElmtsebelum++){
        for (NBElmtsekarang = 0; NBElmtsekarang < NBElmt(temp2); NBElmtsekarang++){
            if (Elmt(temp1, i).id == Elmt(temp2, j).id){
                found = true;
                Remove(&temp2, Elmt(temp2, i));
                break;
            }
            j = (j+1)%MaxEl(temp2);
        }
        if (!found){
            printf("%s expired :(\n", Elmt(temp1, i).nama.content);
            // printf("id = %d expired :)\n", Elmt(temp1, i).id);
        }
        found = false;
        j = Head(temp2);
        i = (i+1)%MaxEl(temp1);
    }
}