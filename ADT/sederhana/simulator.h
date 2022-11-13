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
#define Inventory(s) (s)->inventory
#define Delivery(s) (s)->delivery
#define Kulkas(s) (s)->kulkas

/* *** konstruktor *** */

void createSimulator(Simulator *s);
/* Membentuk Simulator kosong */
/* I.S. sembarang */
/* F.S. Simulator terbentuk */

/* *** dealokasi *** */
void dealokasiSimulator(Simulator *s);
/* Mendealokasi Simulator */
/* I.S. s terdefinisi */
/* F.S. s terdealokasi */

/* *** Operasi Lain *** */
void copySimulator(Simulator *s1, Simulator s2);
/* Menyalin Simulator s2 ke s1 */
/* I.S. s1 sembarang, s2 terdefinisi */
/* F.S. s1 terdefinisi */