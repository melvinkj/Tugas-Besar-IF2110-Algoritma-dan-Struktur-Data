#include <stdio.h>
#include <stdlib.h>
#include "ADT/stack_queue/prioqueue.h"

void kurang_waktu_inv(PrioQueue *inventory){
    int i = Head(*inventory);
    while (i != Tail(*inventory)){
        Elmt(*inventory, i).waktu_kedaluwarsa = PrevMenit(Elmt(*inventory, i).waktu_kedaluwarsa);
        i = (i+1)%MaxEl(*inventory);
    }
    Elmt(*inventory, i).waktu_kedaluwarsa = PrevMenit(Elmt(*inventory, i).waktu_kedaluwarsa);
    int i = Head(*inventory);
    while (i != Tail(*inventory)){
        if (Elmt(*inventory, i).waktu_kedaluwarsa.DD == 0 && Elmt(*inventory, i).waktu_kedaluwarsa.HH == 0 && Elmt(*inventory, i).waktu_kedaluwarsa.MM == 0){
            Remove(inventory, Elmt(*inventory, i));
        }
        i = (i+1)%MaxEl(*inventory);
    }
    if (Elmt(*inventory, i).waktu_kedaluwarsa.DD == 0 && Elmt(*inventory, i).waktu_kedaluwarsa.HH == 0 && Elmt(*inventory, i).waktu_kedaluwarsa.MM == 0){
        Remove(inventory, Elmt(*inventory, i));
    }
}

void kurang_waktu_deliv(PrioQueue *delivery,PrioQueue *inventory){
    int i = Head(*delivery);
    while (i != Tail(*delivery)){
        Elmt(*delivery, i).waktu_kedaluwarsa = PrevMenit(Elmt(*delivery, i).waktu_kedaluwarsa);
        i = (i+1)%MaxEl(*delivery);
    }
    Elmt(*delivery, i).waktu_kedaluwarsa = PrevMenit(Elmt(*delivery, i).waktu_kedaluwarsa);
    int i = Head(*delivery);
    while (i != Tail(*delivery)){
        if (Elmt(*delivery, i).waktu_kedaluwarsa.DD == 0 && Elmt(*delivery, i).waktu_kedaluwarsa.HH == 0 && Elmt(*delivery, i).waktu_kedaluwarsa.MM == 0){
            Enqueue(inventory, Elmt(*delivery, i));
        }
        i = (i+1)%MaxEl(*delivery);
    }
    if (Elmt(*delivery, i).waktu_kedaluwarsa.DD == 0 && Elmt(*delivery, i).waktu_kedaluwarsa.HH == 0 && Elmt(*delivery, i).waktu_kedaluwarsa.MM == 0){
        Enqueue(inventory, Elmt(*delivery, i));
    }
}