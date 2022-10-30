/* ADT Item */

#include "makanan.h"
/* SELEKTOR */
#define ID_MAKANAN(x) (x).id
#define NAMA_MAKANAN(x) (x).nama
#define WAKTU_KEDALUWARSA(x) (x).waktu_kedaluwarsa
#define LOKASI_AKSI(x) (x).lokasi_aksi
#define LAMA_PENGIRIMAN(x) (x).lama_pengiriman
#define LAMA_PEMROSESAN(x) (x).lama_pemrosesan

/* KONSTRUKTOR */
Makanan CreateMakanan(int id, string nama, TIME kedaluwarsa, string lokasi, TIME pengiriman, TIME pemrosesan){
/* Membentuk makanan dari komponen-komponennya */
    Makanan m;
    
    ID_MAKANAN(m) = id;
    NAMA_MAKANAN(m) = nama;
    WAKTU_KEDALUWARSA(m) = kedaluwarsa;
    LOKASI_AKSI(m) = lokasi;
    LAMA_PENGIRIMAN(m) = pengiriman;
    LAMA_PEMROSESAN(m) = pemrosesan;

    return m;
}