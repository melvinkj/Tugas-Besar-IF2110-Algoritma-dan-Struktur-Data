/* ADT TIME */

#ifndef TIME_H
#define TIME_H

#include "boolean.h"

/* *** Definisi TYPE TIME <HH:MM:SS> *** */
typedef struct { 
   int DD; /* integer [0..30]*/
	int HH; /* integer [0..23] */
	int MM; /* integer [0..59] */
} TIME;

/* *** Notasi Akses: selektor TIME *** */
#define Day(T) (T).DD
#define Hour(T) (T).HH
#define Minute(T) (T).MM

/* File: time.c */
/* Realisasi ADT TIME */
#include <stdio.h>
#include "waktu.h"

boolean IsTIMEValid(int D, int H, int M);
    /* Mengirim true jika D,H,M dapat membentuk T yang valid */
    /* dipakai untuk mentest SEBELUM membentuk sebuah Hari */

/* *** Konstruktor: Membentuk sebuah TIME dari komponen-komponennya *** */
void CreateTime(TIME *T, int DD, int HH, int MM);
    /* Membentuk sebuah TIME dari komponen-komponennya yang valid */
    /* Prekondisi : DD, HH, MM valid untuk membentuk TIME */

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void TulisTIME(TIME T);
    /* I.S. : T sembarang */
    /* F.S. : Nilai T ditulis dg format DD.HH.MM */
    /* Proses : menulis nilai setiap komponen T ke layar dalam format DD.HH.MM
       tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
long TIMEToMenit(TIME T);
    /* Diberikan sebuah TIME, mengkonversi menjadi jumlah menit dari waktu 0.0.0 */
    /* Rumus : menit = 1440*DD + 60*HH + MM */
    /* Nilai maksimum = 1440*29+23*60+59*60 */

TIME MenitToTIME(long N);
    /* Mengirim  konversi detik ke TIME */
    /* Catatan: Jika N >= 43200, maka harus dikonversi dulu menjadi jumlah menit yang
       mewakili jumlah menit yang mungkin dalam 30 hari, yaitu dengan rumus:
       N1 = N mod 43200, baru N1 dikonversi menjadi TIME */

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean TEQ(TIME T1, TIME T2);
    /* Mengirimkan true jika T1=T2, false jika tidak */

boolean TNEQ(TIME T1, TIME T2);
    /* Mengirimkan true jika T1 tidak sama dengan T2 */

boolean TLT(TIME T1, TIME T2);
    /* Mengirimkan true jika T1<T2, false jika tidak */

boolean TGT(TIME T1, TIME T2);
    /* Mengirimkan true jika T1>T2, false jika tidak */

/* *** Operator aritmatika TIME *** */
TIME NextMenit(TIME T);
    /* Mengirim 1 menit setelah T dalam bentuk TIME */
 
TIME NextMenit(TIME T, int N);
    /* Mengirim N menit setelah T dalam bentuk TIME */

TIME PrevMenit(TIME T);
    /* Mengirim 1 menit sebelum T dalam bentuk TIME */

TIME PrevNMenit(TIME T, int N);
    /* Mengirim N menit sebelum T dalam bentuk TIME */

/* *** Kelompok Operator Aritmetika *** */
long Durasi(TIME TAw, TIME TAkh);
    /* Mengirim TAkh-TAw dlm Menit, dengan kalkulasi */
    /* Jika TAw > TAkh, maka TAkh adalah 30 hari setelah TAw */

#endif