#include "undoredo.h"
#include "inventory_delivery.h"
#include <stdio.h>

int main(){
    Stack UndoStack;
    CreateEmpty(&UndoStack);
    CreateEmptyUndoRedo();
    Simulator S;
    S.nama.content = "test";
    MakeEmpty(&S.inventory, 10);
    MakeEmpty(&S.delivery, 10);
    PrintPrioQueue(S.inventory);
    printf("delivery");
    PrintPrioQueue(S.delivery);
    PrioQueue inventory;
    PrioQueue delivery;
    MakeEmpty(&inventory, 10);
    MakeEmpty(&delivery, 10);
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
    Enqueue(&inventory, X);
    Enqueue(&delivery, X);
    PrintPrioQueue(inventory);
    printf("delivery");
    PrintPrioQueue(delivery);
    infotype Y;
    Y.id = 2;
    T.HH = 0;
    T.MM = 3;
    T.DD = 0;
    Y.nama.content = "test";
    Y.waktu_kedaluwarsa = T;
    Y.lokasi_aksi.content = "kitchen";
    Y.lama_pengiriman = T;
    Y.lama_pemrosesan = T;
    Enqueue(&inventory, Y);
    Enqueue(&delivery, Y);
    PrintPrioQueue(inventory);
    printf("delivery");
    PrintPrioQueue(delivery);
    infotype Z;
    T.HH = 0;
    T.MM = 2;
    T.DD = 0;
    Z.id = 3;
    Z.nama.content = "akhir";
    Z.waktu_kedaluwarsa = T;
    Z.lokasi_aksi.content = "kitchen";
    Z.lama_pengiriman = T;
    Z.lama_pemrosesan = T;
    Enqueue(&inventory, Z);
    Enqueue(&delivery, Z);
    PrintPrioQueue(inventory);
    printf("delivery");
    PrintPrioQueue(delivery);
    kurang_waktu_deliv(&delivery,&inventory);
    PrintPrioQueue(delivery);
    PrintPrioQueue(inventory);
    kurang_waktu_inv(&inventory);
    PrintPrioQueue(inventory);
    S.inventory = inventory;
    S.delivery = delivery;
    PrintPrioQueue(S.inventory);
    printf("delivery");
    PrintPrioQueue(S.delivery);
    kurang_waktu_inv(&S.inventory);
    addUndo(S);
    PrintPrioQueue(S.inventory);
    kurang_waktu_inv(&S.inventory);
    addUndo(S);
    printf("isi stack:\n");
    printstackundo();
    printf("isi simulasi:\n");
    PrintPrioQueue(S.inventory);
    undo(&S);
    printf("isi stack:\n");
    PrintPrioQueue(S.inventory);
    redo(&S);
    printf("isi stack:\n");
    PrintPrioQueue(S.inventory);
    redo(&S);
     /*
    gcc driver_undoredo.c inventory_delivery.c undoredo.c ../ADT/stack_queue/prioqueue.c ../ADT/stack_queue/stack.c ../ADT/sederhana/makanan.c ../ADT/sederhana/waktu.c ../ADT/sederhana/simulator.c ../ADT/sederha
na/point.c ../ADT/matrix/matrix.c -o main
*/
}