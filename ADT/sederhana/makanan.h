/* ADT Item */

#ifndef MAKANAN_H
#define MAKANAN_H

#include "boolean.h"
#include "point.h"
#include "waktu.h"
#include <stdio.h>
// #include "D:\OneDrive - Institut Teknologi Bandung\File Jimly\College Files\Semester 3\Algoritma & Struktur Data\Tubes\Tugas-Besar-IF2110-Algoritma-dan-Struktur-Data\ADT\char_word_machine\string.h"
#include "../char_word_machine/string.h"

#define UNDEF_WAKTU -1
#define MAX_LISTMAKANAN_CAP 101
/* dipasangkan ke waktu jika bukan perishable item */

// typedef struct{
//     char * content; /* container character */
//     int Length;
// } string;

typedef struct makanan {
  int id; /* ID makanan */
  string nama;    /* nama makanan */
  TIME waktu_kedaluwarsa; /* waktu kedaluwarsa*/
  string lokasi_aksi;  /* lokasi aksi */
  TIME lama_pengiriman; /* waktu yang diperlukan saat berkurang waktu perishable item */
  // TIME lama_pemrosesan; /* waktu yang diperlukan untuk memproses makanan */
  int size_x;
  int size_y;
} Makanan;

typedef struct
{
  Makanan arr[MAX_LISTMAKANAN_CAP];
} ListMakanan;


/* SELEKTOR */
#define ID_MAKANAN(x) (x).id
#define NAMA_MAKANAN(x) (x).nama
#define WAKTU_KEDALUWARSA(x) (x).waktu_kedaluwarsa
#define LOKASI_AKSI(x) (x).lokasi_aksi
#define LAMA_PENGIRIMAN(x) (x).lama_pengiriman
#define SIZE_X(x) (x).size_x
#define SIZE_Y(x) (x).size_y


/* KONSTRUKTOR */
Makanan CreateMakanan(int id, string nama, TIME kedaluwarsa, string lokasi, TIME pengiriman, int size_x, int size_y);
/* Membentuk makanan dari komponen-komponennya */

void CreateListMakanan(ListMakanan *l);

int listMakananLength(ListMakanan l);

void appendListMakanan(ListMakanan *l, Makanan m);

Makanan SearchById(int id, ListMakanan makanan);

#endif