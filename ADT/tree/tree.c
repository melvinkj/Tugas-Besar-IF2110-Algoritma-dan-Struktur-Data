/* ADT Tree
   Implementasi ADT Tree*/

#include <stdio.h>
#include "tree.h"

/* KONSTRUKTOR */
AddressTree newNode(type x){
/* Mengalokasikan memori untuk node baru */
    AddressTree adr;

    adr = (AddressTree) malloc(sizeof(Node));
    if (adr != NIL){
        ROOT(adr) = x;
        NEXTNODE(adr) = NIL;
        CHILDNODE(adr) = NIL;
    }
    return adr;
}

void deallocateNode(AddressTree adr){
/* Membebaskan memori adr */
    free(adr);
}

void createTree(tree *t){
/* Membuat tree kosong*/
    *t = NIL;
}

void insertFirstNode(tree *t, type val){
/* Tree harus kosong */
/* Menambahkan node pertama yang baru */
    Node *n = newNode(val);

    if (n != NIL){
        ROOT(n) = val;
        NEXTNODE(n) = NIL;
        CHILDNODE(n) = NIL;
    }
    *t = n;
}

void insertChild(tree *t, type val){
/* Menambahkan node ke child tree */
    Node *n = newNode(val);

    if (n != NIL){
        if (isOneNode(*t)){
            CHILDNODE(*t) = n;
        }
        else{
            AddressTree last = CHILDNODE(*t);
            while (NEXTNODE(last) != NIL){
                last = NEXTNODE(last);
            }
            NEXTNODE(last) = n;
        }
    }
}


/* PRIMITIF */
boolean isTreeEmpty(tree t){
/* Mengembalikan true jika tree kosong */
    if (t == NIL){
        return true;
    }
    else{
        return false;
    }
}

boolean isOneNode(tree t){
/* Mengirimkan true jika tree berisi 1 node */
    if (CHILDNODE(t) == NIL){
        return true;
    }
    else{
        return false;
    }
}

int nChild(tree t){
/* Mengirimkan jumlah node pada tree */
    int count = 0;
    AddressTree p = CHILDNODE(t);
    
    while(p != NIL){
        count++;
        p = NEXTNODE(p);
    }
    return count;
}

int height(tree t){
/* Mengirimkan kedalaman tree */
    int h = 0;

    if (isTreeEmpty(t)){
        h = 0;
    }
    else if (isOneNode(t)){
        h = 1;
    }
    else{
        h = 1 + (int) fmax(height(CHILDNODE(t)), height(NEXTNODE(CHILDNODE(t))));
    }

    return h;
}

boolean searchNode(tree t, type x){
/* Mengirimkan true jika x ada di tree */
    boolean found = false;

    if (ROOT(t) == x){
        found = true;
    }
    else{
        AddressTree p = CHILDNODE(t);

        while (p != NIL && !found){
            if (ROOT(p) == x){
                found = true;
            }
        }
    }

    return found;
}

AddressTree addrSearch(tree t, int x){
/* Mengirimkan address node x di tree jika ada */
    boolean found = false;
    AddressTree addr;

    if ((CHILDNODE(t) == NIL) && NEXTNODE(t) == NIL && !found){ // tidak punya child dan tidak punya next
        if (ROOT(t) == x){
            addr = t;
            found = true;
            return addr;
        }
    }
    else if ((NEXTNODE(t) == NIL) && !found){ // punya child, tidak punya next
        if (ROOT(t) == x){
            addr = t;
            found = true;
        }
        if (!found){
            return addrSearch(CHILDNODE(t),x);
        }
        else{
            return addr;
        }
    }
    else if (CHILDNODE(t) == NIL){ // tidak punya child, punya next
        if (ROOT(t) == x){
            addr = t;
            found = true;
        }
        if (!found){
            return addrSearch(NEXTNODE(t),x);
        }
        else{
            return addr;
        }
    }
    else{ // punya child, punya next
        if (ROOT(t) == x){
            addr = t;
            found = true;
        }
        if(!found){
            if (addrSearch(CHILDNODE(t),x) == NULL){
                return addrSearch(NEXTNODE(t),x);
            }
            else{
                return addrSearch(CHILDNODE(t),x);
            }
        }
        else{
            return addr;
        }
    }
}

void printTree(tree t, int max){
/* Menampilkan tree */
/* Mengutamakan print child terlebih dahulu lalu next */
    int i;
    if ((CHILDNODE(t) == NIL) && (NEXTNODE(t) == NIL)){ // tidak punya child dan tidak punya next
        for(i = 0; i < max - height(t); i++){
            printf("  ");
        }
        printf("%d\n", ROOT(t));
    }
    else if (NEXTNODE(t) == NIL){ // punys child dan tidak punya next
        for(i = 0; i < max - height(t); i++){
            printf("  ");
        }
        printf("%d\n", ROOT(t));
        printTree(CHILDNODE(t), max);
    }
    else if (CHILDNODE(t) == NIL) { // tidak punya child dan punya next
        for(i = 0; i < max - height(t); i++){
            printf("  ");
        }
        printf("%d\n", ROOT(t));
        printTree(NEXTNODE(t), max);
    }
    else{ // punya child dan punya next (utamakan print child)
        for(i = 0; i < max - height(t); i++){
            printf("  ");
        }
        printf("%d\n", ROOT(t));
        printTree(CHILDNODE(t), max);
        printTree(NEXTNODE(t), max - 1);
    }
}

void printTreeFin(tree t){
/* Print tree tanpa perlu argumen max */
    int max = height(t);
    printTree(t, max);
}