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
// ElType getElmtDiagonal(Matrix m, IdxType i)
// /* Mengirimkan elemen m(i,i) */
// {
//     if (isIdxEff(m, i, i)){
//         return ELMT(m, i, i);
//     }
// }

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mOut)
/* Melakukan assignment mOut <- mIn */
{
    int i;
    int j;


    createMatrix(ROW_EFF(mIn), COL_EFF(mIn), mOut);
    *mOut = mIn;

    // for (i =0; i< ROW_EFF(mIn); i++){
    //     for (j=0; i< COL_EFF(mIn); j++){
    //         ELMT(*mOut, i, j) = ELMT(mIn, i, j);
    //     }
    // }
    // ROW_EFF(*mOut) = ROW_EFF(mIn);
    // COL_EFF(*mOut) = COL_EFF(mIn);
}

// /* ********** KELOMPOK BACA/TULIS ********** */
// void readMatrix(Matrix *m, int nRow, int nCol)
// /* I.S. isIdxValid(nRow,nCol) */
// /* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
// /* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
// /* Selanjutnya membaca nilai elemen per baris dan kolom */
// /* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
// 1 2 3
// 4 5 6
// 8 9 10
// */
// {
//     int i;
//     int j;
//     int val;

//     createMatrix(nRow, nCol, m);
//     for (i = 0; i < nRow; i++){
//         for (j=0; j < nCol;j++){
//             scanf("%d", &val);
//             ELMT(*m, i, j) = val;
//         }
//     }
// }
void displayMatrix(Matrix m)
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan newline */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
    int i;
    int j;

    for (i=0; i <= getLastIdxRow(m);i++){
        for (j=0; j<= getLastIdxCol(m) ; j++){
            if (j == getLastIdxCol(m)){
                printf("%d", ELMT(m,i,j));
            } else {
                printf("%d ", ELMT(m,i,j));
            }
        }
        printf("\n");
        // if (i != getLastIdxRow(m)){
        //     printf("\n");
        // }
    }

}

// /* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
// Matrix addMatrix(Matrix m1, Matrix m2)
// /* Prekondisi : m1 berukuran sama dengan m2 */
// /* Mengirim hasil penjumlahan matriks: m1 + m2 */
// {
//     int i;
//     int j;
//     Matrix m3;
//     createMatrix(ROW_EFF(m1), COL_EFF(m1), &m3);

//     for (i = 0; i <= getLastIdxRow(m1); i++){
//         for (j=0; j <= getLastIdxRow(m1); j++){
//             ELMT(m3, i, j) = ELMT(m1,i,j) + ELMT(m2,i,j);
//         }
//     }
//     return m3;
// }
// Matrix subtractMatrix(Matrix m1, Matrix m2)
// /* Prekondisi : m1 berukuran sama dengan m2 */
// /* Mengirim hasil pengurangan matriks: salinan m1 – m2 */
// {
//     int i;
//     int j;
//     Matrix m3;
//     createMatrix(ROW_EFF(m1), COL_EFF(m1), &m3);

//     for (i = 0; i <= getLastIdxRow(m1); i++){
//         for (j=0; j <= getLastIdxRow(m1); j++){
//             ELMT(m3, i, j) = ELMT(m1,i,j) - ELMT(m2,i,j);
//         }
//     }
//     return m3;
// }
// Matrix multiplyMatrix(Matrix m1, Matrix m2)
// /* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
// /* Mengirim hasil perkalian matriks: salinan m1 * m2 */
// {
//     Matrix m3;
//     int i, j;
//     int k;
//     int sum ;
//     createMatrix(ROW_EFF(m1), COL_EFF(m2), &m3);

