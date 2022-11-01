#include <stdio.h>
#include <stdlib.h>
#include "inventory_delivery.h"

void kurang_waktu_inv(PrioQueue *inventory){
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

void kurang_waktu_deliv(PrioQueue *delivery,PrioQueue *inventory){
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