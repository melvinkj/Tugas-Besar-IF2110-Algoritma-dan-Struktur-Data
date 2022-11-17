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
void copyMatrix(Matrix mIn, Matrix *mOut)
/* Melakukan assignment mOut <- mIn */
{
    int i;
    int j;


    createMatrix(ROW_EFF(mIn), COL_EFF(mIn), mOut);
    *mOut = mIn;

    for (i =0; i< ROW_EFF(mIn); i++){
        for (j=0; i< COL_EFF(mIn); j++){
            ELMTX(*mOut, i, j) = ELMTX(mIn, i, j);
        }
    }
    ROW_EFF(*mOut) = ROW_EFF(mIn);
    COL_EFF(*mOut) = COL_EFF(mIn);
}

void displayMatrix(Matrix m)
{
    /* I.S. m terdefinisi */
    /* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
       dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan newline */
    /* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
    int i, j;
    for (i = 0; i < m.rowEff+2; i++)
    {
        for (j = 0; j < m.colEff+2; j++)
        {
            printf("%c", m.mem[i][j]);
            if (j != (m.colEff + 1))
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

/* ********** Operasi lain ********** */
int countElmt(Matrix m)
/* Mengirimkan banyaknya elemen m */
{
    return (ROW_EFF(m) * COL_EFF(m));
}

Matrix transpose(Matrix m)
/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. menghasilkan salinan transpose dari m, yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
{
    Matrix mNew;
    createMatrix(ROW_EFF(m), COL_EFF(m), &mNew);
    int i;
    int j;

    for (i = 0; i < ROW_EFF(m); i++){
        for (j=0 ; j < COL_EFF(m); j++){
            ELMTX(mNew, i,j ) = ELMTX(m, j, i);
        }
    }
    return mNew;
}
void pTranspose(Matrix *m)
/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
{
    Matrix mNew;
    createMatrix(ROW_EFF(*m), COL_EFF(*m), &mNew);
    copyMatrix(*m, &mNew);

    int i;
    int j;
    for (i = 0; i < ROW_EFF(*m); i++){
        for (j=0 ; j < COL_EFF(*m); j++){
            ELMTX(*m, i,j ) = ELMTX(mNew, j, i);
        }
    }
}

