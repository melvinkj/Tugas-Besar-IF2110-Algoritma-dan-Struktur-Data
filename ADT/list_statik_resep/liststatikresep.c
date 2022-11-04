#include "liststatikresep.h"
#include "../sederhana/boolean.h"
#include <stdio.h>
/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListStatikResep(ListStatikResep *l){
    int i;
    for (i = 0; i < CAPACITY ; i++) {
        ELMTR(*l, i) = MARK;
    }
}
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan MARK */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLengthResep(ListStatikResep l){
    int panjang = 0;
    while (ELMTR(l,panjang) != MARK && panjang < CAPACITY){
        panjang++;
    }
    return panjang;
}
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */  

/* *** Selektor INDEKS *** */
IdxType getFirstIdxResep(ListStatikResep l){
    return 0;
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
IdxType getLastIdxResep(ListStatikResep l){
    return listLengthResep(l)-1;
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** Test Indeks yang valid ********** */
boolean isIdxValidResep(ListStatikResep l, IdxType i){
    return (i>=0 && i<CAPACITY);
}
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxEffResep(ListStatikResep l, IdxType i){
    return (i>=0 && i<listLengthResep(l));
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmptyResep(ListStatikResep l){
    return listLengthResep(l)==0;
}
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
/* *** Test List penuh *** */
boolean isFullResep(ListStatikResep l){
    return listLengthResep(l)==CAPACITY;
}
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readListResep(ListStatikResep *l){
    int n,i;
    CreateListStatikResep(l);
    do {scanf("%d",&n);
    } while (n<0 || n>CAPACITY);
    for (i = 0 ; i<n;i++){
        scanf("%d",&ELMTR(*l,i));
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
void printListResep(ListStatikResep l){
    int i;
    printf("[");
	for (i = 0; isIdxEffResep(l,i) ; i++) {
		if (i != 0) {
			printf(",");
		}
		printf("%d", ELMTR(l,i));
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

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOfResep(ListStatikResep l, elType val){
    int index = 0;
    while (ELMTR(l,index) != val && index<listLengthResep(l)){
        index++;
    }
    if (index<listLengthResep(l)){
        return index;
    }else{
        return IDX_UNDEF;
    }
}
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void insertFirstResep(ListStatikResep *l, elType val){
    int i;
    for (i=getLastIdxResep(*l)+1;i>0;i--){
        ELMTR(*l,i)=ELMTR(*l,i-1);
    }
    ELMTR(*l,0)=val;
}
/* Proses: Menambahkan val sebagai elemen pertama List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen pertama l yang baru */
/* *** Menambahkan elemen pada index tertentu *** */
void insertAtResep(ListStatikResep *l, elType val, IdxType idx){
    int i;
    for (i=getLastIdxResep(*l)+1;i>idx;i--){
        ELMTR(*l,i)=ELMTR(*l,i-1);
    }
    ELMTR(*l,idx)=val;
}
/* Proses: Menambahkan val sebagai elemen pada index idx List */
/* I.S. List l tidak kosong dan tidak penuh, idx merupakan index yang valid di l */
/* F.S. val adalah elemen yang disisipkan pada index idx l */
/* *** Menambahkan elemen terakhir *** */
void insertLastResep(ListStatikResep *l, elType val){
    ELMTR(*l,listLengthResep(*l))=val;
}
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */

/* ********** MENGHAPUS ELEMEN ********** */
/* *** Menghapus elemen pertama *** */
void deleteFirstResep(ListStatikResep *l, elType *val){
    *val=ELMTR(*l,0);
    int i;

    for(i=0;i<listLengthResep(*l)-1;i++){
        ELMTR(*l,i)=ELMTR(*l,i+1);
    }
    ELMTR(*l,listLengthResep(*l)-1)=MARK;
}
/* Proses : Menghapus elemen pertama List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen pertama l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
/* *** Menghapus elemen pada index tertentu *** */
void deleteAtResep(ListStatikResep *l, elType *val, IdxType idx){
    *val=ELMTR(*l,idx);
    int i;

    for(i=idx;i<listLengthResep(*l)-1;i++){
        ELMTR(*l,i)=ELMTR(*l,i+1);
    }
    ELMTR(*l,listLengthResep(*l)-1)=MARK;
}
/* Proses : Menghapus elemen pada index idx List */
/* I.S. List tidak kosong, idx adalah index yang valid di l */
/* F.S. val adalah nilai elemen pada index idx l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
/* *** Menghapus elemen terakhir *** */
void deleteLastResep(ListStatikResep *l, elType *val){
    *val=ELMTR(*l,listLengthResep(*l)-1);
    ELMTR(*l,listLengthResep(*l)-1)=MARK;
}
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */