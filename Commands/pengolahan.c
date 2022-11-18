/* Implementasi pengolahan makanan */

// gcc pengolahan.c ../ADT/tree/tree.c ../ADT/sederhana/makanan.c ../ADT/sederhana/simulator.c ../ADT/stack_queue/prioqueue.c ../ADT/list_statik_resep/liststatikresep.c ../ADT/listdin/listdin.c ../ADT/list_statik/liststatik.c ../ADT/matrix/matrix.c ../ADT/char_word_machine/string.c ../ADT/sederhana/waktu.c ../ADT/sederhana/point.c

#include <stdio.h>
#include "pengolahan.h"

boolean inInventory(PrioQueue q, int ID){
/* Mencari apakah ID makanan berada di inventory atau tidak */
    int i = Head(q);
    boolean found = false;
    while (i < Tail(q) && !found){
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
    Makanan m,mi,mn;
    ListStatik pilihan;
    AddressTree addr;
    CreateListStatik(&pilihan);

    string MIX;
    createString(&MIX);
    MIX.Length = 3;
    MIX.content = "Mix";
    // iterasi lokasi aksi tiap resep
    for (int i = 0; i < listMakananLength(listmakanan); i++){
        m = listmakanan.arr[i];
        if (cmpStrType2(LOKASI_AKSI(m).content, MIX.content)){
            printf("%s\n", NAMA_MAKANAN(m).content);
            insertLast(&pilihan, ID_MAKANAN(m)); // simpan ID makanan di pilihan
        }
    }

    // print list kemungkinan makanan
    if (isEmpty(pilihan)){
        printf("Tidak ada makanan yang bisa dibuat.\n");
    }
    else{
        printf("List bahan makanan yang bisa dibuat: \n");
        for (int i = 0; i < listLength(pilihan); i++){
            m = SearchById(ELMTLIST(pilihan,i),listmakanan);
            printf("%d. %s\n", i+1, NAMA_MAKANAN(m).content);
        }
        
        // pilih makanan
        int pil;
        string inputs;
        printf("\n");
        printf("Enter command: ");
        // scanf("%d", &pil);
        scanWord(&inputs);
        pil = ((int) inputs.content[0]) - 48;
        while (pil < 0 || pil > listLength(pilihan)){
            printf("\n");
            printf("Enter command: ");
        scanf("%d", &pil);
        }

        if (pil != 0){
            // cek apakah bahan ada di inventory atau tidak
            IDsearch = ELMTLIST(pilihan,pil-1);
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
                else{
                    found = true;
                }
            }
            // addr berisi address makanan yang ingin dibuat

            ListDin kosong; // list bahan yang tidak ada
            CreateListDin(&kosong,20);

            // iterasi semua bahan child makanan dan list makanan yang tidak ada
            AddressTree p;
            p = CHILDNODE(addr);
            while (NEXTNODE(p) != NULL){
                if (!inInventory(Inventory(*s),ROOT(p))){
                        insertLastD(&kosong, ROOT(p));
                    }
                p = NEXTNODE(p);
            }

            // print makanan yang tidak dapat dibuat
            if (!isEmptyD(kosong)){
                printf("Gagal membuat %s karena kamu tidak memiliki bahan berikut:\n", NAMA_MAKANAN(m).content);
                for(i = 0; i < NEFF(kosong); i++){
                    mi = SearchById(ELMT(kosong,i), listmakanan);
                    printf("%d. %s\n", i+1, NAMA_MAKANAN(mi).content);
                }
            }
            // jika dapat dibuat, iterasi tiap childnode untuk dikurangkan di inventory
            else{
                // hapus elemen pada inventory
                p = CHILDNODE(addr);
                while (NEXTNODE(p) != NULL){
                    mn = SearchById(ROOT(p), listmakanan);
                    Remove(&Inventory(*s),mn);
                    p = NEXTNODE(p);
                }

                int x;
                int i = 0;
                p = CHILDNODE(addr);
                while (p != NULL){
                    x = ROOT(p); // ID makanan yang akan dikurangkan
                    use(s,x);
                    p = NEXTNODE(p);
                }

                printf("%s selesai dibuat dan sudah masuk ke inventory!", NAMA_MAKANAN(m).content);
                Enqueue(&Inventory(*s),m);

                long waktu = TIMEToMenit(LAMA_PENGIRIMAN(m));

                for(int i = 0; i < (int) waktu; i++){
                    kurang_waktu_deliv(&Delivery(*s), &Inventory(*s));
                    kurang_waktu_inv(&Inventory(*s));
                }
            }
        }
    }

}

