#include "undoredo.h"
#include "inventory_delivery.h"
#include <stdio.h>

int main(){
    Simulator S;
    CreateEmptyUndoRedo();
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
    S.inventory = inventory;
    S.delivery = delivery;
    addUndo(S);
    PrintInventory(S.inventory);
    kurang_waktu_inv(&S.inventory);
    PrintInventory(S.inventory);
}