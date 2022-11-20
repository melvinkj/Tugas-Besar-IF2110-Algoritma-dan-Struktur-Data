#include <stdio.h>
#include "matrix.h"
#include <math.h>
#include "../sederhana/point.h"
#include "../char_word_machine/string.h"


/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void createMatrix(int nRows, int nCols, Matrix *m)
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */
{
    ROW_EFF(*m) = nRows;
    COL_EFF(*m) = nCols;
}
/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mOut){
    ROW_EFF(*mOut) = ROW_EFF(mIn);
    COL_EFF(*mOut) = COL_EFF(mIn);
    int i,j;
    for (i=0;i<ROW_EFF(mIn);i++){
        for (j=0;j<COL_EFF(mIn);j++){
            ELMTX(*mOut,i,j) = ELMTX(mIn,i,j);
        }
    }
}

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