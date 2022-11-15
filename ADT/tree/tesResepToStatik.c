#include "listResepToTree.h"
#include "../char_word_machine/charmachine.h"

// gcc tesResepToStatik.c listResepToTree.c ../char_word_machine/charmachine.c ../list_statik_resep/liststatikresep.c ../tree/tree.c ../sederhana/waktu.c ../char_word_machine/string.c -o a

int main(){
    ListResep l_resep;
    l_resep = READRESEP("../../test/resep_test.txt");

    int i = 0;
    while (l_resep.arr[i].parent_ID != -9999) {
        printf("Parent ID: %d", l_resep.arr[i].parent_ID);
        printf("\n");
        printf("Child ID: ");
        int j;
        for (j = 0; j < l_resep.arr[i].child_ID.nEff; j++){
            printf("%d ", l_resep.arr[i].child_ID.buffer[j]);
        }
        printf(", total child = %d", j);
        printf("\n");
        i++;
    }

    ListStatikResep lr;
    CreateListStatikResep(&lr);
    toStatikResep(&lr,l_resep);

    tree t;
    printf("%d", listLengthResep(lr));

    return 0;
}