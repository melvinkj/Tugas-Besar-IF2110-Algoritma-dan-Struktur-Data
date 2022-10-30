#include <stdio.h>
#include "charmachine.h"
#include "wordmachine.h"
// Driver ADT Mesin Karakter & Kata

// Run path : gcc wordmachine.c charmachine.c driverCharWordMachine.c -o a


int main () {
    Matrix m;
    char scanf_enter;
    char filename[100];
    printf("Masukkan nama file peta : ");
    scanf("%99s%c", filename, &scanf_enter);
    printf("\nHasil konfigurasi: \n");
    READPETA(&m, filename);
    displayMatrix(m);
    printf("Row : %d\n", m.rowEff);
    printf("Col : %d\n", m.colEff);
    Word command;
    scanWord(&command, "Masukkan Command : ");
    char * ans = commandOptions(command);
    printf("Command yang diberikan : %s", ans);
    return 0;
}