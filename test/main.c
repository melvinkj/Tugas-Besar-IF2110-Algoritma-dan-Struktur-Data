// Header
#include "stdio.h"
#include "stdlib.h"
#include "../ADT/char_word_machine/charmachine.h"
#include "../ADT/char_word_machine/string.h"
#include "../ADT/char_word_machine/wordmachine.h"
#include "../ADT/matrix/matrix.h"
#include "../ADT/sederhana/point.h"
#include "../ADT/sederhana/boolean.h"
#include "../ADT/stack_queue/stack.h"
#include "../Commands/pengolahan.h"
#include "../Commands/pemesanan.h"
#include "../command/undoredo.h"
#include "../ADT/list_statik/liststatik.h"
#include "../ADT/list_statik_resep/liststatikresep.h"
#include "../ADT/listdin/listdin.h"
#include "../ADT/sederhana/makanan.h"
#include "../ADT/sederhana/simulator.h"
#include "../ADT/sederhana/waktu.h"
#include "../ADT/stack_queue/prioqueue.h"
#include "../ADT/tree/listResepToTree.h"
#include "../ADT/tree/tree.h"
#include "../command/inventory_delivery.h"
#include "../command/undoredo.h"
#include "../Commands/pemesanan.h"
#include "../Commands/pengolahan.h"
#include "../Commands/moves.h"

/* *** Operasi-operasi *** */

void Catalog()
{
    ListMakanan ans = READMAKANAN("./makanan_test.txt");
    int i = 0;
    char *buy = "Buy";
    printf("List Makanan\n(nama - durasi kedaluwarsa - aksi yang diperlukan - delivery time)\n");
    while (ans.arr[i].id != -9999)
    {
        int id = ans.arr[i].id;
        string nama = {.content = ans.arr[i].nama.content, .Length = ans.arr[i].nama.Length};
        TIME expiry_time = ans.arr[i].waktu_kedaluwarsa;
        TIME delivery_time = ans.arr[i].lama_pengiriman;
        string aksi = {.content = ans.arr[i].lokasi_aksi.content, .Length = ans.arr[i].lokasi_aksi.Length};
        printf("\t%d. %s ", i + 1, nama.content);
        if (expiry_time.DD != 0)
        {
            printf("- %d hari ", expiry_time.DD);
        }
        if (expiry_time.HH != 0)
        {
            if (expiry_time.DD != 0)
            {
                printf("%d jam ", expiry_time.HH);
            }
            else
            {
                printf("- %d jam ", expiry_time.HH);
            }
        }
        if (expiry_time.MM != 0)
        {
            if (expiry_time.DD != 0 || expiry_time.HH != 0)
            {
                printf("%d menit ", expiry_time.MM);
            }
            else
            {
                printf("- %d menit ", expiry_time.MM);
            }
        }
        printf("- %s ", aksi.content);
        if (cmpStrType2(aksi.content, buy))
        {
            if (delivery_time.DD != 0)
            {
                printf("- %d hari ", delivery_time.DD);
            }
            if (delivery_time.HH != 0)
            {
                if (delivery_time.DD != 0)
                {
                    printf("%d jam ", delivery_time.HH);
                }
                else
                {
                    printf("- %d jam ", delivery_time.HH);
                }
            }
            if (delivery_time.MM != 0)
            {
                if (delivery_time.DD != 0 || delivery_time.HH != 0)
                {
                    printf("%d menit ", delivery_time.MM);
                }
                else
                {
                    printf("- %d menit ", delivery_time.MM);
                }
            }
        }
        else
        {
            printf("- %d", 0);
        }
        printf("\n");
        i++;
    }
}

string findFood(int id)
{
    ListMakanan l_makanan = READMAKANAN("./makanan_test.txt");
    int i = 0;
    string res;
    while (l_makanan.arr[i].id != -9999)
    {
        if (l_makanan.arr[i].id == id)
        {
            res = l_makanan.arr[i].nama;
            break;
        }
        i++;
    }
    return res;
}

string findAksi(int id)
{
    ListMakanan l_makanan = READMAKANAN("./makanan_test.txt");
    int i = 0;
    string res;
    while (l_makanan.arr[i].id != -9999)
    {
        if (l_makanan.arr[i].id == id)
        {
            res = l_makanan.arr[i].lokasi_aksi;
            break;
        }
        i++;
    }
    return res;
}

void CookBook()
{
    ListResep l_resep = READRESEP("./resep_test.txt");
    printf("List Resep\n");
    printf("(aksi yang diperlukan - bahan...)\n");
    int i = 0;
    while (l_resep.arr[i].parent_ID != -9999)
    {
        string parent_food = findFood(l_resep.arr[i].parent_ID);
        string food_aksi = findAksi(l_resep.arr[i].parent_ID);
        printf("\t%d. ", i + 1);
        printf("\t%s\n", parent_food.content);
        printf("\t\t%s ", food_aksi.content);
        for (int j = 0; j < l_resep.arr[i].child_ID.nEff; j++)
        {
            printf("- %s ", findFood(l_resep.arr[i].child_ID.buffer[j]).content);
        }
        printf("\n");
        i++;
    }
}

