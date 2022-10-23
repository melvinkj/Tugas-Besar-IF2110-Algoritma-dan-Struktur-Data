#include <stdio.h>
#include <stdlib.h>
#include "tree.c"

int main(){
    tree t;
    createTree(&t);
    infotype a = 'A';
    infotype b = 'B';
    infotype c = 'C';
    infotype d = 'D';

    insertFirstNode(&t, a);
    insertChild(&t, b);
    insertChild(&t, c);
    insertChild(&t, a);
    insertChild(&CHILDNODE(t),d);
    insertChild(&CHILDNODE(t),d);

    printf("%d\n", height(t));

    printTreeFin(t);



    return 0;
}