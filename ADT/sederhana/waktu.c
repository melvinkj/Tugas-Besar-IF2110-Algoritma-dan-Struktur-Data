/* File: waktu.c */
/* Realisasi ADT TIME */
#include <stdio.h>
#include "waktu.h"

boolean IsTIMEValid(int D, int H, int M)
{
    /* Mengirim true jika D,H,M dapat membentuk T yang valid */
    /* dipakai untuk mentest SEBELUM membentuk sebuah Hari */
    return ((0<=D && D<=29) && (0 <= H && H <= 23) && (0 <= M && M <= 59));
}

/* *** Konstruktor: Membentuk sebuah TIME dari komponen-komponennya *** */
void CreateTime(TIME *T, int DD, int HH, int MM)
{
    /* Membentuk sebuah TIME dari komponen-komponennya yang valid */
    /* Prekondisi : DD, HH, MM valid untuk membentuk TIME */
    Day(*T) = DD;
    Hour(*T) = HH;
    Minute(*T) = MM;
}
/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void TulisTIME(TIME T)
{
    /* I.S. : T sembarang */
    /* F.S. : Nilai T ditulis dg format DD.HH.MM */
    /* Proses : menulis nilai setiap komponen T ke layar dalam format DD.HH.MM
       tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/
    printf("%d.%d.%d", Day(T), Hour(T), Minute(T));
}

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
long TIMEToMenit(TIME T)
{
    /* Diberikan sebuah TIME, mengkonversi menjadi jumlah menit dari waktu 0.0.0 */
    /* Rumus : menit = 1440*DD + 60*HH + MM */
    /* Nilai maksimum = 1440*29+23*60+59*60 */
    int menit = Day(T) * 1440 + Hour(T) * 60 + Minute(T);
    return menit;
}

TIME MenitToTIME(long N)
{
    /* Mengirim  konversi menit ke TIME */
    /* Catatan: Jika N >= 43200, maka harus dikonversi dulu menjadi jumlah menit yang
       mewakili jumlah menit yang mungkin dalam 30 hari, yaitu dengan rumus:
       N1 = N mod 43200, baru N1 dikonversi menjadi TIME */
    TIME T;
    N %= 43200;
    Day(T) = N /1440;
    Hour(T) = (N%1440)/60;
    Minute(T) = N%60;
    return T;
}

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean TEQ(TIME T1, TIME T2)
{
    /* Mengirimkan true jika T1=T2, false jika tidak */
    return (TIMEToMenit(T1) == TIMEToMenit(T2));
}
boolean TNEQ(TIME T1, TIME T2)
{
    /* Mengirimkan true jika T1 tidak sama dengan T2 */
    return (TIMEToMenit(T1) != TIMEToMenit(T2));
}
boolean TLT(TIME T1, TIME T2)
{
    /* Mengirimkan true jika T1<T2, false jika tidak */
    return (TIMEToMenit(T1) < TIMEToMenit(T2));
}
boolean TGT(TIME T1, TIME T2)
{
    /* Mengirimkan true jika T1>T2, false jika tidak */
    return (TIMEToMenit(T1) > TIMEToMenit(T2));
}

/* *** Operator aritmatika TIME *** */
TIME NextMenit(TIME T)
{
    /* Mengirim 1 menit setelah T dalam bentuk TIME */
    return MenitToTIME(TIMEToMenit(T) + 1);
}
TIME NextMenit(TIME T, int N)
{
    /* Mengirim N menit setelah T dalam bentuk TIME */
    return MenitToTIME(TIMEToMenit(T) + N);
}
TIME PrevMenit(TIME T)
{
    /* Mengirim 1 menit sebelum T dalam bentuk TIME */
    return MenitToTIME(TIMEToMenit(T) - 1 + 43200);
}
TIME PrevNMenit(TIME T, int N)
{
    /* Mengirim N menit sebelum T dalam bentuk TIME */
    return MenitToTIME(TIMEToMenit(T) - (N%43200) + 43200);
}
/* *** Kelompok Operator Aritmetika *** */
long Durasi(TIME TAw, TIME TAkh)
{
    /* Mengirim TAkh-TAw dlm Menit, dengan kalkulasi */
    /* Jika TAw > TAkh, maka TAkh adalah 30 hari setelah TAw */
    long time = TIMEToMenit(TAkh) - TIMEToMenit(TAw) + 43200;
    return (time % 43200);
}