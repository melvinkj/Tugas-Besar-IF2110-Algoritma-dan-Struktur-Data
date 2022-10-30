/* ADT Tree
   Implementasi ADT Tree*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tree.h"

/* KONSTRUKTOR */
AddressTree newNode(infotype x){
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

void insertFirstNode(tree *t, infotype val){
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

void insertChild(tree *t, infotype val){
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

boolean searchNode(tree t, infotype x){
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

