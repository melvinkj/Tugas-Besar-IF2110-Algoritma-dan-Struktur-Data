#ifndef MOVES_H
#define MOVES_H

#include <stdio.h>
#include "../ADT/sederhana/boolean.h"
#include "../ADT/sederhana/point.h"
#include "../ADT/char_word_machine/string.h"
#include "../ADT/sederhana/simulator.h"

POINT LocateS(Matrix Peta);
// Memberikan lokasi Simulator sekarang

boolean checkAdjacent(char cc, Matrix Peta, POINT S);
// Mengecek apakah ada 'cc' di sekitar Simulator

boolean validateMove(POINT S, Matrix Peta ,boolean West, boolean North, boolean East, boolean South);
// Memvalidasi move Simulator tiap dipanggil

void Move(POINT *S, string direction, Matrix *Peta, Simulator *sim);
// Prosedur Move Simulator

#endif
