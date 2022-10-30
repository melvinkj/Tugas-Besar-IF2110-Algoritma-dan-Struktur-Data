#include "../stack_queue/prioqueue.h"
#include "point.h"
#include "simulator.h"


Simulator CreateSimulator(string nama, POINT posisi, TIME waktu, PrioQueue inventory, PrioQueue delivery, ListStatik kulkas){
/* Membentuk Simulator dari komponen-komponennya */
    Simulator s;

    Nama(s) = nama;
    Posisi(s) = posisi;
    Waktu(s) = waktu;
    Inventory(s) = inventory;
    Delivery(s) = delivery;
    Kulkas(s) = kulkas;
}