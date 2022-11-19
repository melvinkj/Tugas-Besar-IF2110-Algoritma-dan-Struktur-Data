#include <stdio.h>
#include "../ADT/sederhana/makanan.h"
#include "../ADT/sederhana/simulator.h"
#include "../ADT/stack_queue/prioqueue.h"
#include "../ADT/list_statik_resep/liststatikresep.h"
#include "../ADT/listdin/listdin.h"
#include "../ADT/list_statik/liststatik.h"
#include "../ADT/char_word_machine/wordmachine.h"
#include "inventory_delivery.h"

#ifndef PEMESANAN_H
#define PEMESANAN_H


void buy (Simulator *s, ListMakanan LM, ListMakanan *listKedaluwarsa, ListMakanan *listDiterima);
/* Membeli makanan dan memasukannya ke dalam delivery queue*/

#endif