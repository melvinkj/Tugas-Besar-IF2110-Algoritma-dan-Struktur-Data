#include "listResepToTree.h"

char currentChar;
boolean EOP;

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
        // ambil ID pertama
        ID = ld.arr[i].parent_ID;

        if (isEmptyResep(*lr)){
            t = NULL;
            t = newNode(ID);
            for (int j = 0; j < ld.arr[i].child_ID.nEff; j++){
                insertChild(&t, ld.arr[i].child_ID.buffer[j]);
            }
            insertLastResep(lr,t);
            t = NULL;
        }
        else{
            if (addrInRes(*lr,ID) == NULL){
                t = NULL;
                t = newNode(ID);
                for(int j = 0; j < ld.arr[i].child_ID.nEff; j++){
                    insertChild(&t, ld.arr[i].child_ID.buffer[j]);
                }
                insertLastResep(lr,t);
                t = NULL;
            }
            else{
                t = NULL;
                t = addrInRes(*lr,ID);
                for(int j = 0; j < ld.arr[i].child_ID.nEff; j++){
                    insertChild(&t, ld.arr[i].child_ID.buffer[j]);
                }
                t = NULL;
            }
        }
        i++;
    }
}