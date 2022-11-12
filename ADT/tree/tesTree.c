#include <stdio.h>
#include <stdlib.h>
#include "tree.c"

int main(){
    tree t;
    createTree(&t);
    type a = 0;
    type b = 1;
    type c = 2;
    type d = 3;

    insertFirstNode(&t, a);
    insertChild(&t, b);
    insertChild(&t, c);
    insertChild(&t, a);
    insertChild(&CHILDNODE(t),d);
    insertChild(&CHILDNODE(t),d);
    printf("%d\n", ROOT(addrSearch(t,4)));

    printf("%d\n", height(t));

    printTreeFin(t);



    return 0;
}