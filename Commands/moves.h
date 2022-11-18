#ifndef MOVES_H
#define MOVES_H

#include <stdio.h>
#include "../ADT/sederhana/boolean.h"
#include "../ADT/sederhana/point.h"
#include "../ADT/char_word_machine/string.h"
#include "../ADT/sederhana/simulator.h"

POINT LocateS(Matrix Peta);
// Memberikan lokasi Simulator sekarang

void updatePeta(Matrix *Peta, Simulator S);
// Mengupdate peta konfigurasi

boolean checkAdjacent(char cc, Matrix Peta, POINT S);
// Mengecek apakah ada 'cc' di sekitar Simulator

boolean validateMove(POINT S, Matrix Peta ,boolean West, boolean North, boolean East, boolean South);
// Memvalidasi move Simulator tiap dipanggil

void Move(POINT *S, string direction, Matrix *Peta, Simulator *sim);
// Prosedur Move Simulator

void displayPeta(Matrix m, Simulator S);
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan newline */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/

#endif
