/* File: point.c */
#include <stdio.h>
#include <math.h>
#include "point.h"

/* *** IMPLEMENTASI *** */
/* *** Konstruktor membentuk POINT *** */
void CreatePoint(POINT *P, int X, int Y)
{
    /* Membentuk sebuah POINT dari komponen-komponennya */
    Absis(*P) = X;
    Ordinat(*P) = Y;
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void BacaPOINT(POINT *P)
{
    /* Membaca nilai absis dan ordinat dari keyboard dan membentuk
       POINT P berdasarkan dari nilai absis dan ordinat tersebut */
    /* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
    /* Contoh: 1 2
       akan membentuk POINT <1,2> */
    /* I.S. Sembarang */
    /* F.S. P terdefinisi */
    float X, Y;
    scanf("%f %f", &X, &Y);
    CreatePoint(P, X, Y);
}
void TulisPOINT(POINT P)
{
    /* Nilai P ditulis ke layar dengan format "(X,Y)"
       tanpa spasi, enter, atau karakter lain di depan, belakang,
       atau di antaranya
       Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
    */
    /* I.S. P terdefinisi */
    /* F.S. P tertulis di layar dengan format "(X,Y)" */
    printf("(%d,%d)", Absis(P), Ordinat(P));
}
