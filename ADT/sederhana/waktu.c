/* File: time.c */
/* Realisasi ADT TIME */
#include <stdio.h>
#include "waktu.h"

boolean IsTIMEValid(int H, int M, int S)
{
    /* Mengirim true jika H,M,S dapat membentuk T yang valid */
    /* dipakai untuk mentest SEBELUM membentuk sebuah Jam */
    return ((0 <= H && H <= 23) && (0 <= M && M <= 59) && (0 <= S && S <= 59));
}

/* *** Konstruktor: Membentuk sebuah TIME dari komponen-komponennya *** */
void CreateTime(TIME *T, int HH, int MM, int SS)
{
    /* Membentuk sebuah TIME dari komponen-komponennya yang valid */
    /* Prekondisi : HH, MM, SS valid untuk membentuk TIME */
    Hour(*T) = HH;
    Minute(*T) = MM;
    Second(*T) = SS;
}
/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaTIME(TIME *T)
{
    /* I.S. : T tidak terdefinisi */
    /* F.S. : T terdefinisi dan merupakan jam yang valid */
    /* Proses : mengulangi membaca komponen HH, MM, SS sehingga membentuk T */
    /* yang valid. Tidak mungkin menghasilkan T yang tidak valid. */
    /* Pembacaan dilakukan dengan mengetikkan komponen HH, MM, SS
       dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
    /* Jika TIME tidak valid maka diberikan pesan: "Jam tidak valid", dan pembacaan
       diulangi hingga didapatkan jam yang valid. */
    /* Contoh:
       60 3 4
       Jam tidak valid
       1 3 4
       --> akan terbentuk TIME <1,3,4> */
    int HH, MM, SS;
    scanf("%d %d %d", &HH, &MM, &SS);
    while (IsTIMEValid(HH, MM, SS) != true)
    {
        printf("Jam tidak valid\n");
        scanf("%d %d %d", &HH, &MM, &SS);
    }
    CreateTime(T, HH, MM, SS);
}

void TulisTIME(TIME T)
{
    /* I.S. : T sembarang */
    /* F.S. : Nilai T ditulis dg format HH:MM:SS */
    /* Proses : menulis nilai setiap komponen T ke layar dalam format HH:MM:SS
       tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/
    printf("%d:%d:%d", Hour(T), Minute(T), Second(T));
}

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
long TIMEToDetik(TIME T)
{
    /* Diberikan sebuah TIME, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
    /* Rumus : detik = 3600*HH + 60*MM + SS */
    /* Nilai maksimum = 3600*23+59*60+59 */
    int second = Hour(T) * 3600 + Minute(T) * 60 + Second(T);
    return second;
}

TIME DetikToTIME(long N)
{
    /* Mengirim  konversi detik ke TIME */
    /* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang
       mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus:
       N1 = N mod 86400, baru N1 dikonversi menjadi TIME */
    TIME T;
    if (N >= 86400)
    {
        long int N1 = N % 86400;
        Hour(T) = N1 / 3600;
        Minute(T) = (N1 % 3600) / 60;
        Second(T) = (N1 % 3600) % 60;
    }
    else
    {
        Hour(T) = N / 3600;
        Minute(T) = (N % 3600) / 60;
        Second(T) = (N % 3600) % 60;
    }
    return T;
}

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean TEQ(TIME T1, TIME T2)
{
    /* Mengirimkan true jika T1=T2, false jika tidak */
    return (TIMEToDetik(T1) == TIMEToDetik(T2));
}
boolean TNEQ(TIME T1, TIME T2)
{
    /* Mengirimkan true jika T1 tidak sama dengan T2 */
    return (TIMEToDetik(T1) != TIMEToDetik(T2));
}
boolean TLT(TIME T1, TIME T2)
{
    /* Mengirimkan true jika T1<T2, false jika tidak */
    return (TIMEToDetik(T1) < TIMEToDetik(T2));
}
boolean TGT(TIME T1, TIME T2)
{
    /* Mengirimkan true jika T1>T2, false jika tidak */
    return (TIMEToDetik(T1) > TIMEToDetik(T2));
}

/* *** Operator aritmatika TIME *** */
TIME NextDetik(TIME T)
{
    /* Mengirim 1 detik setelah T dalam bentuk TIME */
    return DetikToTIME(TIMEToDetik(T) + 1);
}
TIME NextNDetik(TIME T, int N)
{
    /* Mengirim N detik setelah T dalam bentuk TIME */
    return DetikToTIME(TIMEToDetik(T) + N);
}
TIME PrevDetik(TIME T)
{
    /* Mengirim 1 detik sebelum T dalam bentuk TIME */
    return DetikToTIME(TIMEToDetik(T) - 1 + 86400);
}
TIME PrevNDetik(TIME T, int N)
{
    /* Mengirim N detik sebelum T dalam bentuk TIME */
    return DetikToTIME(TIMEToDetik(T) - N + 86400);
}
/* *** Kelompok Operator Aritmetika *** */
long Durasi(TIME TAw, TIME TAkh)
{
    /* Mengirim TAkh-TAw dlm Detik, dengan kalkulasi */
    /* Jika TAw > TAkh, maka TAkh adalah 1 hari setelah TAw */
    long time = TIMEToDetik(TAkh) - TIMEToDetik(TAw) + 86400;
    return (time % 86400);
}