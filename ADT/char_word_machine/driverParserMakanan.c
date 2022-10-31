#include <stdio.h>
#include "charmachine.h"
#include "string.h"
#include "../sederhana/makanan.h"
#include "../sederhana/waktu.h"

// Run Path : gcc charmachine.c string.c ../sederhana/makanan.c ../sederhana/waktu.c driverParserMakanan.c -o a

int main() {
    ListMakanan ans = READMAKANAN("../../test/makanan_test.txt");
    int i = 0;
    while (ans.arr[i].id != -9999) {
            printf("id : %d\n", ans.arr[i].id);
            printf("Nama : %s\n", ans.arr[i].nama.content);
            printf("Expired : ");
            TulisTIME(ans.arr[i].waktu_kedaluwarsa);
            printf("\n");
            printf("Delivery : ");
            TulisTIME(ans.arr[i].lama_pengiriman);
            printf("\n");
            printf("Aksi : %s\n", ans.arr[i].lokasi_aksi.content);
            printf("Ukuran x : %d", ans.arr[i].size_x);
            printf("\n");
            printf("Ukuran y : %d", ans.arr[i].size_y);
            printf("\n");
            printf("\n");
        i++;
    }
    return 0;
}


