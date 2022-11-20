#include "notifikasi.h"

void notifikasi(ListMakanan *listKedaluwarsa, ListMakanan *listDiterima, ListMakanan *listBatalBeli, ListMakanan *listJadiBeli, ListMakanan *listKembaliDelivery, ListMakanan *listKeluarDelivery, ListMakanan *listBatalPengolahan, ListMakanan *listJadiPengolahan, ListMakanan *listKembaliInventory, ListMakanan *listKeluarInventory){
    int i = 1;
    int j = 0;
    int lenKedaluwarsa = listMakananLength(*listKedaluwarsa);
    int lenDiterima = listMakananLength(*listDiterima);
    int lenBatalBeli = listMakananLength(*listBatalBeli);
    int lenJadiBeli = listMakananLength(*listJadiBeli);
    int lenKembaliDelivery = listMakananLength(*listKembaliDelivery);
    int lenKeluarDelivery = listMakananLength(*listKeluarDelivery);
    int lenBatalPengolahan = listMakananLength(*listBatalPengolahan);
    int lenJadiPengolahan = listMakananLength(*listJadiPengolahan);
    int lenKembaliInventory = listMakananLength(*listKembaliInventory);
    int lenKeluarInventory = listMakananLength(*listKeluarInventory);
    if (lenKedaluwarsa==0 && lenDiterima == 0 && lenBatalBeli == 0 && lenJadiBeli == 0 && lenKembaliDelivery == 0 && lenKeluarDelivery == 0 && lenBatalPengolahan == 0 && lenJadiPengolahan == 0 && lenKembaliInventory == 0 && lenKeluarInventory == 0){
        printf("Notifikasi : -\n");
    } else {
        printf("Notifikasi :\n");
        while (j < lenKedaluwarsa) {
            printf("%d. %s kedaluwarsa.. :(\n", i, (*listKedaluwarsa).arr[j].nama.content);
            i++;
            j++;
        }
        j = 0;
        while (j < lenKedaluwarsa) {
            (*listKedaluwarsa).arr[lenKedaluwarsa - 1 - j].id = -9999;
            j++;
        }
        j = 0;   
        while (j < lenDiterima) {
            printf("%d. %s sudah diterima oleh BNMO!\n", i, (*listDiterima).arr[j].nama.content);
            i++;
            j++;
        }
        j = 0;
        while (j < lenDiterima) {
            (*listDiterima).arr[lenDiterima - 1 - j].id = -9999;
            j++;
        }
        j = 0;   
        while (j < lenBatalBeli) {
            printf("%d. %s tidak jadi dibeli :(\n", i, (*listBatalBeli).arr[j].nama.content);
            i++;
            j++;
        }
        j = 0;
        while (j < lenBatalBeli) {
            (*listBatalBeli).arr[lenBatalBeli - 1 - j].id = -9999;
            j++;
        }
        j = 0;   
        while (j < lenJadiBeli) {
            printf("%d. %s dibeli\n", i, (*listJadiBeli).arr[j].nama.content);
            i++;
            j++;
        }
        j = 0;
        while (j < lenJadiBeli) {
            (*listJadiBeli).arr[lenJadiBeli - 1 - j].id = -9999;
            j++;
        }
        j = 0;   
        while (j < lenKembaliDelivery) {
            printf("%d. %s kembali ke delivery :(\n", i, (*listKembaliDelivery).arr[j].nama.content);
            i++;
            j++;
        }
        j = 0;
        while (j < lenKembaliDelivery) {
            (*listKembaliDelivery).arr[lenKembaliDelivery - 1 - j].id = -9999;
            j++;
        }
        j = 0;   
        while (j < lenKeluarDelivery) {
            printf("%d. %s masuk ke inventory\n", i, (*listKeluarDelivery).arr[j].nama.content);
            i++;
            j++;
        }
        j = 0;
        while (j < lenKeluarDelivery) {
            (*listKeluarDelivery).arr[lenKeluarDelivery - 1 - j].id = -9999;
            j++;
        }
        j = 0;   
        while (j < lenBatalPengolahan) {
            printf("%d. %s tidak jadi diproses di %s :(\n", i, (*listBatalPengolahan).arr[j].nama.content, (*listBatalPengolahan).arr[j].lokasi_aksi.content);
            i++;
            j++;
        }
        j = 0;
        while (j < lenBatalPengolahan) {
            (*listBatalPengolahan).arr[lenBatalPengolahan - 1 - j].id = -9999;
            j++;
        }
        j = 0;   
        while (j < lenJadiPengolahan) {
            printf("%d. %s diproses di %s\n", i, (*listJadiPengolahan).arr[j].nama.content,(*listJadiPengolahan).arr[j].lokasi_aksi.content );
            i++;
            j++;
        }
        j = 0;
        while (j < lenJadiPengolahan) {
            (*listJadiPengolahan).arr[lenJadiPengolahan - 1 - j].id = -9999;
            j++;
        }
        j = 0;   
        while (j < lenKembaliInventory) {
            printf("%d. %s tidak jadi kedaluwarsa :)\n", i, (*listKembaliInventory).arr[j].nama.content);
            i++;
            j++;
        }
        j = 0;
        while (j < lenKembaliInventory) {
            (*listKembaliInventory).arr[lenKembaliInventory - 1 - j].id = -9999;
            j++;
        }
        j = 0;   
        while (j < lenKeluarInventory) {
            printf("%d. %s kedaluwarsa :(\n", i, (*listKeluarInventory).arr[j].nama.content);
            i++;
            j++;
        }
        j = 0;
        while (j < lenKeluarInventory) {
            (*listKeluarInventory).arr[lenKeluarInventory - 1 - j].id = -9999;
            j++;
        }
    }
    printf("\n");
}