//     for (i = 0 ; i < ROW_EFF(m3); i++){
//         for (j = 0; j < COL_EFF(m3); j++){
//             sum = 0;
//             for (k = 0; k < COL_EFF(m1); k++){
//                 sum = sum + (ELMT(m1, i, k) * ELMT(m2, k, j));
//             }
//             ELMT(m3, i, j) = sum;
//         }
//     }
//     return m3;
// }
// Matrix multiplyByConst(Matrix m, ElType x)
// /* Mengirim hasil perkalian setiap elemen m dengan x */
// {
//     int i;
//     int j;
//     Matrix mNew;
//     createMatrix(ROW_EFF(m), COL_EFF(m), &mNew);
//     for (i = 0; i <= getLastIdxRow(mNew); i++){
//         for (j = 0; j <= getLastIdxCol(mNew) ; j++){
//             ELMT(mNew, i,j) = x*ELMT(m, i, j);
//         }
//     }
//     return mNew;
// }
// void pMultiplyByConst(Matrix *m, ElType k)
// /* I.S. m terdefinisi, k terdefinisi */
// /* F.S. Mengalikan setiap elemen m dengan k */
// {
//     int i;
//     int j;
//     for (i = 0; i <= getLastIdxRow(*m); i++){
//         for (j = 0; j <= getLastIdxCol(*m) ; j++){
//             ELMT(*m, i,j) = k*ELMT(*m, i, j);
//         }
//     }
// }

// /* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
// boolean isMatrixEqual(Matrix m1, Matrix m2)
// /* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
// /* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
// /* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
// {
//     if ((ROW_EFF(m1) != ROW_EFF(m2)) || (COL_EFF(m1) != COL_EFF(m2))){
//         return false;
//     } else {
//         int i;
//         int j;
//         for (i =0 ; i < ROW_EFF(m1); i++){
//             for (j=0; j< COL_EFF(m1) ; j++){
//                 if (ELMT(m1, i,j) != ELMT(m2, i, j)){
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
// }
// boolean isMatrixNotEqual(Matrix m1, Matrix m2)
// /* Mengirimkan true jika m1 tidak sama dengan m2 */
// {
//     return (!(isMatrixEqual(m1, m2)));
// }
// boolean isMatrixSizeEqual(Matrix m1, Matrix m2)
// /* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */
// /* yaitu RowEff(m1) = RowEff (m2) dan ColEff (m1) = ColEff (m2) */
// {
//     return ((ROW_EFF(m1) == ROW_EFF(m2)) && (COL_EFF(m1) == COL_EFF(m2)));
// }

// /* ********** Operasi lain ********** */
// int countElmt(Matrix m)
// /* Mengirimkan banyaknya elemen m */
// {
//     return (ROW_EFF(m) * COL_EFF(m));
// }

// /* ********** KELOMPOK TEST TERHADAP Matrix ********** */
// boolean isSquare(Matrix m)
// /* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
// {
//     return (ROW_EFF(m) == COL_EFF(m));
// }
// boolean isSymmetric(Matrix m)
// /* Mengirimkan true jika m adalah matriks simetri : isSquare(m)
//    dan untuk setiap elemen m, m(i,j)=m(j,i) */
// {
//     if (!isSquare(m)){
//         return false;
//     } else {
//         int i;
//         int j;
//         for (i = 0 ; i < ROW_EFF(m) ; i++){
//             for (j = 0 ; j < COL_EFF(m) ; j++){
//                 if (ELMT(m, i, j) != ELMT(m, j, i)){
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
// }
// boolean isIdentity(Matrix m)
// /* Mengirimkan true jika m adalah matriks satuan: isSquare(m) dan
//    setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
// {
//     if (!isSquare(m)){
//         return false;
//     } else {
//         int i;
//         int j;
//         for (i = 0; i < ROW_EFF(m); i++){
//             for (j = 0; j< COL_EFF(m); j++){
//                 if ((i == j) && (ELMT(m, i, j) != 1)){
//                     return false;
//                 }
//                 if ((i != j) && (ELMT(m, i, j) != 0)){
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
// }
// boolean isSparse(Matrix m)
// /* Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi:
//    hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
// {
//     int i;
//     int j;
//     int count =0;
//     for (i = 0; i <= getLastIdxRow(m); i++){
//         for (j = 0; j <= getLastIdxCol(m); j++){
//             if (ELMT(m, i, j) != 0){
//                 count++;
//             }
//         }
//     }

