// Header
#include "stdio.h"
#include "stdlib.h"
#include "../ADT/char_word_machine/charmachine.h"
#include "../ADT/char_word_machine/string.h"
#include "../ADT/char_word_machine/wordmachine.h"
#include "../ADT/matrix/matrix.h"
#include "../ADT/sederhana/point.h"

/* *** Command Reader *** */
void processCommand(string command) {
    // Pathway untuk ke fungsi lain
    if (command.content == "MOVE UP") {
        printf("Moved Up\n");
    }

}

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
    ListMakanan ans = READMAKANAN();
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
            printf("\n");
        i++;
    }
}

/* *** Main *** */
int main () {
    // Splash screen ...
    char scanf_bug;
    int dum;
    FILE *dummy_fp;
    // START & EXIT option
    // Start Validate
    Word input, clear_scan;
    scanWord(&input,"Enter Command: ");
    printf("\n");
    // fflush(stdin);
    scanWord(&clear_scan, "\nEnter Command (START/EXIT), 2: ");
    printf("\n");
    scanWord(&input, "\nEnter Command (START/EXIT), 3: ");
    printf("\n");
    // Memvalidasi dengan optionsCommand
    boolean valid_command = false;
    char * invalid = "INVALID";
    char * checker = commandOptions(input);
    printf("len: %d\n", input.Length);
    if (!cmpStrType2(checker, invalid)) {
        printf("bool : %d\n", cmpStrType2(checker, invalid));
        printf("Succesfully read: %s\n", checker); }
    // else {
    // Jika hasilnya invalid maka re-loop input
    // while (!valid_command) {
    //     printf("Please enter a valid command.");
    //     // scanf("%d", &scanf_bug);
    //     scanWord(&input, "\nEnter Command (START/EXIT): ");
    //     // scanf("%c", &scanf_bug);
    //     // printf("\n");
    //     checker = commandOptions(input);
    //     // printf("Read : %s\n", checker);
    //     if (!cmpStrType2(checker, invalid)) {
    //         valid_command = true;
    //         printf("pass here\n");
    //         break;
    //     }
    // } // checker != INVALID
    // End START/EXIT Validation
    printf("Res: %s", checker);
    // }
    // // Start Processing
    // string command = {.content = checker, .Length = input.Length};
    // // Jika valid maka akan memanggil fungsi input command untuk diterukan ke fungsi lain
    // processCommand(command);
    // if (command.content == "EXIT"){
    //     exit(0);
    // } else {
    //     while (command.content != "EXIT") {
    //         scanWord(&command.content, "Enter Command (START/EXIT): ");
    //         printf("Processing: %s\n", command.content);
    //         processCommand(command);
    //     }
    //     // User typed exit
    //     exit(0);
    // }

    return 0;
}







