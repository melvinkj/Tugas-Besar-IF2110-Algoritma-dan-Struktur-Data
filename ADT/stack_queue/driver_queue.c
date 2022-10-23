#include "prioqueue.h"
#include <stdio.h>
int main(){
    PrioQueue pq;
    MakeEmpty(&pq, 5);
    infotype x;
    x.time = 1;
    x.info = 'a';
    Enqueue(&pq, x);
    x.time = 2;
    x.info = 'b';
    Enqueue(&pq, x);
    x.time = 3;
    x.info = 'c';
    Enqueue(&pq, x);
    x.time = 4;
    x.info = 'd';
    Enqueue(&pq, x);
    x.time = 5;
    x.info = 'e';
    Enqueue(&pq, x);
    PrintPrioQueue(pq);
    Dequeue(&pq, &x);
    PrintPrioQueue(pq);
    x.time = 3;
    x.info = 'c';
    Enqueue(&pq, x);
    printf("Tail: %d\n", Tail(pq));
    PrintPrioQueue(pq);
    x.time = 3;
    x.info = 'c';
    Remove(&pq, x);
    PrintPrioQueue(pq);
    printf("Head: %d\n", Head(pq));
    printf("%d %c", Time(Elmt(pq, Head(pq))), Info(Elmt(pq, Head(pq))));
    printf("Tail: %d\n", Tail(pq));
    printf("%d %c", Time(Elmt(pq, Tail(pq))), Info(Elmt(pq, Tail(pq))));
}