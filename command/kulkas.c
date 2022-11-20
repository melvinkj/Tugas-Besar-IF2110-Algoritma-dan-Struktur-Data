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
    while (ELMTLIST(l,panjang).posisi_x == -1 && panjang < CAPACITY){
        panjang++;
    }
    return panjang;
}

void insertLastListKulkas(ListStatikKulkas *l, ElTypeListKulkas val){
    ELMTLIST(*l,listLengthKulkas(*l))=val;
}

void deleteFirstListKulkas(ListStatikKulkas *l, ElTypeListKulkas *val){
    *val=ELMTLIST(*l,0);
    int i;

    for(i=0;i<listLengthKulkas(*l)-1;i++){
        ELMTLIST(*l,i)=ELMTLIST(*l,i+1);
    }
    ELMTLIST(*l,listLengthKulkas(*l)-1).posisi_x = -1;
}
void masukKulkas(Matrix * m_tampilan_kulkas, ListStatikKulkas * l_isi_kulkas, PrioQueue * pq) {
    // Keluarin dari pq
    Makanan makanan;
    Dequeue(&pq, &makanan);
    int size_x = makanan.size_x;
    int size_y = makanan.size_y;
    boolean isAvailable = true;

    // Masukin ke dalam matrix
    for (int i=0; i<=10-size_y; i++) {
        for (int j=0; j<=20-size_x; j++) {
            isAvailable = true;

            int k=0;
            while (isAvailable && k<size_y){
                int l=0;
                while (isAvailable && l<size_x){
                    if (ELMTX(*m_tampilan_kulkas, i+k, j+l) != ' ') {
                        isAvailable = false;
                    }
                    l++;
                }
                k++;
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

    if (!isAvailable) {
        printf("Kulkas penuh.\n");
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

void tampilKulkas(Matrix m_tampilan_kulkas) {
    printf("Tampilan kulkas:\n");
    for (int i=0; i<10; i++) {
        for (int j=0; j<20; j++) {
            printf("%c", ELMTX(m_tampilan_kulkas, i, j));
        }
        printf("\n");
    }
}

void printListKulkas(ListStatikKulkas l){
    printf("Isi kulkas:\n");
    int i;
    printf("[");
	for (i = 0; isIdxEffList(l,i) ; i++) {
		if (i != 0) {
			printf(",");
		}
		printf("%d", ELMTLIST(l,i));
	}
	printf("]");
}