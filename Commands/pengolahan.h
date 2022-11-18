/* ADT Pengolahan makanan */

#include <stdio.h>
#include "../ADT/tree/tree.h"
#include "../ADT/sederhana/makanan.h"
#include "../ADT/sederhana/simulator.h"
#include "../ADT/stack_queue/prioqueue.h"
#include "../ADT/list_statik_resep/liststatikresep.h"
#include "../ADT/listdin/listdin.h"
#include "../ADT/list_statik/liststatik.h"
#include "../command/inventory_delivery.h"

#ifndef PENGOLAHAN_H
#define PENGOLAHAN_H

boolean inInventory(PrioQueue q, int ID);
/* Mencari apakah ID makanan berada di inventory atau tidak */

void use(Simulator *s, int ID);
/* Mengurangkan makanan yang digunakan */

void mix(Simulator *s, ListStatikResep resep, ListMakanan listmakanan);
/* Mencampurkan beberapa bahan menjadi makanan baru */

void chop(Simulator *s, ListStatikResep resep, ListMakanan listmakanan);
/* Memotong satu bahan makanan menjadi makanan baru */

void fry(Simulator *s, ListStatikResep resep, ListMakanan listmakanan);
/* Menggoreng satu atau lebih makanan menjadi makanan baru */

void boil(Simulator *s, ListStatikResep resep, ListMakanan listmakanan);
/* Merebus satu bahan makanan */


#endif