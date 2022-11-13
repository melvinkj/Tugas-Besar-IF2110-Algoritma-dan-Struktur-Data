#include <stdio.h>
#include "makanan.h"
#include "simulator.h"

int main(){
    Simulator s;
    createSimulator(&s);
    string nama;
    printf("Nama simulator: ");
    scanWord(&nama);
    printf("\n");
    s.nama = nama;

    return 0;
}