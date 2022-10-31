#ifndef INVENTORY_DELIVERY_H
#define INVENTORY_DELIVERY_H
#include "../ADT/stack_queue/prioqueue.h"

/* *** Operasi Inventory *** */
void kurang_waktu_inv(PrioQueue *inventory);
/* Mengurangi waktu inventory */
/* I.S. inventory terdefinisi */
/* F.S. waktu inventory dikurangi 1 dan jika waktu 0 akan diremove */

/* *** Operasi Delivery *** */
void kurang_waktu_deliv(PrioQueue *delivery,PrioQueue *inventory);
/* Mengurangi waktu delivery */
/* I.S. delivery terdefinisi */
/* F.S. waktu delivery dikurangi 1 dan jika waktu 0 akan dipindahkan ke inventory */


#endif