#include "stack.h"
#include <stdio.h>

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Stack *S){
    Top(*S) = Nil;
}
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas Max */
/* jadi indeksnya antara 0.. Max */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsStackEmpty(Stack S){
    return Top(S) == Nil;
}
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsStackFull(Stack S){
    return Top(S) == Max-1;
}
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack * S, Simulator X){
    Simulator s;
    createSimulator(&s);
    s.nama = X.nama;
    s.posisi = X.posisi;
    s.waktu = X.waktu;
    copyPrioQueue(X.inventory,&s.inventory);
    copyPrioQueue(X.delivery,&s.delivery);
    s.kulkas = X.kulkas;
    Top(*S)++;
    InfoTop(*S) = s;
}
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack * S, Simulator* X){
    *X = InfoTop(*S);
    Top(*S)--;
}
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

void printstack(Stack S){
    int i;
    for(i=Top(S);i>=0;i--){
        PrintPrioQueue(S.T[i].inventory);
    }
}   