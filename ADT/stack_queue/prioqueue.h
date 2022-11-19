/* File : PrioQueue.h */
/* Definisi ADT Priority Queue dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */
/* Elemen queue terurut membesar berdasarkan elemen time */

#ifndef prioqueue_H
#define prioqueue_H

#include "../sederhana/boolean.h"
#include "../sederhana/makanan.h"
#include "../sederhana/waktu.h"

#define Nil -1
/* Konstanta untuk mendefinisikan address tak terdefinisi */

/* Definisi elemen dan address */
typedef Makanan infotype; /* type infotype sesuai pada makanan */
typedef int address;   /* indeks tabel */
/* Contoh deklarasi variabel bertype PrioQueue : */
/* Versi I : tabel dinamik, Head dan Tail eksplisit, ukuran disimpan */
typedef struct {
    infotype * T;   /* tabel penyimpan elemen */
    address HEAD;  /* alamat penghapusan */
    address TAIL;  /* alamat penambahan */
    int MaxEl;     /* Max elemen queue */
} PrioQueue;
/* Definisi PrioQueue kosong: HEAD=Nil; TAIL=Nil. */
/* Catatan implementasi: T[0] tidak pernah dipakai */

/* ********* AKSES (Selektor) ********* */
/* Jika e adalah infotype dan Q adalah PrioQueue, maka akses elemen : */
#define Time(e)             (e).waktu_kedaluwarsa
#define Time_Delivery(e)    (e).lama_pengiriman
#define Info(e)             (e).nama.content
#define Head(Q)             (Q).HEAD
#define Tail(Q)             (Q).TAIL
#define InfoHead(Q)         (Q).T[(Q).HEAD]
#define InfoTail(Q)         (Q).T[(Q).TAIL]
#define MaxEl(Q)            (Q).MaxEl
#define Elmt(Q,i)           (Q).T[(i)]
        
/* ********* Prototype ********* */
boolean IsPrioQueueEmpty (PrioQueue Q);
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsPrioQueueFull (PrioQueue Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int NBElmt (PrioQueue Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void MakeEmpty (PrioQueue * Q, int Max);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasi(PrioQueue * Q);
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void Enqueue (PrioQueue * Q, infotype X);
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut membesar berdasarkan time */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */

void Enqueue_Delivery (PrioQueue * Q, infotype X);
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut membesar berdasarkan time delivery */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */

void Dequeue (PrioQueue * Q, infotype * X);
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

/* Operasi Tambahan */
void PrintPrioQueue (PrioQueue Q);
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<time-1> <elemen-1>
...
<time-n> <elemen-n>
#
*/

/* remove */
void Remove (PrioQueue * Q, infotype X);
/* Proses: Menghapus X pada Q dengan aturan priority queue, terurut membesar berdasarkan time */
/* I.S. Q tidak mungkin kosong */
/* F.S. Elemen X terhapus dari Queue Q dan Q mungkin kosong */
/* */

void RemoveMakanan (PrioQueue * Q, infotype X);
/* Proses: Menghapus X pada Q dengan aturan priority queue, terurut membesar berdasarkan time */
/* I.S. Q tidak mungkin kosong */
/* F.S. Elemen X terhapus dari Queue Q dan Q mungkin kosong */

/* Operasi Tambahan */
void PrintInventory (PrioQueue Q);
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
    List Makanan di Inventory
    (nama - waktu sisa kedaluwarsa)
    Ayam Goreng - 2 menit
    Ayam Goreng - 5 menit
    Cabai - 3 menit
    Bawang - 1 menit
*/

void PrintDelivery(PrioQueue Q);
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
    List Makanan di Delivery
    (nama - waktu sisa delivery)
    Ayam Goreng - 2 menit
    Ayam Goreng - 5 menit
    Cabai - 3 menit
    Bawang - 1 menit
*/

void copyPrioQueue(PrioQueue Q1, PrioQueue *Q2);
/* I.S. Q1 terdefinisi, mungkin kosong */
/* F.S. Q2 terdefinisi, mungkin kosong */
/* Proses: Mengcopy isi Q1 ke Q2 */


#endif