#include <stdio.h>
#include "charmachine.h"


int main () {
    ListResep l_resep;
    l_resep = READRESEP();
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
    return 0;
}
