/* ADT Item */

#ifndef MAKANAN_H
#define MAKANAN_H

#include "boolean.h"
#include "point.h"
#include "waktu.h"
#include <stdio.h>

#define UNDEF_WAKTU -1
/* dipasangkan ke waktu jika bukan perishable item */

typedef struct{
    char * content; /* container character */
    int Length;
} string;

typedef struct makanan {
  int id; /* ID makanan */
  string nama;    /* nama makanan */
  TIME waktu_kedaluwarsa; /* waktu kedaluwarsa*/
  string lokasi_aksi;  /* lokasi aksi */
  TIME lama_pengiriman; /* waktu yang diperlukan saat berkurang waktu perishable item */
} Makanan;

/* SELEKTOR */
#define ID_MAKANAN(x) (x).id
#define NAMA_MAKANAN(x) (x).nama
#define WAKTU_KEDALUWARSA(x) (x).waktu_kedaluwarsa
#define LOKASI_AKSI(x) (x).lokasi_aksi
#define LAMA_PENGIRIMAN(x) (x).lama_pengiriman

/* KONSTRUKTOR */
Makanan CreateMakanan(int id, string nama, TIME kedaluwarsa, string lokasi, TIME pengiriman);
/* Membentuk makanan dari komponen-komponennya */



#endif