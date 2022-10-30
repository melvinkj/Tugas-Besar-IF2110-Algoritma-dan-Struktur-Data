/* ADT Tree
   Definisi ADT Tree */

#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "boolean.h"
#include "../sederhana/makanan.h"


/* Definisi Tipe Node*/
typedef int infotype;
typedef struct tNode *AddressTree;
typedef struct tNode {
    infotype infoNode; // nilai node
    AddressTree nextNode; // next node dalam 1 root
    AddressTree childNode; // node child
} Node;
typedef AddressTree tree;

#define NIL NULL
#define ROOT(T) (T)-> infoNode
#define NEXTNODE(T) (T)-> nextNode
#define CHILDNODE(T) (T)-> childNode


/* KONSTRUKTOR */
AddressTree newNode(infotype x);
/* Mengalokasikan memori untuk node baru */

void deallocateNode(AddressTree adr);
/* Membebaskan memori adr */

void createTree(tree *t);
/* Membuat tree kosong*/

void insertFirstNode(tree *t, infotype val);
/* Menambahkan node pertama yang baru */

void insertChild(tree *t, infotype val);
/* Menambahkan node ke tree */


/* PRIMITIF */
boolean isTreeEmpty(tree t);
/* Mengembalikan true jika tree kosong */

boolean isOneNode(tree t);
/* Mengirimkan true jika tree berisi 1 node */

int nChild(tree t);
/* Mengirimkan jumlah node pada tree */

int height(tree t);
/* Mengirimkan kedalaman tree */

boolean searchNode(tree t, infotype x);
/* Mengirimkan true jika x ada di tree */

void printTree(tree t, int max);
/* Menampilkan tree */

void printTreeFin(tree t);
/* Print tree tanpa perlu argumen max */

#endif