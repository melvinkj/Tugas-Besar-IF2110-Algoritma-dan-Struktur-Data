/* File: charmachine.c */
/* Implementasi Mesin Karakter */

#include <stdio.h>
#include <stdlib.h>
#include "charmachine.h"
#include "../sederhana/makanan.h"
#include "string.h"
#include "../sederhana/waktu.h"

char currentChar;
boolean EOP;

static FILE *pita;
static int retval;

void START()
{
    /* Algoritma */
    pita = stdin;
    ADV();
}

void ADV()
{
    /* Algoritma */
    retval = fscanf(pita, "%c", &currentChar);
    EOP = (currentChar == MARK);
    if (EOP)
    {
        fclose(pita);
    }
}

// Parser Peta
void READPETA(Matrix *m)
{
    /* Algoritma */
    FILE *fp = fopen("../../test/peta_test.txt", "r");
    char cc = fgetc(fp);
    int char_to_int = 0;
    int looper = 0;
    int i = 0, j = 1;
    boolean readRow = false;
    if (fp == NULL)
    {
        printf("Filename not found!");
    }
    else
    {
        while (cc != EOF)
        {
            if (cc != '#' && cc != '\n')
            {
                if (looper <= 0)
                {
                    if (readRow)
                    {
                        char_to_int *= 10;
                        char_to_int += ((int)cc) - 48;
                    }
                    if (cc != ' ' && !readRow)
                    {
                        char_to_int *= 10;
                        char_to_int += ((int)cc) - 48;
                    }
                    else
                    {
                        if (cc == ' ')
                        {
                            m->rowEff = char_to_int;
                            char_to_int = 0;
                            readRow = true;
                        }
                    }
                }
                else
                {
                    m->mem[i][j] = cc;
                    j++;
                }
            }
            else if (cc == '#')
            {
                m->mem[i][j] = ' ';
                j++;
            }
            if (cc == '\n')
            {
                if (looper == 0)
                {
                    m->colEff = char_to_int;
                    for (int k = 0; k < m->colEff + 1; k++)
                    {
                        m->mem[0][k] = '*';
                        m->mem[m->rowEff + 1][k] = '*';
                    }
                    for (int h = 0; h < m->rowEff + 2; h++)
                    {
                        m->mem[h][0] = '*';
                        m->mem[h][m->colEff + 1] = '*';
                    }
                }
                i++;
                j = 1;
                looper++;
            }
            cc = fgetc(fp);
        }
        fclose(fp);
    }
}

// Parser Makanan
ListMakanan READMAKANAN()
{
    /* Algoritma */
    FILE *fp = fopen("../../test/makanan_test.txt", "r");
    char cc = fgetc(fp);
    int n_makanan = 0;
    // Get N
    while (cc != '\n')
    {
        n_makanan *= 10;
        n_makanan = ((int)cc) - 48;
        cc = fgetc(fp);
    }
    ListMakanan container_makanan;
    Makanan makanan;
    // Data makanan
    int id = 0, id2 = 0;
    string nama_makanan;
    createString(&nama_makanan);
    TIME expired;
    int D_expired = 0, H_expired = 0, M_expired = 0;
    TIME delivery;
    int D_delivery = 0, H_delivery = 0, M_delivery = 0;
    string aksi;
    int size_x = 0, size_y = 0;
    createString(&aksi);

    // Looping data ke - n
    int counter = 0;
    // Index array listMakanan
    int current_makanan = 0;
    // Pembatas Waktu
    int next_digit = 0;
    while (cc != EOF)
    {
        cc = fgetc(fp);
        if (cc != '\n')
        {
            // Retrieve ID
            if (counter == 0)
            {
                id *= 10;
                id += ((int)cc) - 48;
            }
            // Get name
            if (counter % 7 == 1)
            {
                nama_makanan = appendCCtoStr(nama_makanan, cc);
            }
            // Get expiry time
            if (counter % 7 == 2)
            {
                if (cc != ' ')
                {
                    if (next_digit == 0)
                    {
                        D_expired *= 10;
                        D_expired += ((int)cc) - 48;
                    }
                    if (next_digit == 1)
                    {
                        H_expired *= 10;
                        H_expired += ((int)cc) - 48;
                    }
                    if (next_digit == 2)
                    {
                        M_expired *= 10;
                        M_expired += ((int)cc) - 48;
                    }
                }
                else
                {
                    next_digit++;
                }
            }

            // Get delivery time
            if (counter % 7 == 3)
            {
                if (cc != ' ')
                {
                    switch (next_digit)
                    {
                    case 0:
                        D_delivery *= 10;
                        D_delivery += ((int)cc) - 48;
                        break;
                    case 1:
                        H_delivery *= 10;
                        H_delivery += ((int)cc) - 48;
                        break;
                    case 2:
                        M_delivery *= 10;
                        M_delivery += ((int)cc) - 48;
                        break;
                    }
                }
                else
                {
                    next_digit++;
                }
            }

            // Get Aksi
            if (counter % 7 == 4)
            {
                aksi = appendCCtoStr(aksi, cc);
            }
            
            // Get size x
            if (counter % 7 == 5) {
                size_x *= 10;
                size_x += ((int)cc) - 48;
            }

            // Get size y
            if (counter % 7 == 6) {
                size_y *= 10;
                size_y += ((int)cc) - 48;
            }

        }
        else
        {
            if (counter < 6)
            {
                counter++;
            }
            // Restart Loop untuk sequence makanan berikutnya
            else
            {
                counter = 0;
                CreateTime(&expired, D_expired, H_expired, M_expired);
                CreateTime(&delivery, D_delivery, H_delivery, M_delivery);
                container_makanan.arr[current_makanan].id = id;
                container_makanan.arr[current_makanan].nama = nama_makanan;
                container_makanan.arr[current_makanan].waktu_kedaluwarsa = expired;
                container_makanan.arr[current_makanan].lokasi_aksi = aksi;
                container_makanan.arr[current_makanan].lama_pengiriman = delivery;
                container_makanan.arr[current_makanan].size_x = size_x;
                container_makanan.arr[current_makanan].size_y = size_y;
                current_makanan++;
                id = 0;
                size_x = 0;
                size_y = 0;
                createString(&nama_makanan);
                createString(&aksi);
                D_expired = 0;
                H_expired = 0;
                M_expired = 0;
                D_delivery = 0;
                H_delivery = 0;
                M_delivery = 0;
                
            }
            next_digit = 0;
        }
    }
    // Set the last index
    container_makanan.arr[current_makanan].id = id;
    container_makanan.arr[current_makanan].nama = nama_makanan;
    container_makanan.arr[current_makanan].waktu_kedaluwarsa = expired;
    container_makanan.arr[current_makanan].lokasi_aksi = aksi;
    container_makanan.arr[current_makanan].lama_pengiriman = delivery;
    container_makanan.arr[current_makanan].size_x = size_x;
    container_makanan.arr[current_makanan].size_y = size_y;
    // MARK
    container_makanan.arr[current_makanan + 1].id = -9999;
    fclose(fp);
    return container_makanan;
}
// Helper
void CreateListDin(ListDin *l, int capacity){
   l->buffer = (int*) malloc (capacity*sizeof(int));
   l->nEff = 0;
   l->capacity = capacity;
}

