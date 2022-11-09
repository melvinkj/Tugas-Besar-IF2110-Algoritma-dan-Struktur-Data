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

/* ********** Operasi MOVE ********** */
POINT LocateS(Matrix Peta)
{
    POINT S;
    for (int i = 0; i < Peta.rowEff; i++)
    {
        for (int j = 0; j < Peta.colEff; j++)
        {
            if (Peta.mem[i][j] == 'S')
            {
                CreatePoint(&S, j, i);
                break;
            }
        }
    }
    return S;
}

boolean checkAdjacent(char cc, Matrix Peta, POINT S)
{
    // Mengecek area 4 kotak (hanya north,west,east,south) dengan S sebagai pusat
    // cc = Karakter yang akan dicek ('T','M','C','F','B')
    // Adjacent S
    // Result
    boolean found = false;
    if (S.Y + 1 == cc) found = true;
    if (S.Y - 1 == cc) found = true;
    if (S.X + 1 == cc) found = true;
    if (S.X - 1 == cc) found = true;
    // for (int i = S.Y - 1; i <= S.Y + 1; i++)
    // {
    //     for (int j = S.X - 1; j <= S.X + 1; j++)
    //     {
    //         if (Peta.mem[i][j] == cc)
    //         {
    //             found = true;
    //         }
    //     }
    // }
    return found;
}

boolean validateMove(POINT S, Matrix Peta ,boolean West, boolean North, boolean East, boolean South) {
    // Restriction Place
    char arr[7] = {'*','X','T','M','C','F','B'};
    // Set default return
    boolean valid = true;
    // get current coordinate
    int y = S.X, x = S.Y;

    int i = 0;
    // Check if move west
    if (West) {
        while (i < 7 && valid) {
            if (Peta.mem[x][y - 1] == arr[i]){
                valid = false;
            }
            i++;
        }    
    }
    // Check if move east
    if (East) {
        while (i < 7 && valid) {
            if (Peta.mem[x][y + 1] == arr[i]){
                valid = false;
            }
            i++;
        }    
    }
    // Check if move north
    if (North) {
        while (i < 7 && valid) {
            if (Peta.mem[x - 1][y] == arr[i]){
                valid = false;
            }
            i++;
        }    
    }
    // Check if move south
    if (South) {
        while (i < 7 && valid) {
            if (Peta.mem[x + 1][y] == arr[i]){
                valid = false;
            }
            i++;
        }    
    }
    return valid;
}

void Move(POINT *S, string direction, Matrix *Peta) {
    POINT dummyS;
    // Move commands
    string move_north_cmd = {.content = "MOVE NORTH", .Length = 10};
    string move_east_cmd = {.content = "MOVE EAST", .Length = 9};
    string move_west_cmd = {.content = "MOVE WEST", .Length = 9};
    string move_south_cmd = {.content = "MOVE SOUTH", .Length = 10};

    // get coordinate
    int x = S->Y, y = S->X;

    // Process direction
    if (cmpStrType2(move_north_cmd.content, direction.content)){
        // Check North
        if(validateMove(*S, *Peta, false, true, false, false)){
            Peta->mem[x][y] = ' ';
            (S->Y)--;
            x = S->Y;
            Peta->mem[x][y] = 'S';
        }
        else {
            printf("Tidak bisa Move North (ada obstacle).\n");
            printf("Posisi S: (%d, %d).\n", S->X, S->Y);
        }
    }
    if (cmpStrType2(move_east_cmd.content, direction.content)){
        // Check East
        if(validateMove(*S, *Peta, false, false, true, false)){
            Peta->mem[x][y] = ' ';
            (S->X)++;
            y = S->X;
            Peta->mem[x][y] = 'S';
        }
        else {
            printf("Tidak bisa Move East (ada obstacle).\n");
            printf("Posisi S: (%d, %d).\n", S->X, S->Y);
        }
    }
    if (cmpStrType2(move_west_cmd.content, direction.content)){
        // Check West
        if(validateMove(*S, *Peta, true, false, false, false)){
            Peta->mem[x][y] = ' ';
            (S->X)--;
            y = S->X;
            Peta->mem[x][y] = 'S';
        }
        else {
            printf("Tidak bisa Move West (ada obstacle).\n");
            printf("Posisi S: (%d, %d).\n", S->X, S->Y);
        }
    }
    if (cmpStrType2(move_south_cmd.content, direction.content)){
        // Check South
        if(validateMove(*S, *Peta, false, false, false, true)){
            Peta->mem[x][y] = ' ';
            (S->Y)++;
            x = S->Y;
            Peta->mem[x][y] = 'S';
        }
        else {
            printf("Tidak bisa Move South (ada obstacle).\n");
            printf("Posisi S: (%d, %d).\n", S->X, S->Y);
        }
    }
}

