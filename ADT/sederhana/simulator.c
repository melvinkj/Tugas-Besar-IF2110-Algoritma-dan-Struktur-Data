
#include "simulator.h"


void CreateSimulator(Simulator s, Matrix peta){
/* Membentuk Simulator dari komponen-komponennya */
    string nama;
    boolean found;
    int i, j;

    char * str;

    // scanf("%s", nama.content);
    Nama(s) = nama;

    found = false;
    i = 0;

    while(i<ROW_EFF(peta) && found == false){
        j = 0;
        while(j<COL_EFF(peta) && found == false){
            if(ELMT(peta, i, j) =='S'){
                CreatePoint(&Posisi(s), i, j);
                found = true;
            } 
            j++;       
        }
        i++;
    }


    CreateTime(&Waktu(s), 0, 0, 0);
    MakeEmpty(&Inventory(s), 100);
    MakeEmpty(&Delivery(s), 100);
    createMatrix(10, 20, &Kulkas(s));
}