/* *** Command Reader *** */
void processCommand(string command, Simulator *S, Matrix *Peta, ListMakanan LM)
{
    // Pathway untuk ke fungsi lain
    
    // ALL COMMANDS
    string exit_cmd = {.content = "EXIT", .Length = 4};
    string start_cmd = {.content = "START", .Length = 5};
    string buy_cmd = {.content = "BUY", .Length = 3};
    string fry_cmd = {.content = "FRY", .Length = 3};
    string delivery_cmd = {.content = "DELIVERY", .Length = 8};
    string move_north_cmd = {.content = "MOVE NORTH", .Length = 10};
    string move_east_cmd = {.content = "MOVE EAST", .Length = 9};
    string move_west_cmd = {.content = "MOVE WEST", .Length = 9};
    string move_south_cmd = {.content = "MOVE SOUTH", .Length = 10};
    string mix_cmd = {.content = "MIX", .Length = 3};
    string chop_cmd = {.content = "CHOP", .Length = 4};
    string boil_cmd = {.content = "BOIL", .Length = 4};
    string undo_cmd = {.content = "UNDO", .Length = 4};
    string redo_cmd = {.content = "REDO", .Length = 4};
    string catalog_cmd = {.content = "CATALOG", .Length = 7};
    string cookbook_cmd = {.content = "COOKBOOK", .Length = 8};
    string wait_x_y_cmd = {.content = "WAIT", .Length = 4};

    // Start Processing
    if (hasSubstring(wait_x_y_cmd, command))
    {
        int hour;
        int minute;
        TIME T;
        long T1;
        int i;
        processWaitCommand(command, &hour, &minute);
        
        CreateTime(&T, 0, hour, minute);

        T1 = TIMEToMenit(T);
        addUndo(*S);
        

        for(i=0; i < (int)T1; i++){
            S->waktu = NextMenit(S->waktu);
            kurang_waktu_deliv(&Delivery(*S), &Inventory(*S));
            kurang_waktu_inv(&Inventory(*S));
        }

        printf("Extra Hour : %d\n", hour);
        printf("Extra Minute : %d\n", minute);
    }
    else
    {
        if (cmpStrType2(command.content, exit_cmd.content))
        {
            printf("Exiting Program....\n");
            exit(0);
        }
        if (cmpStrType2(command.content, start_cmd.content))
        {
            
            printf("The Program is Running!\n");
        }
        if (cmpStrType2(command.content, catalog_cmd.content))
        {
            Catalog();
            printf("\n");
        }
        if (cmpStrType2(command.content, cookbook_cmd.content))
        {
            CookBook();
            printf("\n");
        }
        if (cmpStrType2(command.content, buy_cmd.content))
        {
            if(checkAdjacent('T', *Peta, Posisi(*S))){
                addUndo(*S);
                buy(S, LM);
                S->waktu = NextMenit(S->waktu);
            } else {
                printf("%d, %d", S->posisi.X,S->posisi.Y);
                printf("%s tidak berada di area telepon!\n", Nama(*S));
            }
        }
        if (cmpStrType2(command.content, delivery_cmd.content))
        {
            PrintDelivery(S->delivery);
            return;
        }
        if (cmpStrType2(command.content, move_north_cmd.content))
        {
            Move(&S->posisi, command, Peta, S);
        }
        if (cmpStrType2(command.content, move_east_cmd.content))
        {
            Move(&S->posisi, command, Peta, S);
        }
        if (cmpStrType2(command.content, move_west_cmd.content))
        {
            Move(&S->posisi, command, Peta, S);
        }
        if (cmpStrType2(command.content, move_south_cmd.content))
        {
            Move(&S->posisi, command, Peta, S);
        }
        if (cmpStrType2(command.content, mix_cmd.content))
        {
            ListResep l_resep = READRESEP("./resep_test.txt");
            if(checkAdjacent('M', *Peta, Posisi(*S))){
                 addUndo(*S);
                // mix(S, l_resep, LM);
                S->waktu = NextMenit(S->waktu);
            } else {
                printf("%s tidak berada di area mixer!\n", Nama(*S));
            }
        }
        if (cmpStrType2(command.content, chop_cmd.content))
        {
            ListResep l_resep = READRESEP("./resep_test.txt");

            if(checkAdjacent('C', *Peta, Posisi(*S))){
                addUndo(*S);
                // chop(S, l_resep, LM);
                S->waktu = NextMenit(S->waktu);
            } else {
                printf("%s tidak berada di area choper!\n", Nama(*S));
            }
        }
        if (cmpStrType2(command.content, fry_cmd.content))
        {
            ListResep l_resep = READRESEP("./resep_test.txt");

            if(checkAdjacent('F', *Peta, Posisi(*S))){
                addUndo(*S);
                // fry(S, l_resep, LM);
                S->waktu = NextMenit(S->waktu);
            } else {
                printf("%c tidak berada di area fryer!\n", Nama(*S));
            }
        }
        if (cmpStrType2(command.content, boil_cmd.content))
        {
            ListResep l_resep = READRESEP("./resep_test.txt");

            if(checkAdjacent('B', *Peta, Posisi(*S))){
                addUndo(*S);
                // boil(S, l_resep, LM);
                S->waktu = NextMenit(S->waktu);
            } else {
                printf("%s tidak berada di area boiler!\n", Nama(*S));
            }
        }
        if (cmpStrType2(command.content, undo_cmd.content))
        {
            undo(S);
            return;
        }
        if (cmpStrType2(command.content, redo_cmd.content))
        {
            redo(S);
            return;
        }
    }
}

