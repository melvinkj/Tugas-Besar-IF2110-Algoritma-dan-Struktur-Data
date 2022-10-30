/* ADT Resep
   Implementasi ADT Resep */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tree.h"
#include "../tree/tree.h"
#include "resep.h"

void printTree(tree t, int max){
/* Menampilkan tree */
/* Mengutamakan print child terlebih dahulu lalu next */
    int i;
    if ((CHILDNODE(t) == NIL) && (NEXTNODE(t) == NIL)){ // tidak punya child dan tidak punya next
        for(i = 0; i < max - height(t); i++){
            printf("  ");
        }
        printf("%c\n", ROOT(t));
    }
    else if (NEXTNODE(t) == NIL){ // punys child dan tidak punya next
        for(i = 0; i < max - height(t); i++){
            printf("  ");
        }
        printf("%c\n", ROOT(t));
        printTree(CHILDNODE(t), max);
    }
    else if (CHILDNODE(t) == NIL) { // tidak punya child dan punya next
        for(i = 0; i < max - height(t); i++){
            printf("  ");
        }
        printf("%c\n", ROOT(t));
        printTree(NEXTNODE(t), max);
    }
    else{ // punya child dan punya next (utamakan print child)
        for(i = 0; i < max - height(t); i++){
            printf("  ");
        }
        printf("%c\n", ROOT(t));
        printTree(CHILDNODE(t), max);
        printTree(NEXTNODE(t), max - 1);
    }
}

void printTreeFin(tree t){
/* Print tree tanpa perlu argumen max */
    int max = height(t);
    printTree(t, max);
}