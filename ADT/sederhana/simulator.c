#include "simulator.h"

void createSimulator(Simulator *s){
/* Membentuk Simulator kosong */
    Nama(*s).content = NULL;
    Nama(*s).Length = 0;
    CreatePoint(&Posisi(*s), 0, 0);
    CreateTime(&Waktu(*s), 0, 0, 0);
    MakeEmpty(&Inventory(*s), 100);
    MakeEmpty(&Delivery(*s), 100);
    Kulkas(*s)=inisialisasiTampilanKulkas();
    }

void dealokasiSimulator(Simulator *s){
/* Mendealokasi Simulator */
    DeAlokasi(&Inventory(*s));
    DeAlokasi(&Delivery(*s));
}

void copySimulator(Simulator *s1, Simulator s2){
/* Menyalin Simulator s2 ke s1 */
    (s1)->nama = Nama(s2);
    (s1)->posisi = Posisi(s2);
    (s1)->waktu = Waktu(s2);
    copyPrioQueue(Inventory(s2), &Inventory(*s1));
    copyPrioQueue(Delivery(s2), &Delivery(*s1));
    copyMatrix(Kulkas(s2), &Kulkas(*s1));
}