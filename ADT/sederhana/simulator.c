
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

void createSimulator(Simulator *s){
/* Membentuk Simulator kosong */
    Nama(*s).content = NULL;
    Nama(*s).Length = 0;
    CreatePoint(&Posisi(*s), 0, 0);
    CreateTime(&Waktu(*s), 0, 0, 0);
    MakeEmpty(&Inventory(*s), 100);
    MakeEmpty(&Delivery(*s), 100);
    createMatrix(10, 20, &Kulkas(*s));
    }


void dealokasiSimulator(Simulator *s){
/* Mendealokasi Simulator */
    DeAlokasi(&Inventory(*s));
    DeAlokasi(&Delivery(*s));
}

void copySimulator(Simulator *s1, Simulator s2){
/* Menyalin Simulator s2 ke s1 */
    Nama(*s1) = Nama(s2);
    Posisi(*s1) = Posisi(s2);
    Waktu(*s1) = Waktu(s2);
    copyPrioQueue(Inventory(s2), &Inventory(*s1));
    copyPrioQueue(Delivery(s2), &Delivery(*s1));
    copyMatrix(Kulkas(s2), &Kulkas(*s1));
}