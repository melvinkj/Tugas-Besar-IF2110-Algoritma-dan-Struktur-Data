#include <stdio.h>
#include <stdlib.h>
#include "kulkas.h"

Matrix tampilanKulkas() {
    Matrix m;
    createMatrix(10, 20, &m);
    return m;
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
    while (ELMTLIST(l,panjang) != MARK && panjang < CAPACITY){
        panjang++;
    }
    return panjang;
}

void insertLastListKulkas(ListStatikKulkas *l, ElTypeListKulkas val){
    ELMTLIST(*l,listLength(*l))=val;
}

void deleteFirstListKulkas(ListStatikKulkas *l, ElTypeListKulkas *val){
    *val=ELMTLIST(*l,0);
    int i;

    for(i=0;i<listLength(*l)-1;i++){
        ELMTLIST(*l,i)=ELMTLIST(*l,i+1);
    }
    ELMTLIST(*l,listLength(*l)-1)=MARK;
}
void masukKulkas(Matrix * m_tampilan_kulkas, ListStatikKulkas * l_isi_kulkas, PrioQueue * pq) {
    // Keluarin dari pq
    Makanan makanan;
    Dequeue(&pq, &makanan);
    int size_x = makanan.size_x;
    int size_y = makanan.size_y;

    // Masukin ke dalam matrix
    for (int i=0; i<=10-size_y; i++) {
        for (int j=0; j<=20-size_x; j++) {
            boolean isAvailable = true;

            for (int k=0; k<size_y; k++){
                for (int l=0; l<size_x; l++) {
                    if (ELMTX(*m_tampilan_kulkas, i+k, j+l) != ' ') {
                        isAvailable = false;
                    }
                }
            }

            if (isAvailable) {
                for (int k=0; k<size_y; k++){
                    for (int l=0; l<size_x; l++) {
                        ELMTX(*m_tampilan_kulkas, i+k, j+l) = makanan.nama.content[0];
                    }
                }

                // Masukin ke dalam list statik
                element_kulkas e = createElementKulkas(makanan, i, j);
                insertLast(&l_isi_kulkas, e);
                break;
            }
        }
    }
}

void keluarKulkas(Matrix * m_tampilan_kulkas,  ListStatikKulkas * l_isi_kulkas, PrioQueue * pq) {
    // Keluarin dari list statik
    element_kulkas e;
    deleteFirst(&l_isi_kulkas, &e);

    // Hilangin dari matriks
    for (int i=&e.posisi_y; i<e.posisi_y+e.makanan.size_y; i++) {
        for (int j=&e.posisi_x; j<e.posisi_x+e.makanan.size_x; j++) {
            ELMTX(*m_tampilan_kulkas, i, j) = ' ';
        }
    }

    // Masukin ke prio queue
    Enqueue(&pq, e.makanan);
}