//     return (count <= (0.05*countElmt(m)));

// }
// Matrix negation(Matrix m)
// /* Menghasilkan salinan m dengan setiap elemen dinegasikan (dikalikan -1) */
// {
//     return (multiplyByConst(m, -1));
// }
// void pNegation(Matrix *m)
// /* I.S. m terdefinisi */
// /* F.S. m di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
// {
//     pMultiplyByConst(m, -1);
// }

void swapRow(Matrix *m, int ridx1, int ridx2)
// I.S. m terdefinisi
// F.S. m dengan posisi row idx1 dan row idx2 tertukar
{
    int i;
    int temp;
    for (i = 0; i < COL_EFF(*m); i++){
        temp = ELMT(*m, ridx1, i);
        ELMT(*m, ridx1, i) = ELMT(*m, ridx2, i);
        ELMT(*m, ridx2, i) = temp;
    }
}


// float determinant(Matrix m)
// /* Prekondisi: isSquare(m) */
// /* Menghitung nilai determinan m */


// {
//     if (isSquare(m)){

//         // ALGORITMA REKURSIF
//         int i, j, k;
//         float result = 0;
//         Matrix mnext;
//         if (ROW_EFF(m) == 1){
//             return ELMT(m,0,0);
//         } else {
//             for (i =0; i <ROW_EFF(m); i++){
//                 createMatrix(ROW_EFF(m) -1, COL_EFF(m)-1, &mnext);
//                 for (j=1; j < ROW_EFF(m); j++){
//                     for (k =0; k < COL_EFF(m); k++){

//                         if (k < i) {
//                             ELMT(mnext, j-1, k) = ELMT(m,j,k);
//                         } else if (k > i){
//                             ELMT(mnext, j-1, k-1) = ELMT(m,j,k);
//                         }
//                     }
//                 }
//                 result = result + pow(-1,i) * ELMT(m,0,i) *determinant(mnext);
//             }
//             return result;
//         }

//     }

// }

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
            ELMT(mNew, i,j ) = ELMT(m, j, i);
        }
    }
    return mNew;
}
// void pTranspose(Matrix *m)
// /* I.S. m terdefinisi dan IsSquare(m) */
// /* F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
// {
//     Matrix mNew;
//     createMatrix(ROW_EFF(*m), COL_EFF(*m), &mNew);
//     copyMatrix(*m, &mNew);

//     int i;
//     int j;
//     for (i = 0; i < ROW_EFF(*m); i++){
//         for (j=0 ; j < COL_EFF(*m); j++){
//             ELMT(*m, i,j ) = ELMT(mNew, j, i);
//         }
//     }
// }

POINT LocateS (Matrix peta) {
    POINT S;
    for (int i = 0; i < peta.rowEff; i++) {
        for (int j = 0; j < peta.colEff; j++) {
            if (peta.mem[i][j] == 'S'){
                CreatePoint(&S, i, j);
                break;
            }
        }
    }
    return S;
}

boolean checkAdjacent(char cc, Matrix peta) {
    // Posisi S
    POINT S = LocateS(peta);
    // Adjacent S
    int start_check_x = (S.X - 1) >= 0 ? S.X-1 : 0;
    int end_check_x = (S.X + 1) <= peta.rowEff - 1 ? S.X + 1 : S.X;
    int start_check_y = (S.Y - 1) >= 0 ? S.Y-1 : 0;
    int end_check_y = (S.Y + 1) <= peta.colEff - 1 ? S.Y + 1 : S.Y;

    // Result
    boolean found = false;
    for (int i = start_check_x; i < end_check_x; i++){
        for (int j = start_check_y; j < end_check_y; j++){
            if (peta.mem[i][j] == cc) {
                found = true;
            }
        }
    }
    return found;
}

void move() {
// Mengupdate posisi S pada peta

}