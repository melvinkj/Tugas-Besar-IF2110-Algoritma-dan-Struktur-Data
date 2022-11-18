#include <stdio.h>
#include <stdlib.h>
#include "tree.c"

int main(){
    tree t;
    createTree(&t);

    insertFirstNode(&t, 0);
    insertChild(&t, 1);
    insertChild(&t, 2);
    insertChild(&t, 3);
    insertChild(&CHILDNODE(t),4);
    insertChild(&CHILDNODE(t),5);

    printf("%d\n", height(t));

    printTreeFin(t);

    printf("%d", ROOT(addrSearch(t,2)));

    return 0;
}