#include <stdio.h>
#include "charmachine.h"
#include "wordmachine.h"
// #include "../../moves.h"
// Driver ADT Mesin Karakter & Kata

// Run path : gcc wordmachine.c charmachine.c driverCharWordMachine.c -o a

int main () {
    Matrix m;    
    READPETA(&m, "../../test/peta_test.txt");
    
    
    Word command;
    scanWord(&command, "Masukkan Command : ");
    char * ans = commandOptions(command);
    printf("Command yang diberikan : %s", ans);
    return 0;
}