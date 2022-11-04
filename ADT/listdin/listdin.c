/* Implementasi listdin*/
#include <stdio.h>
#include "listdin.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, ElTypeD capacityd){
   BUFFER(*l)=(ElTypeD*) malloc (capacityd*sizeof(ElTypeD));
   NEFF(*l)=0;
   CAPACITYD(*l)=capacityd;
}
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */

void dealocateList(ListDin *l){
   free(BUFFER(*l));
   CAPACITYD(*l)=0;
   NEFF(*l)=0;
}
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLengthD(ListDin l){
   return NEFF(l);
}
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */

/* *** Selektor INDEKS *** */
IdxType getFirstIdxD(ListDin l){
   return 0;
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
IdxType getLastIdxD(ListDin l){
   return listLengthD(l)-1;
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** Test Indeks yang valid ********** */
boolean isIdxValidD(ListDin l, IdxType i){
   return (i>=0 && i<CAPACITYD(l));
}
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxEff(ListDin l, IdxType i){
   return (i>=0 && i<NEFF(l));
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmptyD(ListDin l){
   return (NEFF(l)==0);
}
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
boolean isFullD(ListDin l){
   return (NEFF(l)==CAPACITYD(l));
}
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readListD(ListDin *l){
   int N;
   scanf("%d",&N);
   while (N<0||N>CAPACITYD(*l)){
      scanf("%d",&N);
   }
   int i;
   if (N!=0){
   for (i=0;i<N;i++){
      scanf("%d",&ELMT(*l,i));  
   }
   }
   NEFF(*l) = N;
}
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
      0 satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
void printListD(ListDin l){
   int i;
   printf("[");
   for (i=0;i<NEFF(l);i++){
      if (i != 0){
         printf(",");
      }
      printf("%d",ELMT(l,i));
   }
   printf("]");
}
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
ListDin plusMinusListD(ListDin l1, ListDin l2, boolean plus){
   ListDin l;
   CreateListDin(&l,CAPACITYD(l1));
   if (plus){
      int i;
      for (i=0;i<NEFF(l1);i++){
         ELMT(l,i)=ELMT(l1,i)+ELMT(l2,i);
      }
   }
   else{
      int i;
      for (i=0;i<NEFF(l1);i++){
         ELMT(l,i)=ELMT(l1,i)-ELMT(l2,i);
      }
   }
   NEFF(l)=NEFF(l1);
   return l;
}
/* Prekondisi : l1 dan l2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqualD(ListDin l1, ListDin l2){
    int i = 0; 
    boolean status = true;
    if (NEFF(l1) != NEFF(l2)){
        status = false;
    }
    else{
        while ((i<NEFF(l1)) && (status)) {
            if (ELMT(l1,i) != ELMT(l2,i)) {
                status = false;
            }
            i++ ;
        }
    }
    return status;
}
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
IdxType indexOfD(ListDin l, ElTypeD val){
   int i = 0;
   while (ELMT(l,i)!=val && i<NEFF(l)){
      i++;
   }
   if (i<NEFF(l)){
      return i;
   }else{
      return IDX_UNDEF;
   }
}
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */

/* ********** NILAI EKSTREM ********** */
void extremeValuesD(ListDin l, ElTypeD *max, ElTypeD *min){
   *max = ELMT(l,0);
   *min = ELMT(l,0);
   int i;
   for (i=0;i<NEFF(l);i++){
      if (*max <= ELMT(l,i)){
         *max = ELMT(l,i);
      }

      if (*min >= ELMT(l,i)){
         *min = ELMT(l,i);
      }
   }
}
/* I.S. List l tidak kosong */
/* F.S. max berisi nilai maksimum l;
        min berisi nilai minimum l */

/* ********** OPERASI LAIN ********** */
void copyList(ListDin lIn, ListDin *lOut){
   CreateListDin(lOut,CAPACITYD(lIn));
   NEFF(*lOut)=NEFF(lIn);
   int i;
   for (i=0;i<NEFF(lIn);i++){
      ELMT(*lOut,i)=ELMT(lIn,i);
   }
}
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */ 
ElTypeD sumList(ListDin l){
   int total = 0;
   int i;
   for (i =0;i<NEFF(l);i++){
      total=total+ELMT(l,i);
   }
   return total;
}
/* Menghasilkan hasil penjumlahan semua elemen l */
/* Jika l kosong menghasilkan 0 */
int countVal(ListDin l, ElTypeD val){
   int count = 0;
   int i;
   for (i=0;i<NEFF(l);i++){
      if (val==ELMT(l,i)){
         count++;
      }
   }
   return count;
}
/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */

/* ********** SORTING ********** */
void sort(ListDin *l, boolean asc){
   int i, j, temp;
   for (i = 0; i < listLengthD(*l)-1; i++){
        for (j = 0; j < listLengthD(*l)-i-1; j++){
            if (asc) {
                if (ELMT(*l,j) > ELMT(*l,j+1)){
                    temp = ELMT(*l,j);
                    ELMT(*l,j) = ELMT(*l,j+1);
                    ELMT(*l,j+1) = temp;
                }
            }
            else {
                if (ELMT(*l,j) < ELMT(*l,j+1)){
                    temp = ELMT(*l,j) ;
                    ELMT(*l,j) = ELMT(*l,j+1);
                    ELMT(*l,j+1) = temp;
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

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLastD(ListDin *l, ElTypeD val){
   ELMT(*l,NEFF(*l)) = val;
   NEFF(*l)++;    
}
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLastD(ListDin *l, ElTypeD *val){
   *val = ELMT(*l,NEFF(*l)-1);
   NEFF(*l)--;
}
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandList(ListDin *l, int num){
    ListDin temp;
    int newcapacity = CAPACITYD(*l) + num ;
    copyList(*l, &temp) ;
    CAPACITYD(temp) = newcapacity;
    dealocateList(l);
    copyList(temp, l);
}
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */

void shrinkList(ListDin *l, int num){
    ListDin temp;
    int newcapacity = CAPACITYD(*l) - num ;
    copyList(*l, &temp) ;
    CAPACITYD(temp) = newcapacity;
    dealocateList(l);
    copyList(temp, l);
}
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */

void compressList(ListDin *l){
    ListDin temp;
    int newcapacity = NEFF(*l);
    copyList(*l, &temp) ;
    CAPACITYD(temp) = newcapacity;
    dealocateList(l);
    copyList(temp, l);
}
/* Proses : Mengubah capactity sehingga nEff = capacity */
/* I.S. List tidak kosong */
/* F.S. Ukuran nEff = capacity */