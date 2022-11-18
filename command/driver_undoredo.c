#include "undoredo.h"
#include "inventory_delivery.h"
#include <stdio.h>

int main(){
    ListStatikResep LSR;
    CreateListStatikResep(&LSR);
    tree T;
    createTree(&T);
    insertFirstNode(&T, 1);
    insertChild(&T,2);
    insertChild(&T,3);
    insertFirstResep(&LSR,T);


    CreateEmptyUndoRedo();
    Stack UndoStack;
    CreateEmpty(&UndoStack);
    Simulator s;
    createSimulator(&s);
    Simulator s2;
    createSimulator(&s2);
    string s1;
    createString(&s1);
    s1 = appendCCtoStr(s1, 'a');
    s.nama = s1;
    TIME t1;
    CreateTime(&t1, 0, 0, 1);
    s.waktu = t1;
    POINT p1;
    CreatePoint(&p1, 1, 1);
    s.posisi = p1;
    MakeEmpty(&s.inventory, 10);
    MakeEmpty(&s.delivery, 10);
    createMatrix(10, 10, &s.kulkas);
    Makanan makanan1 = CreateMakanan(1, s1, t1, s1, t1, 2, 2);
    Makanan makanan2 = CreateMakanan(3, s1, t1, s1, t1, 2, 2);
    Makanan makanan3 = CreateMakanan(3, s1, t1, s1, t1, 2, 2);
    Makanan makanan6 = CreateMakanan(4, s1, t1, s1, t1, 2, 2);
    Enqueue(&s.inventory, makanan1);
    Enqueue(&s.inventory, makanan2);
    Enqueue(&s.inventory, makanan3);
    Enqueue(&s.inventory, makanan6);
    PrintPrioQueue(s.inventory); 
    addUndo(s);
    Dequeue(&s.inventory, &makanan1);
    BacaPOINT(&p1);
    s.posisi = p1;
    TulisPOINT(s.posisi);
    addUndo(s);
    PrintPrioQueue(s.inventory);
    undo(&s,LSR);
    PrintPrioQueue(s.inventory);
    redo(&s,LSR);
    BacaPOINT(&p1);
    s.posisi = p1;
    TulisPOINT(s.posisi);
    addUndo(s);
    TulisPOINT(s.posisi);
    TulisPOINT(s.posisi);
     /*
    gcc driver_undoredo.c inventory_delivery.c undoredo.c ../ADT/stack_queue/prioqueue.c ../ADT/stack_queue/stack.c ../ADT/sederhana/makanan.c ../ADT/sederhana/waktu.c ../ADT/sederhana/simulator.c ../ADT/sederhana/point.c ../ADT/matrix/matrix.c ../ADT/char_word_machine/string.c -o main
*/
}