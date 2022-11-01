#include "prioqueue.h"
#include <stdio.h>
int main(){
    PrioQueue(Q);
    MakeEmpty(&Q, 10);
    infotype X;
    TIME T;
    T.HH = 0;
    T.MM = 1;
    T.DD = 0;
    X.id = 1;
    X.nama.content = "beras";
    X.waktu_kedaluwarsa = T;
    X.lokasi_aksi.content = "kitchen";
    X.lama_pengiriman = T;
    X.lama_pemrosesan = T;
    Enqueue(&Q, X);
    PrintPrioQueue(Q);
    Enqueue(&Q, X);
    Enqueue(&Q, X);
    Enqueue(&Q, X);
    Enqueue(&Q, X);
    Enqueue(&Q, X);
    Enqueue(&Q, X);
    Enqueue(&Q, X);
    Enqueue(&Q, X);
    Enqueue(&Q, X);
    Dequeue(&Q, &X);
    Enqueue(&Q, X);
    PrintPrioQueue(Q);
    Remove(&Q, X);
    PrintPrioQueue(Q);
}