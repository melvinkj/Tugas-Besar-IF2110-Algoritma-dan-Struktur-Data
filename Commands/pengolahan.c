/* Implementasi pengolahan makanan */

#include <stdio.h>
#include "../ADT/tree/tree.h"
#include "../ADT/sederhana/makanan.h"
#include "../ADT/sederhana/simulator.h"
#include "../ADT/stack_queue/prioqueue.h"
#include "../ADT/list_statik_resep/liststatikresep.h"
#include "../ADT/listdin/listdin.h"
#include "pengolahan.h"

boolean inInventory(PrioQueue q, int ID){
/* Mencari apakah ID makanan berada di inventory atau tidak */
    int i = HEAD(q);
    boolean found = false;
    while (i < TAIL(q) && !found){
        if (ID_MAKANAN(q.T[i]) == ID){
            found = true;
        }
    }
    return found;
}

void use(Simulator *s, int ID){
/* Mengurangkan makanan yang digunakan */
    // iterasi inventory sampai mendapatkan bahan makanan
    int i = Head(Inventory(*s));
    boolean found = false;

    while (i < Tail(Inventory(*s)) && !found){
        if (ID_MAKANAN(Elmt(Inventory(*s),i)) == ID){ // jika makanan sudah ketemu
            if (NBElmt(Inventory(*s)) == 1){
                Head(Inventory(*s)) = Nil;
                Tail(Inventory(*s)) = Nil;
            }
            else{
                int j;
                for(j = i; j < Tail(Inventory(*s)); j++){
                    Elmt(Inventory(*s),j) = Elmt(Inventory(*s),j+1);
                }
                Tail(Inventory(*s))--;
            }
            found = true;
        }
        i++;
    }
}

void mix(Simulator *s, ListStatikResep resep, ListMakanan listmakanan){
/* Mencampurkan beberapa bahan menjadi makanan baru */
    // Mengecek bahan makanan yang dapat dimix
    int count = 0;
    int ID, IDsearch;
    Makanan m,mi;
    ListDin pilihan;
    AddressTree addr,p;
    CreateListDin(&pilihan, 20);

    string MIX;
    createString(&MIX);
    MIX.content = "MIX";

    // iterasi lokasi aksi tiap resep
    for (int i = 0; i < listLengthResep(resep); i++){
        ID = ROOT(ELMTR(resep,i));
        m = SearchById(ID, listmakanan);
        if (cmpStrType2(LOKASI_AKSI(m).content, MIX.content)){
            insertLast(&pilihan, ID_MAKANAN(m)); // simpan ID makanan di pilihan
        }
    }

    // print list kemungkinan makanan
    if (isEmpty(pilihan)){
        printf("Tidak ada makanan yang bisa dibuat.\n");
    }
    else{
        printf("List bahan makanan yang bisa dibuat: \n");
        for (int i = 0; i < NEFF(pilihan); i++){
            printf("%d. %s", i+1, NAMA_MAKANAN(m).content);
        }

        // pilih makanan
        int pil;
        printf("Enter command: ");
        scanf("%d", &pil);
        while (pil < 0 || pil > NEFF(pilihan)){
            printf("Enter command: ");
        scanf("%d", &pil);
        }

        if (pil != 0){
            // cek apakah bahan ada di inventory atau tidak
            IDsearch = ELMT(pilihan,pil-1);
            m = SearchById(IDsearch, listmakanan); // makanan

            // cari tree ID makanan di list resep
            boolean found = false;
            int i = 0;
            addr = NULL;
            while (!found && i < listLengthResep(resep)){
                addr = addrSearch(ELMTR(resep,i),IDsearch);
                if (addr == NULL){
                    i++;
                }
            }
            // addr berisi address makanan yang ingin dibuat

        
            ListDin kosong; // list bahan yang tidak ada

            // iterasi semua bahan child makanan dan list makanan yang tidak ada
            p = CHILDNODE(addr);
            while (p != NULL){
                if (!inInventory(Inventory(*s),INFO(p))){
                    insertLast(&kosong, INFO(p));
                }
            }

            // print makanan yang tidak dapat dibuat
            if (!isEmpty(kosong)){
                printf("Gagal membuat %s karena kamu tidak memiliki bahan berikut:\n", NAMA_MAKANAN(m).content);
                for(i = 0; i < NEFF(kosong); i++){
                    mi = SearchById(ELMT(kosong,i), listmakanan);
                    printf("%d. %s", i+1, NAMA_MAKANAN(mi).content);
                }
            }
            // jika dapat dibuat, iterasi tiap childnode untuk dikurangkan di inventory
            else{
                int x;
                int i = 0;
                p = CHILDNODE(addr);
                while (p != NULL){
                    x = INFO(p); // ID makanan yang akan dikurangkan
                    use(s,x);
                    p = NEXT(p);
                }

                printf("%s selesai dibuat dan sudah masuk ke inventory!", NAMA_MAKANAN(m).content);
            }
        }
    }

}

