#include "../stack_queue/prioqueue.h"
#include "../list_statik/liststatik.h"
#include "point.h"
#include "waktu.h"
#include "../matrix/matrix.h"
#include "../char_word_machine/string.h"


typedef struct simulator {
    string nama;
    POINT posisi;
    TIME waktu;
    PrioQueue inventory;
    PrioQueue delivery;
    Matrix kulkas;

} Simulator;

#define Nama(s) (s).nama
#define Posisi(s) (s).posisi
#define Waktu(s) (s).waktu
#define Inventory(s) (s).inventory
#define Delivery(s) (s).delivery
#define Kulkas(s) (s).kulkas

void CreateSimulator(Simulator s, Matrix peta);
/* Membentuk Simulator dari komponen-komponennya */
