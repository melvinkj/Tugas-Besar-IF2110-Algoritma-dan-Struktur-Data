// Header
#include "stdio.h"
#include "stdlib.h"
#include "../ADT/char_word_machine/charmachine.h"
#include "../ADT/char_word_machine/string.h"
#include "../ADT/char_word_machine/wordmachine.h"
#include "../ADT/matrix/matrix.h"
#include "../ADT/sederhana/point.h"
#include "../ADT/stack_queue/stack.h"
#include "../Commands/pengolahan.h"
#include "../command/undoredo.h"

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
void processCommand(string command, POINT *S, Matrix *Peta)
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
        processWaitCommand(command, &hour, &minute);
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
            return;
        }
        if (cmpStrType2(command.content, delivery_cmd.content))
        {
            return;
        }
        if (cmpStrType2(command.content, move_north_cmd.content))
        {
            Move(S, command, Peta);
        }
        if (cmpStrType2(command.content, move_east_cmd.content))
        {
            Move(S, command, Peta);
        }
        if (cmpStrType2(command.content, move_west_cmd.content))
        {
            Move(S, command, Peta);
        }
        if (cmpStrType2(command.content, move_south_cmd.content))
        {
            Move(S, command, Peta);
        }
        if (cmpStrType2(command.content, mix_cmd.content))
        {
            ListResep l_resep = READRESEP("./resep_test.txt");
            ListMakanan l_makanan = READMAKANAN("./makanan_test.txt");

            mix(S, l_resep, l_makanan);
        }
        if (cmpStrType2(command.content, chop_cmd.content))
        {
            ListResep l_resep = READRESEP("./resep_test.txt");
            ListMakanan l_makanan = READMAKANAN("./makanan_test.txt");

            chop(S, l_resep, l_makanan);
        }
        if (cmpStrType2(command.content, fry_cmd.content))
        {
            ListResep l_resep = READRESEP("./resep_test.txt");
            ListMakanan l_makanan = READMAKANAN("./makanan_test.txt");

            fry(S, l_resep, l_makanan);
        }
        if (cmpStrType2(command.content, boil_cmd.content))
        {
            ListResep l_resep = READRESEP("./resep_test.txt");
            ListMakanan l_makanan = READMAKANAN("./makanan_test.txt");

            boil(S, l_resep, l_makanan);
        }
        if (cmpStrType2(command.content, undo_cmd.content))
        {
            undo(&S);
            return;
        }
        if (cmpStrType2(command.content, redo_cmd.content))
        {
            redo(&S);
            return;
        }
    }
}

/* *** Main *** */
int main()
{

    // Splash Screen
    // -------------
    printf("░▄░░░░█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█░░░░░░");
    printf("░█░░░░█░▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄░█░░░░▄░");
    printf("░█░░░░█░█░░░░░░░░░░░░░░█░█░░░░█░");
    printf("░█░░░░█░█░░░▀░░░░░░▀░░░█░█░░░░█░");
    printf("░▀█░░░█░█░░░░▄▄▄▄▄▄░░░░█░█░░░░█░");
    printf("░░█▄░░█░█░░░░█▄░░▄█░░░░█░█░░▄█▀░");
    printf("░░░▀█░█░█░░░░░▀▀▀▀░░░░░█░█▄█▀░░░");
    printf("░░░░░▀█░▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀░█▀░░░░░");
    printf("░░░░░░█░████████░░░▄░░▀░░█░░░░░░");
    printf("░░░░░░█░░░▄░░░░░░▄███▄░░░█░░░░░░");
    printf("░░░░░░█░▄▄█▄▄░░░░░░░░░▄▄░█░░░░░░");
    printf("░░░░░░█░░░█░░░░░░░░░▄░▀▀░█░░░░░░");
    printf("░░░░░░█░░░░░░░░░░░▄███▄░░█░░░░░░");
    printf("░░░░░░█░███░███░░░░▀█▀░░░█░░░░░░");
    printf("░░░░░░█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█░░░░░░");
    printf("░░░░░░░░░░░░█░░░░░░█░░░░░░░░░░░░");
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
        // checker.content = commandOptions(input);
        if (cmpStrType2(input.content, start_cmd.content))
        {
            validate = true;
            if (cmpStrType2(input.content, exit_cmd.content))
            {
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
        printf("\n");

        // Init simulator
        Simulator S;
        createSimulator(&S);
        S.nama = nama;

        // Init peta
        Matrix peta;
        READPETA(&peta, "./peta_test.txt");
        POINT S = LocateS(peta);

        // Init stack undo redo
        CreateEmptyUndoRedo();

        while (running_state)
        {
            // Validate every command
            printf("%s di posisi: (%d,%d)\n", nama.content, S.posisi.X, S.posisi.Y);
            printf("Waktu : \n");
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
                        exit(0);
                    }
                }
                else
                {
                    printf("Please enter a valid command!\n");
                }
            } while (cmpStrType2(checker.content, invalid.content));
            // input valid
            
            // testing new func
            processCommand(input, &S, &peta);
            // displayMatrix(peta);
            
        }
    }

    return 0;
}