void chop(Simulator *s, ListStatikResep resep, ListMakanan listmakanan){
/* Memotong makanan */
    // Mengecek bahan makanan yang dapat dichop
    int count = 0;
    int ID, IDsearch;
    Makanan m,mi,mn;
    ListStatik pilihan;
    AddressTree addr;
    CreateListStatik(&pilihan);

    string CHOP;
    createString(&CHOP);
    CHOP.Length = 4;
    CHOP.content = "Chop";
    // iterasi lokasi aksi tiap resep
    for (int i = 0; i < listMakananLength(listmakanan); i++){
        m = listmakanan.arr[i];
        if (cmpStrType2(LOKASI_AKSI(m).content, CHOP.content)){
            printf("%s\n", NAMA_MAKANAN(m).content);
            insertLast(&pilihan, ID_MAKANAN(m)); // simpan ID makanan di pilihan
        }
    }

    // print list kemungkinan makanan
    if (isEmpty(pilihan)){
        printf("Tidak ada makanan yang bisa dibuat.\n");
    }
    else{
        printf("List bahan makanan yang bisa dibuat: \n");
        for (int i = 0; i < listLength(pilihan); i++){
            m = SearchById(ELMTLIST(pilihan,i),listmakanan);
            printf("%d. %s\n", i+1, NAMA_MAKANAN(m).content);
        }
        
        // pilih makanan
        int pil;
        printf("\n");
        printf("Enter command: ");
        scanf("%d", &pil);
        while (pil < 0 || pil > listLength(pilihan)){
            printf("\n");
            printf("Enter command: ");
        scanf("%d", &pil);
        }

        if (pil != 0){
            // cek apakah bahan ada di inventory atau tidak
            IDsearch = ELMTLIST(pilihan,pil-1);
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
                else{
                    found = true;
                }
            }
            // addr berisi address makanan yang ingin dibuat

            ListDin kosong; // list bahan yang tidak ada
            CreateListDin(&kosong,20);

            // iterasi semua bahan child makanan dan list makanan yang tidak ada
            AddressTree p;
            p = CHILDNODE(addr);
            while (NEXTNODE(p) != NULL){
                if (!inInventory(Inventory(*s),ROOT(p))){
                        insertLastD(&kosong, ROOT(p));
                    }
                p = NEXTNODE(p);
            }

            // print makanan yang tidak dapat dibuat
            if (!isEmptyD(kosong)){
                printf("Gagal membuat %s karena kamu tidak memiliki bahan berikut:\n", NAMA_MAKANAN(m).content);
                for(i = 0; i < NEFF(kosong); i++){
                    mi = SearchById(ELMT(kosong,i), listmakanan);
                    printf("%d. %s\n", i+1, NAMA_MAKANAN(mi).content);
                }
            }
            // jika dapat dibuat, iterasi tiap childnode untuk dikurangkan di inventory
            else{
                // hapus elemen pada inventory
                p = CHILDNODE(addr);
                while (NEXTNODE(p) != NULL){
                    mn = SearchById(ROOT(p), listmakanan);
                    Remove(&Inventory(*s),mn);
                    p = NEXTNODE(p);
                }
                int x;
                int i = 0;
                p = CHILDNODE(addr);
                while (p != NULL){
                    x = ROOT(p); // ID makanan yang akan dikurangkan
                    use(s,x);
                    p = NEXTNODE(p);
                }

                printf("%s selesai dibuat dan sudah masuk ke inventory!", NAMA_MAKANAN(m).content);
                Enqueue(&Inventory(*s),m);

                long waktu = TIMEToMenit(LAMA_PENGIRIMAN(m));

                for(int i = 0; i < (int) waktu; i++){
                    kurang_waktu_deliv(&Delivery(*s), &Inventory(*s));
                    kurang_waktu_inv(&Inventory(*s));
                }
            }
        }
    }
}

