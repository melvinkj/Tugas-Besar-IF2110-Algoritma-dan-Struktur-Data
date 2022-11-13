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

void toStatikResep(ListStatikResep *lr, ListResep ld){
    int ID;
    AddressTree t;

    // iterasi semua resep
    int i = 0;
    while (ld.arr[i].parent_ID != -9999){
        ID = ld.arr[i].parent_ID; // ID int
    
        for (int ii = 0; ii < listLengthResep(*lr); ii++){
            // jika makanan belum ada di liststatik, buat tree baru
            if (addrSearch(ELMTR(*lr,ii), ID) == NULL){
                t = newNode(ID);
                printf("%d\n", ROOT(t));
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
                insertLastResep(lr,t);
            }
            printTreeFin(t);
            printf("\n");
        }
        i++;
        printf(".\n");
    }
}

/*
ListStatikResep lr
CreateListStatikResep(&lr)

ListResep (listdin) -> tree -> ListStatikResep elmt tree
*/