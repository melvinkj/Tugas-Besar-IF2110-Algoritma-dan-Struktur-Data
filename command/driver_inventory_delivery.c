#include "inventory_delivery.h"
#include <stdio.h>

int main(){
    PrioQueue inventory;
    PrioQueue delivery;
    MakeEmpty(&inventory, 10);
    MakeEmpty(&delivery, 10);
    TIME t1,t2 ;
    CreateTime(&t1,0, 0, 1);
    CreateTime(&t2,0, 0, 2);
    string s1,s2;
    createString(&s1);
    createString(&s2);
    s1 = appendCCtoStr(s1, 'a');
    s2 = appendCCtoStr(s2, 'b');

    Makanan makanan1 = CreateMakanan(1, s1, t1, s2, t2, 2, 2);
    Makanan makanan2 = CreateMakanan(3, s1, t1, s2, t2, 2, 2);
    Makanan makanan3 = CreateMakanan(3, s1, t1, s2, t2, 2, 2);
    Makanan makanan6 = CreateMakanan(4, s1, t1, s2, t2, 2, 2);

    Enqueue(&inventory, makanan1);
    Enqueue(&inventory, makanan2);
    Enqueue(&inventory, makanan3);
    Enqueue(&inventory, makanan6);
    PrintPrioQueue(inventory);

    Makanan makanan4 = CreateMakanan(1, s1, t1, s2, t2, 2, 2);
    Makanan makanan5 = CreateMakanan(3, s1, t1, s2, t2, 2, 2);

    Enqueue(&delivery, makanan4);
    Enqueue(&delivery, makanan5);
    PrintPrioQueue(delivery);

    tidakjadibeli(delivery, inventory);
    kembalikedelivery(inventory, delivery);
}
/*
gcc driver_inventory_delivery.c ../ADT/sederhana/waktu.c ../ADT/sederhana/makanan.c inventory_delivery.c ../ADT/stack_queue/prioqueue.c ../ADT/char_word_machine/string.c -o main
*/