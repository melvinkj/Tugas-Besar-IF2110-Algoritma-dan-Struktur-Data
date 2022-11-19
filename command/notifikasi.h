/*  Notifikasi */

#include <stdio.h>
#include "../ADT/sederhana/makanan.h"
#include "../ADT/sederhana/simulator.h"
#include "../ADT/stack_queue/prioqueue.h"
#include "../ADT/listdin/listdin.h"
#include "../ADT/list_statik/liststatik.h"
#include "../ADT/char_word_machine/wordmachine.h"

#ifndef NOTIFIKASI_H
#define NOTIFIKASI_H


void notifikasi(ListMakanan *listKedaluwarsa, ListMakanan *listDiterima, ListMakanan *listBatalBeli, ListMakanan *listJadiBeli, ListMakanan *listKembaliDelivery, ListMakanan *listKeluarDelivery, ListMakanan *listBatalPengolahan, ListMakanan *listJadiPengolahan, ListMakanan *listKembaliInventory, ListMakanan *listKeluarInventory);

#endif