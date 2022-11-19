#include "moves.h"
#include "inventory_delivery.h"
#include "undoredo.h"

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
                Peta.mem[i][j] == ' ';
                break;
            }
        }
    }
    return S;
}

void updatePeta(Matrix *Peta, Simulator S) {
    POINT currPoint = { .X = S.posisi.X, .Y = S.posisi.Y };
    Peta->mem[currPoint.Y][currPoint.X] = ' ';
}

boolean checkAdjacent(char cc, Matrix Peta, POINT S)
{
    // Mengecek area 4 kotak (hanya north,west,east,south) dengan S sebagai pusat
    // cc = Karakter yang akan dicek ('T','M','C','F','B')
    // Adjacent S
    // Result
    boolean found = false;
    if (Peta.mem[S.Y + 1][S.X] == cc) found = true;
    if (Peta.mem[S.Y - 1][S.X] == cc) found = true;
    if (Peta.mem[S.Y][S.X + 1] == cc) found = true;
    if (Peta.mem[S.Y][S.X - 1] == cc) found = true;
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

void Move(POINT *S, string direction, Matrix *Peta, Simulator *sim) {
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
            // Peta->mem[x][y] = ' ';
            (S->Y)--;
            // x = S->Y;
            // Peta->mem[x][y] = 'S';
            kurang_waktu_deliv(&Delivery(*sim), &Inventory(*sim));
            kurang_waktu_inv(&Inventory(*sim));
            sim->waktu = NextMenit(sim->waktu);
            addUndo(*sim);
        }
        else {
            printf("Tidak bisa Move North (ada obstacle).\n");
            printf("Posisi S: (%d, %d).\n", S->X, S->Y);
        }
    }
    if (cmpStrType2(move_east_cmd.content, direction.content)){
        // Check East
        if(validateMove(*S, *Peta, false, false, true, false)){
            // Peta->mem[x][y] = ' ';
            (S->X)++;
            // y = S->X;
            // Peta->mem[x][y] = 'S';
            kurang_waktu_deliv(&Delivery(*sim), &Inventory(*sim));
            kurang_waktu_inv(&Inventory(*sim));
            sim->waktu = NextMenit(sim->waktu);
        }
        else {
            printf("Tidak bisa Move East (ada obstacle).\n");
            printf("Posisi S: (%d, %d).\n", S->X, S->Y);
        }
    }
    if (cmpStrType2(move_west_cmd.content, direction.content)){
        // Check West
        if(validateMove(*S, *Peta, true, false, false, false)){
            // Peta->mem[x][y] = ' ';
            (S->X)--;
            // y = S->X;
            // Peta->mem[x][y] = 'S';
            kurang_waktu_deliv(&Delivery(*sim), &Inventory(*sim));
            kurang_waktu_inv(&Inventory(*sim));
            sim->waktu = NextMenit(sim->waktu);
            addUndo(*sim);
        }
        else {
            printf("Tidak bisa Move West (ada obstacle).\n");
            printf("Posisi S: (%d, %d).\n", S->X, S->Y);
        }
    }
    if (cmpStrType2(move_south_cmd.content, direction.content)){
        // Check South
        if(validateMove(*S, *Peta, false, false, false, true)){
            // Peta->mem[x][y] = ' ';
            (S->Y)++;
            // x = S->Y;
            // Peta->mem[x][y] = 'S';
            kurang_waktu_deliv(&Delivery(*sim), &Inventory(*sim));
            kurang_waktu_inv(&Inventory(*sim));
            sim->waktu = NextMenit(sim->waktu);
            addUndo(*sim);
        }
        else {
            printf("Tidak bisa Move South (ada obstacle).\n");
            printf("Posisi S: (%d, %d).\n", S->X, S->Y);
        }
    }
}

void displayPeta(Matrix m, Simulator S)
{
    /* I.S. m terdefinisi */
    /* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
       dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan newline */
    /* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
    int i, j;
    POINT currS = { .X = S.posisi.X , .Y = S.posisi.Y};
    for (i = 0; i < m.rowEff+2; i++)
    {
        for (j = 0; j < m.colEff+2; j++)
        {
            if (i == currS.Y && j == currS.X) {
                printf("S ");    
            } else {
                printf("%c", m.mem[i][j]);
                if (j != (m.colEff + 1))
                {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}