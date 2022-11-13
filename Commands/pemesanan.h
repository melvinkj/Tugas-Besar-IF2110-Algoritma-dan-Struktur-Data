/* ADT Pengolahan makanan */

#include <stdio.h>
#include "../ADT/sederhana/makanan.h"
#include "../ADT/sederhana/simulator.h"
#include "../ADT/stack_queue/prioqueue.h"
#include "../ADT/list_statik_resep/liststatikresep.h"
#include "../ADT/listdin/listdin.h"
#include "../ADT/list_statik/liststatik.h"


void buy(ListMakanan LM, Simulator *s);
/* Membeli makanan dan memasukannya ke dalam delivery queue*/