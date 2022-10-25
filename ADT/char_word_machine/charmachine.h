/* File: charmachine.h */
/* Definisi Mesin Karakter */

#ifndef __MESIN_KAR_H_
#define __MESIN_KAR_H_

#include "boolean.h"
#include "../sederhana/makanan.h"
#include "string.h"
#include "../sederhana/waktu.h"

#define MARK '\n'
/* State Mesin */
extern char currentChar;
extern boolean EOP;

/* Dummy Typedef Matrix */
/* Ukuran maksimum baris dan kolom */
#define ROW_CAP 100
#define COL_CAP 100
typedef char ElType;
typedef struct
{
   ElType mem[ROW_CAP][COL_CAP];
   int rowEff; /* banyaknya/ukuran baris yg terdefinisi */
   int colEff; /* banyaknya/ukuran kolom yg terdefinisi */
} Matrix;

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

void READPETA(Matrix * m, char * filename);
/* Membaca file dan dimasukkan ke dalam matrix.
   I.S. : Matrix sembarang.
   F.S. : Matrix terisi dengan elemen efektif sebanyak rowEff dan colEff.
          Matrix utuh memiliki jumlah kolom colEff + 2 dan jumlah baris rowEff + 2. (2 tambahan baris dan kolom untuk karakter '*');
          Akses matrix dari elemen baris 1 kolom 1 hingga baris ke rowEff + 1 kolom colEff + 1*/


ListMakanan READMAKANAN();


void READRESEP(Matrix * m);


#endif