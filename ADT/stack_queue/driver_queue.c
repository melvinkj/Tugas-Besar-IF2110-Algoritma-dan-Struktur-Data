#include "prioqueue.h"
#include <stdio.h>
int main(){
    PrioQueue(Q);
    MakeEmpty(&Q, 10);
    Makanan m1;
    string s1;
    createString(&s1);
    s1 = appendCCtoStr(s1, 'a');
    string s2;
    createString(&s2);
    s2 = appendCCtoStr(s2, 'b');
    Makanan m2;
    TIME t3;
    CreateTime(&t3, 0, 0, 3);
    TIME t4;
    CreateTime(&t4, 0, 0, 5);
    m2 = CreateMakanan(2, s1, t4, s2, t3, 2, 2);
    Enqueue_Delivery(&Q, m2);
    TIME t1;
    CreateTime(&t1, 0, 0, 1);
    TIME t2;
    CreateTime(&t2, 0, 0, 6);
    m1 = CreateMakanan(1, s1, t2, s2, t1, 2, 2);
    Enqueue_Delivery(&Q, m1);
    PrintPrioQueue(Q);
}