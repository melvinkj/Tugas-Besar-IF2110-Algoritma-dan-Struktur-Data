#include "../stack_queue/prioqueue.h"
#include "../list_statik/liststatik.h"
#include "point.h"
#include "waktu.h"

typedef struct{
    char * content; /* container character */
    int Length;
} string;

typedef struct simulator {
    string nama;
    POINT posisi;
    TIME waktu;
    PrioQueue inventory;
    PrioQueue delivery;
    ListStatik kulkas;

} Simulator;

#define Nama(s) (s).nama
#define Posisi(s) (s).posisi
#define Waktu(s) (s).waktu
#define Inventory(s) (s).inventory
#define Delivery(s) (s).delivery
#define Kulkas(s) (s).kulkas

Simulator CreateSimulator(string nama, POINT posisi, TIME waktu, PrioQueue inventory, PrioQueue delivery, ListStatik kulkas);
/* Membentuk Simulator dari komponen-komponennya */
