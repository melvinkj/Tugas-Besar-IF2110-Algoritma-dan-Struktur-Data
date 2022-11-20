#include <stdio.h>
#include <stdlib.h>
#include "kulkas.h"

Matrix inisialisasiTampilanKulkas() {
    Matrix m;
    createMatrix(10, 20, &m);
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 20; j++) {
            ELMTX(m, i, j) = 'X';
            
        }
    }
    return m;
}

ListStatikKulkas inisialisasiListKulkas() {
    ListStatikKulkas l;
    for (int i=0; i<CAPACITY; i++){
        POSISI_X(ELMTLIST(l, 0))  = IDX_UNDEF;
        POSISI_X(ELMTLIST(l, 0))  = IDX_UNDEF;
    }
    return l;
}

element_kulkas createElementKulkas(Makanan makanan, int posisi_x, int posisi_y) {
    element_kulkas e;
    MAKANAN(e) = makanan;
    POSISI_X(e) = posisi_x;
    POSISI_Y(e) = posisi_y;
    return e;
}

int listLengthKulkas(ListStatikKulkas l){
    int panjang = 0;
    while (ELMTLIST(l,panjang).posisi_x != -1 && panjang < CAPACITY){
        panjang++;
    }
    return panjang;
}

void insertLastListKulkas(ListStatikKulkas *l, ElTypeListKulkas val){
    POSISI_X(ELMTLIST(*l,listLengthKulkas(*l)+1)) = IDX_UNDEF;
    ELMTLIST(*l,listLengthKulkas(*l))=val;
}

void deleteFirstListKulkas(ListStatikKulkas *l, ElTypeListKulkas *val){
    *val=ELMTLIST(*l,0);
    int i;

    for(i=0;i<listLengthKulkas(*l)-1;i++){
        ELMTLIST(*l,i)=ELMTLIST(*l,i+1);
    }
    POSISI_X(ELMTLIST(*l,listLengthKulkas(*l)-1)) = -1;
}
void masukKulkas(Matrix * m_tampilan_kulkas, ListStatikKulkas * l_isi_kulkas, PrioQueue * pq) {
    printf("Memasukkan makanan ke dalam kulkas\n");

    // Keluarin dari pq
    Makanan makanan;
    Dequeue(pq, &makanan);
    int size_x = SIZE_X(makanan);
    int size_y = SIZE_Y(makanan);
    boolean isAvailable = false;

    // Masukin ke dalam matrix
    int i = 0;
    int j = 0;
    while(!isAvailable && i<=10-size_y){
        while(!isAvailable && j<=20-size_y){
            isAvailable = checkKulkasEmptyAtSpot(i,j,size_x,size_y,*m_tampilan_kulkas);

            if (isAvailable) {
                // Perbaruin tampilan dari kulkas
                for (int x=0; x<size_y; x++){
                    for (int y=0; y<size_x; y++) {
                        ELMTX(*m_tampilan_kulkas, i+x, j+y) = Info(makanan)[0];
                    }
                }

                // Masukin ke dalam list statik
                element_kulkas e = createElementKulkas(makanan, i, j);
                insertLastListKulkas(l_isi_kulkas, e);
                break;
            }

            j++;
        }
        i++;
    }

    if (!isAvailable) {
        printf("Kulkas penuh.\n");
    }
}

boolean checkKulkasEmptyAtSpot(int x, int y, int size_x, int size_y, Matrix M){
    for (int i=x; i<x+size_x; i++){
        for (int j=y; j<y+size_y; j++){
            if (ELMTX(M, i, j) != 'X'){
                return false;
            }
        }
    }
    return true;
}

void keluarKulkas(Matrix * m_tampilan_kulkas,  ListStatikKulkas * l_isi_kulkas, PrioQueue * pq) {
printf("Mengeluarkan makanan dari kulkas\n");

    // Keluarin dari list statik
    element_kulkas e;
    deleteFirstListKulkas(l_isi_kulkas, &e);

    // Hilangin dari matriks
    for (int i=e.posisi_y; i<e.posisi_y+e.makanan.size_y; i++) {
        for (int j=e.posisi_x; j<e.posisi_x+e.makanan.size_x; j++) {
            ELMTX(*m_tampilan_kulkas, i, j) = 'X';
        }
    }

    // Masukin ke prio queue
    Enqueue(pq, e.makanan);
}

void printTampilanKulkas(Matrix m_tampilan_kulkas) {
    printf("Tampilan kulkas:\n");
    for (int i=0; i<10; i++) {
        for (int j=0; j<20; j++) {
            printf("%c", ELMTX(m_tampilan_kulkas, i, j));
        }
        printf("\n");
    }
}

void printListKulkas(ListStatikKulkas l){
    if (listLengthKulkas(l) == 0){
        printf("Isi kulkas: kosong\n");
    }
    else{
        printf("Isi kulkas:\n");
        int i;
        for (i = 0; i<listLengthKulkas(l) ; i++) {
            printf("%d. %s - ", i+1, Info(ELMTLIST(l,i).makanan));
            TulisTIME(Time(ELMTLIST(l,i).makanan));
            printf("\n");
        }
        printf("\n");
    }
}