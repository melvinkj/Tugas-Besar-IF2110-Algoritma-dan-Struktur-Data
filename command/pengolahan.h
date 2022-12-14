/* ADT Pengolahan makanan */

#include <stdio.h>
#include "../ADT/tree/tree.h"
#include "../ADT/sederhana/makanan.h"
#include "../ADT/sederhana/simulator.h"
#include "../ADT/stack_queue/prioqueue.h"
#include "../ADT/list_statik_resep/liststatikresep.h"
#include "../ADT/listdin/listdin.h"
#include "../ADT/list_statik/liststatik.h"
#include "inventory_delivery.h"
#include "../ADT/char_word_machine/wordmachine.h"

#ifndef PENGOLAHAN_H
#define PENGOLAHAN_H

boolean inInventory(PrioQueue q, int ID);
/* Mencari apakah ID makanan berada di inventory atau tidak */

void use(Simulator *s, int ID);
/* Mengurangkan makanan yang digunakan */

void mix(Simulator *s, ListStatikResep resep, ListMakanan listmakanan, ListMakanan *listKedaluwarsa, ListMakanan *listDiterima);
/* Mencampurkan beberapa bahan menjadi makanan baru */

void chop(Simulator *s, ListStatikResep resep, ListMakanan listmakanan, ListMakanan *listKedaluwarsa, ListMakanan *listDiterima);
/* Memotong satu bahan makanan menjadi makanan baru */

void fry(Simulator *s, ListStatikResep resep, ListMakanan listmakanan, ListMakanan *listKedaluwarsa, ListMakanan *listDiterima);
/* Menggoreng satu atau lebih makanan menjadi makanan baru */

void boil(Simulator *s, ListStatikResep resep, ListMakanan listmakanan, ListMakanan *listKedaluwarsa, ListMakanan *listDiterima);
/* Merebus satu bahan makanan */


#endif