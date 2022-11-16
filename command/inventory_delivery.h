#ifndef INVENTORY_DELIVERY_H
#define INVENTORY_DELIVERY_H
#include "../ADT/stack_queue/prioqueue.h"
#include "../ADT/tree/tree.h"
#include "../ADT/char_word_machine/charmachine.h"

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

void tidakjadibeli(PrioQueue sebelum, PrioQueue sekarang);
/* Mengeluarkan makanan yang tidak jadi dibeli */
/* I.S. sebelum dan sesudah terdefinisi */
/* F.S. makanan yang tidak jadi dibeli akan ditampilkan */

void kembalikedelivery(PrioQueue sebelum, PrioQueue sekarang);
/* Mengembalikan makanan yang tidak jadi masuk ke inventory */
/* I.S. sebelum dan sesudah terdefinisi */
/* F.S. makanan yang tidak jadi masuk ke inventory akan ditampilkan */

// void tidakjadipengolahan(PrioQueue sebelum, PrioQueue sekarang, ListResep resep);
/* Mengeluarkan makanan yang tidak jadi diproses */
/* I.S. sebelum dan sesudah terdefinisi */
/* F.S. makanan yang tidak jadi diproses akan ditampilkan */

void kembalikeinventory(PrioQueue sebelum, PrioQueue sekarang);
/* Mengembalikan makanan yang tidak jadi expired */
/* I.S. sebelum dan sesudah terdefinisi */
/* F.S. makanan yang tidak jadi expired akan ditampilkan */

boolean isEmptyPriorityQueue(PrioQueue P);
/* Mengembalikan true jika PrioQueue kosong */

#endif