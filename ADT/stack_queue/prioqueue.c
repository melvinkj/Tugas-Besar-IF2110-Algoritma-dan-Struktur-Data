#include <stdio.h>
#include <stdlib.h>
#include "prioqueue.h"

/* ********* Prototype ********* */
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsPrioQueueEmpty (PrioQueue Q){
    return (Head(Q) == Nil && Tail(Q) == Nil);
}
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
boolean IsPrioQueueFull (PrioQueue Q){
    return (Tail(Q) % MaxEl(Q) == Head(Q) - 1);
}

/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
int NBElmt (PrioQueue Q){
    if (IsPrioQueueEmpty(Q)){
        return 0;
    } else if (Head(Q) <= Tail(Q)){
        return (Tail(Q) - Head(Q) + 1);
    } else{
        return (MaxEl(Q) - Head(Q) + Tail(Q) + 1);
    }
}

/* *** Kreator *** */
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
void MakeEmpty (PrioQueue * Q, int Max){
    (*Q).T = (infotype *) malloc ((Max) * sizeof(infotype));
    if ((*Q).T != NULL){
        MaxEl(*Q) = Max;
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    } else{
        MaxEl(*Q) = 0;
    }
}

/* *** Destruktor *** */
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
void DeAlokasi(PrioQueue * Q){
    MaxEl(*Q) = 0;
    free((*Q).T);
}

/* *** Primitif Add/Delete *** */
void Enqueue (PrioQueue * Q, infotype X){
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut membesar berdasarkan time */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
    if (IsPrioQueueEmpty(*Q)){
        Head(*Q) = 0;
        Tail(*Q) = 0;
        InfoTail(*Q) = X;
    } else{
        int i = Tail(*Q);
        while (TLT(Time(X),Time(Elmt(*Q, i)))){
            Elmt(*Q, (i + 1) % MaxEl(*Q)) = Elmt(*Q, i);
            i--;            
        }
        if (TGT(Time(X),Time(Elmt(*Q, i))) || TEQ(Time(X),Time(Elmt(*Q, i)))){
            Elmt(*Q, (i + 1) % MaxEl(*Q)) = X;
        } else{
            Elmt(*Q, (i % MaxEl(*Q))) = X;
        }
        Tail(*Q) = (Tail(*Q) + 1) % MaxEl(*Q);
    }
}
        
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* X merupakan makanan dengan expired kurang dari sama dengan nol */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
void Dequeue (PrioQueue * Q, infotype * X){
    *X = InfoHead(*Q);
    if (NBElmt(*Q) == 1){
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    } else{
        Head(*Q) = (Head(*Q) + 1) % MaxEl(*Q);
    }
}

/* Operasi Tambahan */
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<time-1> <elemen-1>
...
<time-n> <elemen-n>
#
*/
void PrintPrioQueue (PrioQueue Q){
    while (!IsPrioQueueEmpty(Q)){
        infotype X;
        Dequeue(&Q, &X);
        TulisTIME(Time(X));
        printf(" %s\n", Info(X));
    }
    printf("#\n");
}

/* remove */

void Remove (PrioQueue * Q, infotype X){
    int i = Head(*Q);
    while (i != Tail(*Q) && !(Info(Elmt(*Q, i)) == Info(X) && TEQ(Time(Elmt(*Q, i)),Time(X)))){
        i = (i + 1)%MaxEl(*Q);
    }
    if (Info(Elmt(*Q, i)) == Info(X) && TEQ(Time(Elmt(*Q, i)),Time(X))){
        while (i != Tail(*Q)){
            Elmt(*Q, i) = Elmt(*Q, (i + 1)%MaxEl(*Q));
            i = (i + 1)%MaxEl(*Q);
        }
        if (Tail(*Q)==0){
            Tail(*Q) = MaxEl(*Q)-1;
        } else{
            Tail(*Q)--;
        }
    }
}
/* Proses: Menghapus X pada Q dengan aturan priority queue, terurut membesar berdasarkan time */
/* Tail maju dengan mekanisme circular buffer */
/* I.S. Q tidak mungkin kosong */
/* F.S. Elemen X terhapus dari Queue Q dan Q mungkin kosong */

/* Operasi Tambahan */
void PrintInventory (PrioQueue Q){
    int i=1;
    while (!IsPrioQueueEmpty(Q)){
        infotype X;
        Dequeue(&Q, &X);
        printf("%d. %s - ", i, Info(X));
        i++;
        TulisTIME(Time(X));
        printf("\n");
    }
}
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

void PrintDelivery(PrioQueue Q){
    int i=1;
    while (!IsPrioQueueEmpty(Q)){
        infotype X;
        Dequeue(&Q, &X);
        printf("%d. %s - ", i, Info(X));
        i++;
        TulisTIME(Time_Delivery(X));
        printf("\n");
    }
}
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

