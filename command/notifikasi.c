#include "notifikasi.h"

void notifikasi(ListMakanan *listKedaluwarsa, ListMakanan *listDiterima){
    int i = 1;
    int j = 0;
    int lengthKedaluwarsa = listMakananLength(*listKedaluwarsa);
    int lengthDiterima = listMakananLength(*listDiterima);

    if (lengthKedaluwarsa==0 && lengthDiterima == 0){
        printf("Notifikasi : -\n");
    } else {
        printf("Notifikasi :\n");
        while (j < lengthKedaluwarsa) {
            printf("%d. %s kedaluwarsa.. :(\n", i, (*listKedaluwarsa).arr[j].nama.content);
            i++;
            j++;
        }
        j = 0;
        while (j < lengthKedaluwarsa) {
            (*listKedaluwarsa).arr[lengthKedaluwarsa - 1 - j].id = -9999;
            j++;
        }
        j = 0;   
        while (j < lengthDiterima) {
            // printf("%s sudah diterima oleh BNMO!\n", Elmt(*delivery, i).nama.content);
            printf("%d. %s sudah diterima oleh BNMO!\n", i, (*listDiterima).arr[j].nama.content);
            i++;
            j++;
        }
        j = 0;
        while (j < lengthDiterima) {
            (*listDiterima).arr[lengthDiterima - 1 - j].id = -9999;
            j++;
        }
    }
    printf("\n");
}
