// Matriks kulkas
// List buat kulkas

#ifndef KULKAS_H
#define KULKAS_H
#include "../ADT/matrix/matrix.h"
#include "../ADT/sederhana/makanan.h"
#include "../ADT/stack_queue/prioqueue.h"

/*  Kamus Umum */
#define CAPACITY 100
#define IDX_MIN 0
#define IDX_UNDEF -1
#define MARK -9999

/* Definisi elemen dan koleksi objek */
typedef struct {
    Makanan makanan;
    int posisi_x;
    int posisi_y;
} element_kulkas;

typedef element_kulkas ElTypeListKulkas;  
typedef int IdxType;
typedef struct {
   ElTypeListKulkas contents[CAPACITY]; 
} ListStatikKulkas;

Matrix kulkas();

/* ********** SELEKTOR ********** */
#define MAKANAN(e) (e).makanan
#define POSISI_X(e) (e).posisi_x
#define POSISI_Y(e) (e).posisi_y
#define ELMTLIST(l, i) (l).contents[(i)]

/* ********** FUNCTION ********** */
int listLengthListKulkas(ListStatikKulkas l);

void deleteFirstListKulkas(ListStatikKulkas *l, ElTypeListKulkas *val);

void insertLastListKulkas(ListStatikKulkas *l, ElTypeListKulkas val);

element_kulkas createElementKulkas(Makanan makanan, int posisi_x, int posisi_y);

void masukKulkas(Matrix * m_tampilan_kulkas, ListStatikKulkas * l_isi_kulkas, PrioQueue * pq);

void keluarKulkas(Matrix * m_tampilan_kulkas,  ListStatikKulkas * l_isi_kulkas, PrioQueue * pq);

void tampilKulkas(Matrix m_tampilan_kulkas);

void printListKulkas(ListStatikKulkas l);

#endif