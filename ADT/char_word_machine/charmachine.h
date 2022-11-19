/* File: charmachine.h */
/* Definisi Mesin Karakter */

#ifndef __MESIN_KAR_H_
#define __MESIN_KAR_H_

#include "../sederhana/boolean.h"
#include "../sederhana/makanan.h"
#include "string.h"
#include "../sederhana/waktu.h"
#include "../matrix/matrix.h"
#include "../tree/tree.h"

#define MARKCM '\n'
#define MAX_CAP_RESEP 100
/* State Mesin */
extern char currentChar;
extern boolean EOP;
typedef struct
{
   int *buffer; /* memori tempat penyimpan elemen (container) */
   int nEff;       /* >=0, banyaknya elemen efektif */
   int capacity;   /* ukuran elemen */
} ListDinParser;

typedef struct {
   int parent_ID;
   ListDinParser child_ID;
} Resep;

typedef struct
{
   Resep arr[MAX_CAP_RESEP];
} ListResep;


void START();
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */

void ADV();
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = MARK
          Jika  currentChar = MARK maka EOP akan menyala (true) */

void READPETA(Matrix *m, char * filename);
/* Membaca file dan dimasukkan ke dalam matrix.
   I.S. : Matrix sembarang.
   F.S. : Matrix terisi dengan elemen efektif sebanyak rowEff dan colEff.
          Matrix utuh memiliki jumlah kolom colEff + 2 dan jumlah baris rowEff + 2. (2 tambahan baris dan kolom untuk karakter '*');
          Akses matrix dari elemen baris 1 kolom 1 hingga baris ke rowEff + 1 kolom colEff + 1*/


ListMakanan READMAKANAN(char * filename);
/* Membaca file konfigurasi dan mengembalikan list makanan */

ListResep READRESEP(char * filename);
/* Membaca file konfigurasi dan mengembalikan list resep */

void createResepParser(Resep * resep, int cap);
/* Menginisialisasi resep dengan sebuah list dinamik dengan capacity max = cap
   I.S. : resep sembarang
   F.S. : terbentuk list dinamik kosong pada resep */

void CreateListDinParser(ListDinParser *l, int capacity);
/* Menginisialisasi list dinamik kosong
   I.S. : l sembarang
   F.S. : l terdefinisi, l menjadi kosong dengan capacity = capacity */

void insertLastParser(ListDinParser *l, int child_ID);
/* Menambahkan elemen pada bagian terakhir list. List dinamik mungkin kosong
   I.S. : l terdefinisi
   F.S. : l terdefinisi, child_ID menjadi elemen terakhir pada list */

#endif