void insertLast(ListDin *l, int child_ID){
   l->buffer[l->nEff] = child_ID;
   l->nEff++;    
}

void createResep (Resep * resep, int cap) {
    CreateListDin(&resep->child_ID, cap);
}

ListResep READRESEP()
{
    /* Algoritma */
    FILE *fp = fopen("../../test/resep_test.txt", "r");
    char cc = fgetc(fp);
    int n_resep = 0;
    while (cc != '\n')
    {
        n_resep *= 10;
        n_resep = ((int) cc) - 48;
        cc = fgetc(fp);
    }
    // cc = fgetc(fp);
    ListResep l_resep;
    int parent_ID = 0;
    int child_ID = 0;
    int space_count = 0;
    int n_child = 0;
    int current_index = 0;
    int last_child_ID = 0;
    int looper = 1;
    boolean first = true;
    while (cc != EOF)
    {
        cc = fgetc(fp);
        if (cc == ' ') {
            space_count++;
        }
        // Get ID parent
        if (cc != '\n') {
            if (space_count == 0){
                parent_ID *= 10;
                parent_ID += ((int) cc) - 48;
            }
            if (space_count == 1 && cc != ' ') {
                n_child *= 10;
                n_child += ((int) cc) - 48;
                // printf("%d", n_child);
            }
            if (space_count > 1){
                if (space_count == 2 && cc == ' '){
                    createResep(&l_resep.arr[current_index], n_child);
                }
                else {
                    if (cc != ' ' && ((int) cc) != -1){
                        child_ID *= 10;
                        child_ID += ((int) cc) - 48;
                    } else {
                        if (((int) cc) != -1){
                            insertLast(&l_resep.arr[current_index].child_ID, child_ID);
                            child_ID = 0;
                        }
                    }
                }

            }
        }
        // cc == '\n'
        else {
            insertLast(&l_resep.arr[current_index].child_ID, child_ID);
            child_ID = 0;
            l_resep.arr[current_index].parent_ID = parent_ID;
            parent_ID = 0;
            space_count = 0;
            current_index++;
            n_child = 0;
            looper++;
        }
        // cc = fgetc(fp);
    }
    // last index
    insertLast(&l_resep.arr[current_index].child_ID, child_ID);
    child_ID = 0;
    l_resep.arr[current_index].parent_ID = parent_ID;
    parent_ID = 0;
    space_count = 0;
    current_index++;
    n_child = 0;
    l_resep.arr[current_index].parent_ID = -9999;
    
    fclose(fp);
    return l_resep;
}