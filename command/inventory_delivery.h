#ifndef INVENTORY_DELIVERY_H
#define INVENTORY_DELIVERY_H
#include "../ADT/stack_queue/prioqueue.h"
#include "../ADT/tree/tree.h"
#include "../ADT/char_word_machine/charmachine.h"
#include "../ADT/list_statik_resep/liststatikresep.h"
#include "../ADT/sederhana/makanan.h"

/* *** Operasi Inventory *** */
void kurang_waktu_inv(PrioQueue *inventory, ListMakanan *listKedaluwarsa);
/* Mengurangi waktu inventory */
/* I.S. inventory terdefinisi */
/* F.S. waktu inventory dikurangi 1 dan jika waktu 0 akan diremove */

/* *** Operasi Delivery *** */
void kurang_waktu_deliv(PrioQueue *delivery,PrioQueue *inventory, ListMakanan *listDiterima);
/* Mengurangi waktu delivery */
/* I.S. delivery terdefinisi */
/* F.S. waktu delivery dikurangi 1 dan jika waktu 0 akan dipindahkan ke inventory */

void tidakjadibeli(PrioQueue sebelum, PrioQueue sekarang);
/* Mengeluarkan makanan yang tidak jadi dibeli */
/* I.S. sebelum dan sesudah terdefinisi */
/* F.S. makanan yang tidak jadi dibeli akan ditampilkan */

void jadibeli(PrioQueue sebelum, PrioQueue sekarang);

void kembalikedelivery(PrioQueue sebelum, PrioQueue sekarang);
/* Mengembalikan makanan yang tidak jadi masuk ke inventory */
/* I.S. sebelum dan sesudah terdefinisi */
/* F.S. makanan yang tidak jadi masuk ke inventory akan ditampilkan */

void keluardelivery(PrioQueue sebelum, PrioQueue sekarang);

void tidakjadipengolahan(PrioQueue sebelum, PrioQueue sekarang, ListStatikResep resep);
/* Mengeluarkan makanan yang tidak jadi diproses */
/* I.S. sebelum dan sesudah terdefinisi */
/* F.S. makanan yang tidak jadi diproses akan ditampilkan */

void jadipengolahan(PrioQueue sebelum, PrioQueue sekarang, ListStatikResep resep);

void kembalikeinventory(PrioQueue sebelum, PrioQueue sekarang);
/* Mengembalikan makanan yang tidak jadi expired */
/* I.S. sebelum dan sesudah terdefinisi */
/* F.S. makanan yang tidak jadi expired akan ditampilkan */

void keluarinventory(PrioQueue sebelum, PrioQueue sekarang);

boolean isEmptyPriorityQueue(PrioQueue P);
/* Mengembalikan true jika PrioQueue kosong */

#endif