#include "../stack_queue/prioqueue.h"
#include "point.h"

typedef struct{
    char * content; /* container character */
    int Length;
} string;

typedef struct simulator {
    string nama;
    POINT posisi;
    PrioQueue inventory;

} Simulator;

#define Nama(s) (s).nama
#define Posisi(s) (s).posisi
#define Inventory(s) (s).inventory

Simulator CreateSimulator(string nama, POINT posisi, PrioQueue inventory){
/* Membentuk Simulator dari komponen-komponennya */
    Simulator s;

    Nama(s) = nama;
    Posisi(s) = posisi;
    Inventory(s) = inventory;
}