void chop(Simulator *s, ListStatikResep resep, ListMakanan listmakanan){
/* Memotong satu bahan makanan menjadi makanan baru */
    // Mengecek bahan makanan yang dapat dichop
    int count = 0;
    int ID, IDsearch;
    Makanan m,mi;
    ListDin pilihan;
    AddressTree addr,p;
    CreateListDin(&pilihan, 20);

    string CHOP;
    createString(&CHOP);
    CHOP.content = "CHOP";

    // iterasi lokasi aksi tiap resep
    for (int i = 0; i < listLengthResep(resep); i++){
        ID = ROOT(ELMTR(resep,i));
        m = SearchById(ID, listmakanan);
        if (cmpStrType2(LOKASI_AKSI(m).content, CHOP.content)){
            insertLast(&pilihan, ID_MAKANAN(m)); // simpan ID makanan di pilihan
        }
    }

    // print list kemungkinan makanan
    if (isEmpty(pilihan)){
        printf("Tidak ada makanan yang bisa dibuat.\n");
    }
    else{
        printf("List bahan makanan yang bisa dibuat: \n");
        for (int i = 0; i < NEFF(pilihan); i++){
            printf("%d. %s", i+1, NAMA_MAKANAN(m).content);
        }

        // pilih makanan
        int pil;
        printf("Enter command: ");
        scanf("%d", &pil);
        while (pil < 0 || pil > NEFF(pilihan)){
            printf("Enter command: ");
        scanf("%d", &pil);
        }

        if (pil != 0){
            // cek apakah bahan ada di inventory atau tidak
            IDsearch = ELMT(pilihan,pil-1);
            m = SearchById(IDsearch, listmakanan); // makanan

            // cari tree ID makanan di list resep
            boolean found = false;
            int i = 0;
            addr = NULL;
            while (!found && i < listLengthResep(resep)){
                addr = addrSearch(ELMTR(resep,i),IDsearch);
                if (addr == NULL){
                    i++;
                }
            }
            // addr berisi address makanan yang ingin dibuat

        
            ListDin kosong; // list bahan yang tidak ada

            // iterasi semua bahan child makanan dan list makanan yang tidak ada
            p = CHILDNODE(addr);
            while (p != NULL){
                if (!inInventory(Inventory(*s),INFO(p))){
                    insertLast(&kosong, INFO(p));
                }
            }

            // print makanan yang tidak dapat dibuat
            if (!isEmpty(kosong)){
                printf("Gagal membuat %s karena kamu tidak memiliki bahan berikut:\n", NAMA_MAKANAN(m).content);
                for(i = 0; i < NEFF(kosong); i++){
                    mi = SearchById(ELMT(kosong,i), listmakanan);
                    printf("%d. %s", i+1, NAMA_MAKANAN(mi).content);
                }
            }
            // jika dapat dibuat, iterasi tiap childnode untuk dikurangkan di inventory
            else{
                int x;
                int i = 0;
                p = CHILDNODE(addr);
                while (p != NULL){
                    x = INFO(p); // ID makanan yang akan dikurangkan
                    use(s,x);
                    p = NEXT(p);
                }

                printf("%s selesai dibuat dan sudah masuk ke inventory!", NAMA_MAKANAN(m).content);
            }
        }
    }
}

