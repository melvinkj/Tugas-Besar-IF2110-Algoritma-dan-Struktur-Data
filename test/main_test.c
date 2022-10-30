// Header
#include "stdio.h"
#include "stdlib.h"
#include "../ADT/char_word_machine/charmachine.h"
#include "../ADT/char_word_machine/string.h"
#include "../ADT/char_word_machine/wordmachine.h"

/* *** Command Reader *** */
void processCommand(string command) {
    // Pathway untuk ke fungsi lain
    if (command.content == "MOVE UP") {
        printf("Moved Up\n");
    }

}

/* *** Operasi-operasi *** */
void move() {
// Mengupdate posisi S pada peta

}

/* *** Main *** */
int main () {
    // Splash screen ...
    char scanf_bug;

    // START & EXIT option
    // Start Validate
    Word input;
    scanWord(&input,"Enter Command (START/EXIT): ");
    printf("\n");
    // Memvalidasi dengan optionsCommand
    boolean valid_command = false;
    char * invalid = "INVALID";
    char * checker = commandOptions(input);
    printf("len: %d\n", input.Length);
    if (!cmpStrType2(checker, invalid)) {
        printf("bool : %d\n", cmpStrType2(checker, invalid));
        printf("Succesfully read: %s\n", checker);
    } else {
    // Jika hasilnya invalid maka re-looop input
    while (!valid_command) {
        printf("Please enter a valid command.");
        scanf("%c", &scanf_bug);
        scanWord(&input, "\nEnter Command (START/EXIT): ");
        scanf("%c", &scanf_bug);
        // printf("\n");
        checker = commandOptions(input);
        // printf("Read : %s\n", checker);
        if (!cmpStrType2(checker, invalid)) {
            valid_command = true;
            printf("pass here\n");
            break;
        }
    } // checker != INVALID
    // End START/EXIT Validation
    printf("Res: %s", checker);
    }
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







