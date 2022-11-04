#include <stdio.h>
#include "matrix.h"
#include <math.h>

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

/* *** Selektor "Dunia Matrix" *** */
boolean isMatrixIdxValid(int i, int j)
/* Mengirimkan true jika i, j adalah index yang valid untuk matriks apa pun */
{
    return ( (i >= 0 && i < ROW_CAP) && (j >= 0 && j < COL_CAP));
}

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IdxType getLastIdxRow(Matrix m)
/* Mengirimkan Index baris terbesar m */
{
    return ROW_EFF(m)-1;
}
IdxType getLastIdxCol(Matrix m)
/* Mengirimkan Index kolom terbesar m */
{
    return COL_EFF(m)-1;
}
boolean isIdxEff(Matrix m, IdxType i, IdxType j)
/* Mengirimkan true jika i, j adalah Index efektif bagi m */
{
    return ( (i >= 0 && i < ROW_EFF(m)) && (j >= 0 && j < COL_EFF(m)));
}
ElType getElmtDiagonal(Matrix m, IdxType i)
/* Mengirimkan elemen m(i,i) */
{
    if (isIdxEff(m, i, i)){
        return ELMTX(m, i, i);
    }else{
        return -1;
    }
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

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol)
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10
*/
{
    int i;
    int j;
    int val;

    createMatrix(nRow, nCol, m);
    for (i = 0; i < nRow; i++){
        for (j=0; j < nCol;j++){
            scanf("%d", &val);
            ELMTX(*m, i, j) = val;
        }
    }
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

/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquare(Matrix m)
/* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
{
    return (ROW_EFF(m) == COL_EFF(m));
}
boolean isSymmetric(Matrix m)
/* Mengirimkan true jika m adalah matriks simetri : isSquare(m)
   dan untuk setiap elemen m, m(i,j)=m(j,i) */
{
    if (!isSquare(m)){
        return false;
    } else {
        int i;
        int j;
        for (i = 0 ; i < ROW_EFF(m) ; i++){
            for (j = 0 ; j < COL_EFF(m) ; j++){
                if (ELMTX(m, i, j) != ELMTX(m, j, i)){
                    return false;
                }
            }
        }
        return true;
    }
}

void swapRow(Matrix *m, int ridx1, int ridx2)
// I.S. m terdefinisi
// F.S. m dengan posisi row idx1 dan row idx2 tertukar
{
    int i;
    int temp;
    for (i = 0; i < COL_EFF(*m); i++){
        temp = ELMTX(*m, ridx1, i);
        ELMTX(*m, ridx1, i) = ELMTX(*m, ridx2, i);
        ELMTX(*m, ridx2, i) = temp;
    }
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