void fry(Simulator *s, ListStatikResep resep, ListMakanan listmakanan){
/* Menggoreng satu atau lebih makanan menjadi makanan baru */
    // Mengecek bahan makanan yang dapat difry
    int count = 0;
    int ID, IDsearch;
    Makanan m,mi;
    ListDin pilihan;
    AddressTree addr,p;
    CreateListDin(&pilihan, 20);

    string FRY;
    createString(&FRY);
    FRY.content = "FRY";

    // iterasi lokasi aksi tiap resep
    for (int i = 0; i < listLengthResep(resep); i++){
        ID = ROOT(ELMTR(resep,i));
        m = SearchById(ID, listmakanan);
        if (cmpStrType2(LOKASI_AKSI(m).content, FRY.content)){
            insertLast(&pilihan, ID_MAKANAN(m)); // simpan ID makanan di pilihan
        }
    }

    // print list kemungkinan makanan
    if (isEmpty(pilihan)){
        printf("Tidak ada makanan yang bisa dibuat.\n");
    }
    else{
        printf("List bahan makanan yang bisa dibuat: \n");
        for (int i = 0; i < NEFF(pilihan); i++){
            printf("%d. %s", i+1, NAMA_MAKANAN(m).content);
        }

        // pilih makanan
        int pil;
        printf("Enter command: ");
        scanf("%d", &pil);
        while (pil < 0 || pil > NEFF(pilihan)){
            printf("Enter command: ");
        scanf("%d", &pil);
        }

        if (pil != 0){
            // cek apakah bahan ada di inventory atau tidak
            IDsearch = ELMT(pilihan,pil-1);
            m = SearchById(IDsearch, listmakanan); // makanan

            // cari tree ID makanan di list resep
            boolean found = false;
            int i = 0;
            addr = NULL;
            while (!found && i < listLengthResep(resep)){
                addr = addrSearch(ELMTR(resep,i),IDsearch);
                if (addr == NULL){
                    i++;
                }
            }
            // addr berisi address makanan yang ingin dibuat

        
            ListDin kosong; // list bahan yang tidak ada

            // iterasi semua bahan child makanan dan list makanan yang tidak ada
            p = CHILDNODE(addr);
            while (p != NULL){
                if (!inInventory(Inventory(*s),INFO(p))){
                    insertLast(&kosong, INFO(p));
                }
            }

            // print makanan yang tidak dapat dibuat
            if (!isEmpty(kosong)){
                printf("Gagal membuat %s karena kamu tidak memiliki bahan berikut:\n", NAMA_MAKANAN(m).content);
                for(i = 0; i < NEFF(kosong); i++){
                    mi = SearchById(ELMT(kosong,i), listmakanan);
                    printf("%d. %s", i+1, NAMA_MAKANAN(mi).content);
                }
            }
            // jika dapat dibuat, iterasi tiap childnode untuk dikurangkan di inventory
            else{
                int x;
                int i = 0;
                p = CHILDNODE(addr);
                while (p != NULL){
                    x = INFO(p); // ID makanan yang akan dikurangkan
                    use(s,x);
                    p = NEXT(p);
                }

                printf("%s selesai dibuat dan sudah masuk ke inventory!", NAMA_MAKANAN(m).content);
            }
        }
    }
}

void boil(Simulator *s, ListStatikResep resep, ListMakanan listmakanan){
/* Merebus satu bahan makanan */
    // Mengecek bahan makanan yang dapat dimix
    int count = 0;
    int ID, IDsearch;
    Makanan m,mi;
    ListDin pilihan;
    AddressTree addr,p;
    CreateListDin(&pilihan, 20);

    string BOIL;
    createString(&BOIL);
    BOIL.content = "BOIL";

    // iterasi lokasi aksi tiap resep
    for (int i = 0; i < listLengthResep(resep); i++){
        ID = ROOT(ELMTR(resep,i));
        m = SearchById(ID, listmakanan);
        if (cmpStrType2(LOKASI_AKSI(m).content, BOIL.content)){
            insertLast(&pilihan, ID_MAKANAN(m)); // simpan ID makanan di pilihan
        }
    }

    // print list kemungkinan makanan
    if (isEmpty(pilihan)){
        printf("Tidak ada makanan yang bisa dibuat.\n");
    }
    else{
        printf("List bahan makanan yang bisa dibuat: \n");
        for (int i = 0; i < NEFF(pilihan); i++){
            printf("%d. %s", i+1, NAMA_MAKANAN(m).content);
        }

        // pilih makanan
        int pil;
        printf("Enter command: ");
        scanf("%d", &pil);
        while (pil < 0 || pil > NEFF(pilihan)){
            printf("Enter command: ");
        scanf("%d", &pil);
        }

        if (pil != 0){
            // cek apakah bahan ada di inventory atau tidak
            IDsearch = ELMT(pilihan,pil-1);
            m = SearchById(IDsearch, listmakanan); // makanan

            // cari tree ID makanan di list resep
            boolean found = false;
            int i = 0;
            addr = NULL;
            while (!found && i < listLengthResep(resep)){
                addr = addrSearch(ELMTR(resep,i),IDsearch);
                if (addr == NULL){
                    i++;
                }
            }
            // addr berisi address makanan yang ingin dibuat

        
            ListDin kosong; // list bahan yang tidak ada

            // iterasi semua bahan child makanan dan list makanan yang tidak ada
            p = CHILDNODE(addr);
            while (p != NULL){
                if (!inInventory(Inventory(*s),INFO(p))){
                    insertLast(&kosong, INFO(p));
                }
            }

            // print makanan yang tidak dapat dibuat
            if (!isEmpty(kosong)){
                printf("Gagal membuat %s karena kamu tidak memiliki bahan berikut:\n", NAMA_MAKANAN(m).content);
                for(i = 0; i < NEFF(kosong); i++){
                    mi = SearchById(ELMT(kosong,i), listmakanan);
                    printf("%d. %s", i+1, NAMA_MAKANAN(mi).content);
                }
            }
            // jika dapat dibuat, iterasi tiap childnode untuk dikurangkan di inventory
            else{
                int x;
                int i = 0;
                p = CHILDNODE(addr);
                while (p != NULL){
                    x = INFO(p); // ID makanan yang akan dikurangkan
                    use(s,x);
                    p = NEXT(p);
                }

                printf("%s selesai dibuat dan sudah masuk ke inventory!", NAMA_MAKANAN(m).content);
            }
        }
    }
}