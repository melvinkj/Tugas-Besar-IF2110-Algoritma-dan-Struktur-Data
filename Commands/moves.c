#include "moves.h"
#include "../command/inventory_delivery.h"
#include "../command/undoredo.h"

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
            Peta->mem[x][y] = ' ';
            (S->Y)--;
            x = S->Y;
            Peta->mem[x][y] = 'S';
            addUndo(*sim);
            kurang_waktu_deliv(&Delivery(*sim), &Inventory(*sim));
            kurang_waktu_inv(&Inventory(*sim));
            NextMenit(sim->waktu);
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
            addUndo(*sim);
            kurang_waktu_deliv(&Delivery(*sim), &Inventory(*sim));
            kurang_waktu_inv(&Inventory(*sim));
            NextMenit(sim->waktu);
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
            addUndo(*sim);
            kurang_waktu_deliv(&Delivery(*sim), &Inventory(*sim));
            kurang_waktu_inv(&Inventory(*sim));
            NextMenit(sim->waktu);
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
            addUndo(*sim);
            kurang_waktu_deliv(&Delivery(*sim), &Inventory(*sim));
            kurang_waktu_inv(&Inventory(*sim));
            NextMenit(sim->waktu);
        }
        else {
            printf("Tidak bisa Move South (ada obstacle).\n");
            printf("Posisi S: (%d, %d).\n", S->X, S->Y);
        }
    }
}

