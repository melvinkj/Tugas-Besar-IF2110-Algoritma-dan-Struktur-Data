// Header
#include "stdio.h"
#include "stdlib.h"
#include "../ADT/char_word_machine/charmachine.h"
#include "../ADT/char_word_machine/string.h"
#include "../ADT/char_word_machine/wordmachine.h"
#include "../ADT/matrix/matrix.h"
#include "../ADT/sederhana/point.h"

/* *** Command Reader *** */
// void processCommand(string command) {
//     // Pathway untuk ke fungsi lain
//     if (command.content == "MOVE UP") {
//         printf("Moved Up\n");
//     }

// }

/* *** Operasi-operasi *** */
POINT LocateS (Matrix peta) {
    POINT S;
    for (int i = 0; i < peta.rowEff; i++) {
        for (int j = 0; j < peta.colEff; j++) {
            if (peta.mem[i][j] == 'S'){
                CreatePoint(&S, j, i);
                break;
            }
        }
    }
    return S;
}

boolean checkAdjacent(char cc, Matrix peta) {
    // Posisi S
    POINT S = LocateS(peta);
    // Adjacent S
    int start_check_x = (S.X - 1) >= 0 ? S.X-1 : 0;
    int end_check_x = (S.X + 1) <= peta.rowEff - 1 ? S.X + 1 : S.X;
    int start_check_y = (S.Y - 1) >= 0 ? S.Y-1 : 0;
    int end_check_y = (S.Y + 1) <= peta.colEff - 1 ? S.Y + 1 : S.Y;

    // Result
    boolean found = false;
    for (int i = start_check_y; i < end_check_y; i++){
        for (int j = start_check_x; j < end_check_x; j++){
            if (peta.mem[i][j] == cc) {
                found = true;
            }
        }
    }
    return found;
}

void Catalog () {
    ListMakanan ans = READMAKANAN("./makanan_test.txt");
    int i = 0;
    char * buy = "Buy";
    printf("List Makanan\n(nama - durasi kedaluwarsa - aksi yang diperlukan - delivery time)\n");
    while (ans.arr[i].id != -9999) {
        int id = ans.arr[i].id;
        string nama = { .content = ans.arr[i].nama.content , .Length = ans.arr[i].nama.Length };
        TIME expiry_time = ans.arr[i].waktu_kedaluwarsa;
        TIME delivery_time = ans.arr[i].lama_pengiriman;
        string aksi = { .content = ans.arr[i].lokasi_aksi.content , .Length = ans.arr[i].lokasi_aksi.Length };
        printf("\t%d. %s ", i + 1 , nama.content);
        if (expiry_time.DD != 0) {
            printf("- %d hari ", expiry_time.DD);
        }
        if (expiry_time.HH != 0) {
            if (expiry_time.DD != 0){
                printf("%d jam ", expiry_time.HH);    
            } else {
                printf("- %d jam ", expiry_time.HH);
            }
        }
        if (expiry_time.MM != 0) {
            if (expiry_time.DD != 0 || expiry_time.HH != 0){
                printf("%d menit ", expiry_time.MM);
            } else {
                printf("- %d menit ", expiry_time.MM);
            }
        }
        printf("- %s ", aksi.content);
        if (cmpStrType2(aksi.content, buy)){
            if (delivery_time.DD != 0) {
            printf("- %d hari ", delivery_time.DD);
            }
            if (delivery_time.HH != 0) {
                if (delivery_time.DD != 0){
                    printf("%d jam ", delivery_time.HH);    
                } else {
                    printf("- %d jam ", delivery_time.HH);
                }
            }
            if (delivery_time.MM != 0) {
                if (delivery_time.DD != 0 || delivery_time.HH != 0){
                    printf("%d menit ", delivery_time.MM);
                } else {
                    printf("- %d menit ", delivery_time.MM);
                }
            }
        } else {
            printf("- %d", 0);
        }
        printf("\n");
        i++;
    }
}

string findFood (int id) {
    ListMakanan l_makanan = READMAKANAN("./makanan_test.txt");
    int i = 0;
    string res;
    while (l_makanan.arr[i].id != -9999) {
        if (l_makanan.arr[i].id == id) {
            res = l_makanan.arr[i].nama;
            break;
        }
        i++;
    }
    return res;
}

string findAksi (int id) {
    ListMakanan l_makanan = READMAKANAN("./makanan_test.txt");
    int i = 0;
    string res;
    while (l_makanan.arr[i].id != -9999) {
        if (l_makanan.arr[i].id == id) {
            res = l_makanan.arr[i].lokasi_aksi;
            break;
        }
        i++;
    }
    return res;
}

void CookBook () {
    ListResep l_resep = READRESEP("./resep_test.txt");
    printf("List Resep\n");
    printf("(aksi yang diperlukan - bahan...)\n");
    int i = 0;
    while (l_resep.arr[i].parent_ID != -9999) {
        string parent_food = findFood(l_resep.arr[i].parent_ID);
        string food_aksi = findAksi(l_resep.arr[i].parent_ID);
        printf("\t%d. ", i+1);
        printf("\t%s\n", parent_food.content);
        printf("\t\t%s ", food_aksi.content);
        for (int j = 0; j < l_resep.arr[i].child_ID.nEff; j++){
            printf("- %s ", findFood(l_resep.arr[i].child_ID.buffer[j]).content);
        }
        printf("\n");
        i++;
    }
}


/* *** Main *** */
int main () {


    return 0;
}