void fry(Simulator *s, ListStatikResep resep, ListMakanan listmakanan){
/* Menggoreng makanan */
    // Mengecek bahan makanan yang dapat difry
    int count = 0;
    int ID, IDsearch;
    Makanan m,mi,mn;
    ListStatik pilihan;
    AddressTree addr;
    CreateListStatik(&pilihan);

    string FRY;
    createString(&FRY);
    FRY.Length = 3;
    FRY.content = "Fry";
    // iterasi lokasi aksi tiap resep
    for (int i = 0; i < listMakananLength(listmakanan); i++){
        m = listmakanan.arr[i];
        if (cmpStrType2(LOKASI_AKSI(m).content, FRY.content)){
            printf("%s\n", NAMA_MAKANAN(m).content);
            insertLast(&pilihan, ID_MAKANAN(m)); // simpan ID makanan di pilihan
        }
    }

    // print list kemungkinan makanan
    if (isEmpty(pilihan)){
        printf("Tidak ada makanan yang bisa dibuat.\n");
    }
    else{
        printf("List bahan makanan yang bisa dibuat: \n");
        for (int i = 0; i < listLength(pilihan); i++){
            m = SearchById(ELMTLIST(pilihan,i),listmakanan);
            printf("%d. %s\n", i+1, NAMA_MAKANAN(m).content);
        }
        
        // pilih makanan
        int pil;
        printf("\n");
        printf("Enter command: ");
        scanf("%d", &pil);
        while (pil < 0 || pil > listLength(pilihan)){
            printf("\n");
            printf("Enter command: ");
        scanf("%d", &pil);
        }

        if (pil != 0){
            // cek apakah bahan ada di inventory atau tidak
            IDsearch = ELMTLIST(pilihan,pil-1);
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
                else{
                    found = true;
                }
            }
            // addr berisi address makanan yang ingin dibuat

            ListDin kosong; // list bahan yang tidak ada
            CreateListDin(&kosong,20);

            // iterasi semua bahan child makanan dan list makanan yang tidak ada
            AddressTree p;
            p = CHILDNODE(addr);
            while (NEXTNODE(p) != NULL){
                if (!inInventory(Inventory(*s),ROOT(p))){
                        insertLastD(&kosong, ROOT(p));
                    }
                p = NEXTNODE(p);
            }

            // print makanan yang tidak dapat dibuat
            if (!isEmptyD(kosong)){
                printf("Gagal membuat %s karena kamu tidak memiliki bahan berikut:\n", NAMA_MAKANAN(m).content);
                for(i = 0; i < NEFF(kosong); i++){
                    mi = SearchById(ELMT(kosong,i), listmakanan);
                    printf("%d. %s\n", i+1, NAMA_MAKANAN(mi).content);
                }
            }
            // jika dapat dibuat, iterasi tiap childnode untuk dikurangkan di inventory
            else{
                // hapus elemen pada inventory
                p = CHILDNODE(addr);
                while (NEXTNODE(p) != NULL){
                    mn = SearchById(ROOT(p), listmakanan);
                    Remove(&Inventory(*s),mn);
                    p = NEXTNODE(p);
                }
                int x;
                int i = 0;
                p = CHILDNODE(addr);
                while (p != NULL){
                    x = ROOT(p); // ID makanan yang akan dikurangkan
                    use(s,x);
                    p = NEXTNODE(p);
                }

                printf("%s selesai dibuat dan sudah masuk ke inventory!", NAMA_MAKANAN(m).content);
                Enqueue(&Inventory(*s),m);

                long waktu = TIMEToMenit(LAMA_PENGIRIMAN(m));

                for(int i = 0; i < (int) waktu; i++){
                    kurang_waktu_deliv(&Delivery(*s), &Inventory(*s));
                    kurang_waktu_inv(&Inventory(*s));
                }
            }
        }
    }
}

