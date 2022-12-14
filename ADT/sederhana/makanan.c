/* ADT Item */

#include "makanan.h"
/* SELEKTOR */
#define ID_MAKANAN(x) (x).id
#define NAMA_MAKANAN(x) (x).nama
#define WAKTU_KEDALUWARSA(x) (x).waktu_kedaluwarsa
#define LOKASI_AKSI(x) (x).lokasi_aksi
#define LAMA_PENGIRIMAN(x) (x).lama_pengiriman

/* KONSTRUKTOR */
Makanan CreateMakanan(int id, string nama, TIME kedaluwarsa, string lokasi, TIME pengiriman, int size_x, int size_y){
/* Membentuk makanan dari komponen-komponennya */
    Makanan m;
    
    ID_MAKANAN(m) = id;
    NAMA_MAKANAN(m) = nama;
    WAKTU_KEDALUWARSA(m) = kedaluwarsa;
    LOKASI_AKSI(m) = lokasi;
    LAMA_PENGIRIMAN(m) = pengiriman;
    SIZE_X(m) = size_x;
    SIZE_Y(m) = size_y;

    return m;
}
void CreateListMakanan(ListMakanan *l){
    int i;
    for (i = 0; i < MAX_LISTMAKANAN_CAP ; i++) {
        (*l).arr[i].id = -9999;
    }
}

int listMakananLength(ListMakanan l){
    int i = 0;
    int panjang = 0;
    while (l.arr[i].id != -9999 && i < MAX_LISTMAKANAN_CAP){
        panjang++;
        i++;
    }
    return panjang;
}
void appendListMakanan(ListMakanan *l, Makanan m){
    int length = listMakananLength(*l);

    (*l).arr[length] = m;
}

Makanan SearchById(int id, ListMakanan l){
    int i = 0;
    boolean found = false;
    while(i < listMakananLength(l) && found == false){
        if(l.arr[i].id == id){
            found = true;
        } else {
            i++;
        }     
    }
    return l.arr[i];
}

