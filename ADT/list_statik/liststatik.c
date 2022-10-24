#include "liststatik.h"
#include "boolean.h"
#include <stdio.h>
/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListStatik(ListStatik *l){
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan MARK */
    int i;
    for (i=0; i<CAPACITY; i++){
        ELMT(*l, i) = MARK;
    }
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListStatik l){
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */  
    int Neff = 0;
    while (Neff<CAPACITY && ELMT(l,Neff)!= MARK) {
            Neff ++;
    }
    return Neff;
}
/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListStatik l){
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
    return IDX_MIN;
}
IdxType getLastIdx(ListStatik l){
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
    return listLength(l)-1;
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListStatik l, IdxType i){
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
    return (i< CAPACITY && i>= 0);

}
boolean isIdxEff(ListStatik l, IdxType i){
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */
    return (i< listLength(l) && i>= 0);
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty(ListStatik l){
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
/* *** Test List penuh *** */
    return (listLength(l) == 0);
}
boolean isFull(ListStatik l){
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
    return (listLength(l) == CAPACITY);
}
/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readList(ListStatik *l){
/* I.S. l sembarang */
/* F.S. List l terdefinisi */
/* Proses: membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya n */
/*    Pembacaan diulangi sampai didapat n yang benar yaitu 0 <= n <= CAPACITY */
/*    Jika n tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < n <= CAPACITY; Lakukan n kali: 
          Baca elemen mulai dari indeks 0 satu per satu diakhiri enter */
/*    Jika n = 0; hanya terbentuk List kosong */
    int n, i, x;
    CreateListStatik(l);
    do {
    scanf ("%d", &n);
    } while (n<0 || n> CAPACITY);

    for(i=0; i<n; i++){
        scanf("%d", &x);
        ELMT(*l, i) = x;
    }
}
void printList(ListStatik l){
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */
    int i;
    
    printf("[");
    for(i=0; i<listLength(l); i++){
        if(i==listLength(l)-1){
             printf("%d", (ELMT (l,i)));
        } else{
        printf("%d,", (ELMT (l,i)));   
        }
    }
    printf("]");
}
/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika List : Penjumlahan, pengurangan, perkalian, ... *** */
ListStatik plusMinusList(ListStatik l1, ListStatik l2, boolean plus){
/* Prekondisi : l1 dan l2 berukuran sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada 
       indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi 
       elemen l2 pada indeks yang sama */
    ListStatik l;
    int i;

    CreateListStatik(&l);
    
    if (plus) {
        for(i=0; i<=getLastIdx(l1); i++){
            ELMT(l, i) = ELMT(l1, i) + ELMT (l2, i);
        }
    } else {
         for(i=0; i<=getLastIdx(l1); i++){
            ELMT(l, i) = ELMT(l1, i) - ELMT (l2, i);
        }
    }
    return l;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
boolean isListEqual(ListStatik l1, ListStatik l2){
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua 
   elemennya sama */
   int i = 0;
   if(listLength(l1) == listLength(l2)){
        while(i<listLength(l1) ){
            if(ELMT(l1, i) != ELMT (l2, i)) {
                return false;
            } else {
                i++;
            }
        } 
        return true;
    }
    return false;
}


/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOf(ListStatik l, ElType val){
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */
    int i = 0;
    while(i<=(listLength(l)-1)){
        if(ELMT(l, i) == val) {
            return i;
        }
        i++;
    }
    return IDX_UNDEF;
}

/* ********** NILAI EKSTREM ********** */
void extremeValues(ListStatik l, ElType *max, ElType *min){
/* I.S. List l tidak kosong */
/* F.S. Max berisi nilai terbesar dalam l;
        Min berisi nilai terkecil dalam l */
    int i;

    *max = ELMT (l,0);
    *min = ELMT (l,0);
    for(i=1; i<=getLastIdx(l);i++){
        if(ELMT(l, i)<*min){
            *min = ELMT(l, i);
        }
        if(ELMT(l, i)>*max){
            *max = ELMT(l, i);
        }
    }
}

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void insertFirst(ListStatik *l, ElType val){
/* Proses: Menambahkan val sebagai elemen pertama List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen pertama l yang baru */
    int i;
    for(i=getLastIdx((*l)); i>=0; i--){
        ELMT(*l,i+1) = ELMT(*l, i);
    }
    ELMT(*l, 0) = val;
}
/* *** Menambahkan elemen pada index tertentu *** */
void insertAt(ListStatik *l, ElType val, IdxType idx){
/* Proses: Menambahkan val sebagai elemen pada index idx List */
/* I.S. List l tidak kosong dan tidak penuh, idx merupakan index yang valid di l */
/* F.S. val adalah elemen yang disisipkan pada index idx l */
/* *** Menambahkan elemen terakhir *** */
    int i;
    for(i=getLastIdx(*l); i>=idx; i--){
        ELMT(*l,i+1) = ELMT(*l, i);
    }
    ELMT(*l, idx) = val;
}
void insertLast(ListStatik *l, ElType val){
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
    insertAt(l, val, listLength(*l));
}

/* ********** MENGHAPUS ELEMEN ********** */
/* *** Menghapus elemen pertama *** */
void deleteFirst(ListStatik *l, ElType *val){
/* Proses : Menghapus elemen pertama List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen pertama l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
    deleteAt(l, val, 0);
}
/* *** Menghapus elemen pada index tertentu *** */
void deleteAt(ListStatik *l, ElType *val, IdxType idx){
/* Proses : Menghapus elemen pada index idx List */
/* I.S. List tidak kosong, idx adalah index yang valid di l */
/* F.S. val adalah nilai elemen pada index idx l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
    int i ;
    *val = ELMT(*l, idx);
    for(i=idx; i< getLastIdx(*l); i++){
        ELMT(*l, i) = ELMT(*l, i+1);
    }
    ELMT(*l, getLastIdx(*l))= MARK;
}
/* *** Menghapus elemen terakhir *** */
void deleteLast(ListStatik *l, ElType *val){
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
    deleteAt(l, val, getLastIdx(*l));
}

/* ********** SORTING ********** */
void sortList(ListStatik *l, boolean asc){
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */
    
// insertion sort
   int i, j, holder;
    if(asc){
        for(i=1; i < listLength(*l); i++ ){
                holder = ELMT(*l, i);
                j = i -1;
                while (j>=0 && ELMT(*l, j)>holder){
                    ELMT(*l, j+1) = ELMT(*l, j);
                    j--;
                }
                ELMT(*l, j+1) = holder;
        }  
    } else {
        for(i=1; i < listLength(*l); i++ ){
                holder = ELMT(*l, i);
                j = i -1;
                while (j>=0 && ELMT(*l, j)<holder){
                    ELMT(*l, j+1) = ELMT(*l, j);
                    j--;
                }           
                ELMT(*l, j+1) = holder;
        }
    }
}