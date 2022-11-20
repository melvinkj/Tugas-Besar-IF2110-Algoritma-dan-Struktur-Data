#include "kulkas.h"
#include <stdio.h>

// Command untuk ngejalanin
// cd command
// gcc driver_kulkas.c kulkas.c ../ADT/matrix/matrix.c ../ADT/sederhana/makanan.c ../ADT/stack_queue/prioqueue.c ../ADT/sederhana/waktu.c ../ADT/char_word_machine/string.c -o driver_kulkas.exe
// ./driver_kulkas.exe

int main(){
    PrioQueue inventory;
    MakeEmpty(&inventory, 10);
    TIME t1,t2 ;
    CreateTime(&t1,0, 0, 1);
    CreateTime(&t2,0, 0, 2);
    string s1,s2;
    createString(&s1);
    createString(&s2);
    s1 = appendCCtoStr(s1, 'a');
    s2 = appendCCtoStr(s2, 'b');

    Makanan makanan1 = CreateMakanan(2, s1, t1, s2, t2, 2, 2);
    Makanan makanan2 = CreateMakanan(3, s2, t1, s2, t2, 2, 2);
    Makanan makanan3 = CreateMakanan(4, s1, t1, s2, t2, 2, 2);

    Enqueue(&inventory, makanan1);
    Enqueue(&inventory, makanan2);
    Enqueue(&inventory, makanan3);
    PrintPrioQueue(inventory);

    Matrix tampilanKulkas = inisialisasiTampilanKulkas();
    ListStatikKulkas listKulkas = inisialisasiListKulkas();

    masukKulkas(&tampilanKulkas, &listKulkas, &inventory);
    printTampilanKulkas(tampilanKulkas);
    printListKulkas(listKulkas);

    masukKulkas(&tampilanKulkas, &listKulkas, &inventory);
    printTampilanKulkas(tampilanKulkas);
    printListKulkas(listKulkas);

    keluarKulkas(&tampilanKulkas, &listKulkas, &inventory);
    printTampilanKulkas(tampilanKulkas);
    printListKulkas(listKulkas);
}