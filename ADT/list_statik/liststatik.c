#include "liststatik.h"
#include <stdio.h>
/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListStatik(ListStatik *l){
    int i;
    for (i = 0; i < CAPACITY ; i++) {
        ELMTLIST(*l, i) = MARK;
    }
}
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan MARK */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListStatik l){
    int panjang = 0;
    while (ELMTLIST(l,panjang) != MARK && panjang < CAPACITY){
        panjang++;
    }
    return panjang;
}
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */  

/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListStatik l){
    return 0;
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
IdxType getLastIdx(ListStatik l){
    return listLength(l)-1;
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListStatik l, IdxType i){
    return (i>=0 && i<CAPACITY);
}
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxEffList(ListStatik l, IdxType i){
    return (i>=0 && i<listLength(l));
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty(ListStatik l){
    return listLength(l)==0;
}
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
/* *** Test List penuh *** */
boolean isFull(ListStatik l){
    return listLength(l)==CAPACITY;
}
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readList(ListStatik *l){
    int n,i;
    CreateListStatik(l);
    do {scanf("%d",&n);
    } while (n<0 || n>CAPACITY);
    for (i = 0 ; i<n;i++){
        scanf("%d",&ELMTLIST(*l,i));
    }
}
/* I.S. l sembarang */
/* F.S. List l terdefinisi */
/* Proses: membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya n */
/*    Pembacaan diulangi sampai didapat n yang benar yaitu 0 <= n <= CAPACITY */
/*    Jika n tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < n <= CAPACITY; Lakukan n kali: 
          Baca elemen mulai dari indeks 0 satu per satu diakhiri enter */
/*    Jika n = 0; hanya terbentuk List kosong */
void printList(ListStatik l){
    int i;
    printf("[");
	for (i = 0; isIdxEffList(l,i) ; i++) {
		if (i != 0) {
			printf(",");
		}
		printf("%d", ELMTLIST(l,i));
	}
	printf("]");
}
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika List : Penjumlahan, pengurangan, perkalian, ... *** */
ListStatik plusMinusList(ListStatik l1, ListStatik l2, boolean plus){
    ListStatik l3;
    CreateListStatik(&l3);
    if (plus){
        int i;
        for (i=0;i<listLength(l1);i++){
            ELMTLIST(l3,i) = ELMTLIST(l1,i) + ELMTLIST(l2,i);
        }
    }else{
        int i;
        for (i=0;i<listLength(l1);i++){
            ELMTLIST(l3,i) = ELMTLIST(l1,i) - ELMTLIST(l2,i);
        }
    }
    return l3;
}
/* Prekondisi : l1 dan l2 berukuran sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada 
       indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi 
       elemen l2 pada indeks yang sama */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
boolean isListEqual(ListStatik l1, ListStatik l2){
    int i = 0;
    while (listLength(l1)==listLength(l2) && ELMTLIST(l1,i)==ELMTLIST(l2,i) && i<listLength(l1)){
        i++;
    }
    return i==listLength(l1) && i==listLength(l2);
}
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua 
   elemennya sama */

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOf(ListStatik l, ElTypeList val){
    int index = 0;
    while (ELMTLIST(l,index) != val && index<listLength(l)){
        index++;
    }
    if (index<listLength(l)){
        return index;
    }else{
        return IDX_UNDEF;
    }
}
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMTLIST(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */

/* ********** NILAI EKSTREM ********** */
void extremeValues(ListStatik l, ElTypeList *max, ElTypeList *min){
    *min = ELMTLIST(l, 0);
    *max = ELMTLIST(l, 0);
    int i;
    for (i=1;isIdxEffList(l,i);i++){
        if (ELMTLIST(l,i) > *max) {
            *max = ELMTLIST(l,i);
        }
        if (ELMTLIST(l,i) < *min) {
            *min = ELMTLIST(l,i);
        }
    }
}
/* I.S. List l tidak kosong */
/* F.S. Max berisi nilai terbesar dalam l;
        Min berisi nilai terkecil dalam l */

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void insertFirst(ListStatik *l, ElTypeList val){
    int i;
    for (i=getLastIdx(*l)+1;i>0;i--){
        ELMTLIST(*l,i)=ELMTLIST(*l,i-1);
    }
    ELMTLIST(*l,0)=val;
}
/* Proses: Menambahkan val sebagai elemen pertama List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen pertama l yang baru */
/* *** Menambahkan elemen pada index tertentu *** */
void insertAt(ListStatik *l, ElTypeList val, IdxType idx){
    int i;
    for (i=getLastIdx(*l)+1;i>idx;i--){
        ELMTLIST(*l,i)=ELMTLIST(*l,i-1);
    }
    ELMTLIST(*l,idx)=val;
}
/* Proses: Menambahkan val sebagai elemen pada index idx List */
/* I.S. List l tidak kosong dan tidak penuh, idx merupakan index yang valid di l */
/* F.S. val adalah elemen yang disisipkan pada index idx l */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListStatik *l, ElTypeList val){
    ELMTLIST(*l,listLength(*l))=val;
}
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */

/* ********** MENGHAPUS ELEMEN ********** */
/* *** Menghapus elemen pertama *** */
void deleteFirst(ListStatik *l, ElTypeList *val){
    *val=ELMTLIST(*l,0);
    int i;

    for(i=0;i<listLength(*l)-1;i++){
        ELMTLIST(*l,i)=ELMTLIST(*l,i+1);
    }
    ELMTLIST(*l,listLength(*l)-1)=MARK;
}
/* Proses : Menghapus elemen pertama List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen pertama l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
/* *** Menghapus elemen pada index tertentu *** */
void deleteAt(ListStatik *l, ElTypeList *val, IdxType idx){
    *val=ELMTLIST(*l,idx);
    int i;

    for(i=idx;i<listLength(*l)-1;i++){
        ELMTLIST(*l,i)=ELMTLIST(*l,i+1);
    }
    ELMTLIST(*l,listLength(*l)-1)=MARK;
}
/* Proses : Menghapus elemen pada index idx List */
/* I.S. List tidak kosong, idx adalah index yang valid di l */
/* F.S. val adalah nilai elemen pada index idx l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
/* *** Menghapus elemen terakhir *** */
void deleteLast(ListStatik *l, ElTypeList *val){
    *val=ELMTLIST(*l,listLength(*l)-1);
    ELMTLIST(*l,listLength(*l)-1)=MARK;
}
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */

/* ********** SORTING ********** */
void sortList(ListStatik *l, boolean asc){
    int i, j, temp;
    for (i = 0; i < listLength(*l)-1; i++){
        for (j = 0; j < listLength(*l)-i-1; j++){
            if (asc) {
                if (ELMTLIST(*l,j) > ELMTLIST(*l,j+1)){
                    temp = ELMTLIST(*l,j);
                    ELMTLIST(*l,j) = ELMTLIST(*l,j+1);
                    ELMTLIST(*l,j+1) = temp;
                }
            }
            else {
                if (ELMTLIST(*l,j) < ELMTLIST(*l,j+1)){
                    temp = ELMTLIST(*l,j) ;
                    ELMTLIST(*l,j) = ELMTLIST(*l,j+1);
                    ELMTLIST(*l,j+1) = temp;
                }
            }
        }
    }
}
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */
