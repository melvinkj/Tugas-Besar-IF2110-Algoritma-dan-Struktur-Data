#include "listResepToTree.h"

/*
int isIn(ListStatikResep lr, int ID){
    boolean found = false;

    int i = 0;
    while(i < listLengthResep(lr) && !found){
        if (ROOT(ELMTR(lr,i)) == ID && !found){
            found = true;
        }
        else{
            i++;
        }
    }

    if (!found){
        return -1;
    }
    else{
        return i;
    }
}
*/

int locRes(ListStatikResep lr, int ID){
    int i = 0;
    boolean found = false;
    while (i < listLengthResep(lr) && !found){
        if (ROOT(ELMTR(lr,i)) == ID){
            found = true;
        }
        else{
            i++;
        }
    }

    if (!found){
        return -1;
    }
    else{
        return i;
    }
}

AddressTree addrInRes(ListStatikResep lr, int ID){
    boolean found = false;
    AddressTree p;

    int i = 0;
    while(i < listLengthResep(lr) && !found){
        p = addrSearch(ELMTR(lr,i),ID);
        if (p != NULL){
            found = true;
        }
        else{
            i++;
        }
    }
    if (!found){
        return NULL;
    }
    else{
        return p;
    }
}


void toStatikResep(ListStatikResep *lr, ListResep ld){
    int ID;
    AddressTree t;

    // iterasi semua resep
    int i = 0;
    while (ld.arr[i].parent_ID != -9999){
        printf("i: %d\n",i);
        // ambil ID pertama
        ID = ld.arr[i].parent_ID;

        if (isEmptyResep(*lr)){
            printf("insert tree pertama\n");
            t = NULL;
            t = newNode(ID);
            for (int j = 0; j < 2 /*ld.arr[i].child_ID.nEff*/; j++){
                insertChild(&t, ld.arr[i].child_ID.buffer[j]);
            }
            insertLastResep(lr,t);
        }
        else{
            printf("alamat: %d\n", addrInRes(*lr,ID));
            if (addrInRes(*lr,ID) == NULL){
                printf("makanan belum ada\n");
                t = NULL;
                t = newNode(ID);
                for(int j = 0; j < ld.arr[i].child_ID.nEff; j++){
                    insertChild(&t, ld.arr[i].child_ID.buffer[j]);
                }
                insertLastResep(lr,t);
            }
            else{
                printf("makanan sudah ada\n");
                printf(".\n");
                t = NULL;
                t = addrInRes(*lr,ID);
                printf(".\n");
                printf("parent : %d\n", ROOT(t));
                printf(".\n");
                for(int j = 0; j < ld.arr[i].child_ID.nEff; j++){
                    printf("child : %d\n", ld.arr[i].child_ID.buffer[j]);
                    insertChild(&t, ld.arr[i].child_ID.buffer[j]);
                }
            }
        }
        printf("\n");
        /*
        ID = ld.arr[i].parent_ID; // ID int

        if (listLengthResep(*lr) == 0){
            t = newNode(ID);
            for(int j = 0; j < ld.arr[i].child_ID.nEff; j++){
                insertChild(&t, ld.arr[i].child_ID.buffer[j]);
            }
            insertLastResep(lr,t);
        }

        else{
            for (int ii = 0; ii < listLengthResep(*lr); ii++){
                // jika makanan belum ada di liststatik, buat tree baru
                if (addrSearch(ELMTR(*lr,ii), ID) == NULL){
                    t = newNode(ID);
                    for(int j = 0; j < ld.arr[i].child_ID.nEff; j++){
                        insertChild(&t, ld.arr[i].child_ID.buffer[j]);
                    }
                    insertLastResep(lr,t);
                }
                // jika makanan sudah ada di liststatik (baik sebagai root maupun sebagai child)
                else{
                    t = addrSearch(ELMTR(*lr,ii), ID);
                    for(int j = 0; j < ld.arr[i].child_ID.nEff; j++){
                        insertChild(&t, ld.arr[i].child_ID.buffer[j]);
                    }
                    //insertLastResep(lr,t);
                }
                printf("\n");
            }
        }*/
        i++;
    }
}

/*
ListStatikResep lr
CreateListStatikResep(&lr)

ListResep (listdin) -> tree -> ListStatikResep elmt tree
*/