/* *** Main *** */
int main()
{

    // Splash Screen
    // -------------
    printf("░▄░░░░█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█░░░░░░\n");
    printf("░█░░░░█░▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄░█░░░░▄░\n");
    printf("░█░░░░█░█░░░░░░░░░░░░░░█░█░░░░█░\n");
    printf("░█░░░░█░█░░░▀░░░░░░▀░░░█░█░░░░█░\n");
    printf("░▀█░░░█░█░░░░▄▄▄▄▄▄░░░░█░█░░░░█░\n");
    printf("░░█▄░░█░█░░░░█▄░░▄█░░░░█░█░░▄█▀░\n");
    printf("░░░▀█░█░█░░░░░▀▀▀▀░░░░░█░█▄█▀░░░\n");
    printf("░░░░░▀█░▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀░█▀░░░░░\n");
    printf("░░░░░░█░████████░░░▄░░▀░░█░░░░░░\n");
    printf("░░░░░░█░░░▄░░░░░░▄███▄░░░█░░░░░░\n");
    printf("░░░░░░█░▄▄█▄▄░░░░░░░░░▄▄░█░░░░░░\n");
    printf("░░░░░░█░░░█░░░░░░░░░▄░▀▀░█░░░░░░\n");
    printf("░░░░░░█░░░░░░░░░░░▄███▄░░█░░░░░░\n");
    printf("░░░░░░█░███░███░░░░▀█▀░░░█░░░░░░\n");
    printf("░░░░░░█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█░░░░░░\n");
    printf("░░░░░░░░░░░░█░░░░░░█░░░░░░░░░░░░\n");
    // INISIASI
    // Init valid & invalid state
    string invalid = {.content = "INVALID", .Length = 7};
    string valid = {.content = "VALID", .Length = 5};
    string exit_cmd = {.content = "EXIT", .Length = 4};
    string start_cmd = {.content = "START", .Length = 5};
    string checker;
    boolean validate = false;

    string input;
    do
    {
        printf("COMMAND (START/EXIT): ");
        scanWord(&input);
        if (cmpStrType2(input.content, exit_cmd.content)) {
            printf("Bye... See you next time!\n");
            exit(0);
        }
        if (cmpStrType2(input.content, start_cmd.content))
        {
            validate = true;
            if (cmpStrType2(input.content, exit_cmd.content))
            {
                printf("Bye... See you next time!\n");
                exit(0);
            }
        }
        else
        {
            printf("Please enter a valid command!\n");
        }
    } while (!cmpStrType2(input.content, start_cmd.content));

    // Pass validation & not EXIT
    if (validate)
    {
        printf("Starting Program...\n");
        boolean running_state = true;
        string nama;
        printf("Nama simulator: ");
        scanWord(&nama);
        printf("%s\n", nama.content);

        // Init simulator
        Simulator S;
        createSimulator(&S);
        S.nama = copyString(nama);

        // Init peta
        Matrix peta;
        READPETA(&peta, "./peta_test.txt");
        S.posisi = LocateS(peta);

        // Init stack undo redo
        CreateEmptyUndoRedo();
        addUndo(S);

        // Init list makanan
        ListMakanan LM = READMAKANAN("./makanan_test.txt");

        while (running_state)
        {
            // Validate every command
            printf("%s di posisi: (%d,%d)\n", nama.content, S.posisi.X, S.posisi.Y);
            printf("Waktu : %d.%d\n", Waktu(S).HH, Waktu(S).MM);
            printf("Notifikasi : -\n");
            displayMatrix(peta);
            printf("\n");
            do
            {
                printf("Enter COMMAND : ");
                scanWord(&input);
                checker.content = commandOptions(input);
                if (cmpStrType2(checker.content, valid.content))
                {
                    validate = true;
                    if (cmpStrType2(input.content, exit_cmd.content))
                    {
                        printf("Bye... See you next time!\n");
                        exit(0);
                    }
                }
                else
                {
                    printf("Please enter a valid command!\n");
                }
            } while (cmpStrType2(checker.content, invalid.content));
            // input valid
            processCommand(input, &S, &peta, LM);
            printf("\n");
            // Passing input to functions / procedures
            
        }
    }

    return 0;
}
