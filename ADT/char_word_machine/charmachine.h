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

#define MARK '\n'
/* State Mesin */
extern char currentChar;
extern boolean EOP;
typedef struct
{
   int *buffer; /* memori tempat penyimpan elemen (container) */
   int nEff;       /* >=0, banyaknya elemen efektif */
   int capacity;   /* ukuran elemen */
} ListDin;

typedef struct {
   int parent_ID;
   ListDin child_ID;
} Resep;

// typedef struct
// {
   
// };


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

void READPETA(Matrix * m);
/* Membaca file dan dimasukkan ke dalam matrix.
   I.S. : Matrix sembarang.
   F.S. : Matrix terisi dengan elemen efektif sebanyak rowEff dan colEff.
          Matrix utuh memiliki jumlah kolom colEff + 2 dan jumlah baris rowEff + 2. (2 tambahan baris dan kolom untuk karakter '*');
          Akses matrix dari elemen baris 1 kolom 1 hingga baris ke rowEff + 1 kolom colEff + 1*/


ListMakanan READMAKANAN();

void READRESEP(Matrix * m);

void createResep (Resep * resep);

void CreateListDin(ListDin *l, int capacity);

void insertLast(ListDin *l, int child_ID);


#endif