void boil(Simulator *s, ListStatikResep resep, ListMakanan listmakanan){
/* Merebus makanan */
    // Mengecek bahan makanan yang dapat dimix
    int count = 0;
    int ID, IDsearch;
    Makanan m,mi,mn;
    ListStatik pilihan;
    AddressTree addr;
    CreateListStatik(&pilihan);

    string BOIL;
    createString(&BOIL);
    BOIL.Length = 4;
    BOIL.content = "Boil";
    // iterasi lokasi aksi tiap resep
    for (int i = 0; i < listMakananLength(listmakanan); i++){
        m = listmakanan.arr[i];
        if (cmpStrType2(LOKASI_AKSI(m).content, BOIL.content)){
            printf("%s\n", NAMA_MAKANAN(m).content);
            insertLast(&pilihan, ID_MAKANAN(m)); // simpan ID makanan di pilihan
        }
    }

    // print list kemungkinan makanan
    if (isEmpty(pilihan)){
        printf("Tidak ada makanan yang bisa dibuat.\n");
    }
    else{
        printf("List bahan makanan yang bisa dibuat: \n");
        for (int i = 0; i < listLength(pilihan); i++){
            m = SearchById(ELMTLIST(pilihan,i),listmakanan);
            printf("%d. %s\n", i+1, NAMA_MAKANAN(m).content);
        }
        
        // pilih makanan
        int pil;
        printf("\n");
        printf("Enter command: ");
        scanf("%d", &pil);
        while (pil < 0 || pil > listLength(pilihan)){
            printf("\n");
            printf("Enter command: ");
        scanf("%d", &pil);
        }

        if (pil != 0){
            // cek apakah bahan ada di inventory atau tidak
            IDsearch = ELMTLIST(pilihan,pil-1);
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
                else{
                    found = true;
                }
            }
            // addr berisi address makanan yang ingin dibuat

            ListDin kosong; // list bahan yang tidak ada
            CreateListDin(&kosong,20);

            // iterasi semua bahan child makanan dan list makanan yang tidak ada
            AddressTree p;
            p = CHILDNODE(addr);
            while (NEXTNODE(p) != NULL){
                if (!inInventory(Inventory(*s),ROOT(p))){
                        insertLastD(&kosong, ROOT(p));
                    }
                p = NEXTNODE(p);
            }

            // print makanan yang tidak dapat dibuat
            if (!isEmptyD(kosong)){
                printf("Gagal membuat %s karena kamu tidak memiliki bahan berikut:\n", NAMA_MAKANAN(m).content);
                for(i = 0; i < NEFF(kosong); i++){
                    mi = SearchById(ELMT(kosong,i), listmakanan);
                    printf("%d. %s\n", i+1, NAMA_MAKANAN(mi).content);
                }
            }
            // jika dapat dibuat, iterasi tiap childnode untuk dikurangkan di inventory
            else{
                // hapus elemen pada inventory
                p = CHILDNODE(addr);
                while (NEXTNODE(p) != NULL){
                    mn = SearchById(ROOT(p), listmakanan);
                    Remove(&Inventory(*s),mn);
                    p = NEXTNODE(p);
                }
                int x;
                int i = 0;
                p = CHILDNODE(addr);
                while (p != NULL){
                    x = ROOT(p); // ID makanan yang akan dikurangkan
                    use(s,x);
                    p = NEXTNODE(p);
                }

                printf("%s selesai dibuat dan sudah masuk ke inventory!", NAMA_MAKANAN(m).content);
                Enqueue(&Inventory(*s),m);

                long waktu = TIMEToMenit(LAMA_PENGIRIMAN(m));

                for(int i = 0; i < (int) waktu; i++){
                    kurang_waktu_deliv(&Delivery(*s), &Inventory(*s));
                    kurang_waktu_inv(&Inventory(*s));
                }
            }
        }
    }
}