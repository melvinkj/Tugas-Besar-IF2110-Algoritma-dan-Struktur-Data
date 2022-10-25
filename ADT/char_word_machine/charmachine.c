/* File: charmachine.c */
/* Implementasi Mesin Karakter */

#include <stdio.h>
#include "charmachine.h"
#include "makanan.c"

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
void READPETA(Matrix *m, char * filename)
{
    /* Algoritma */
    FILE *fp = fopen(filename, "r");
    char cc = fgetc(fp);
    int char_to_int = 0;
    int looper = 0;
    int i = 0, j = 1;
    boolean readRow = false;
    if (fp == NULL){
        printf("Filename not found!");
    } else {
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
                for (int k = 0; k < m->colEff+1; k++) {
                    m->mem[0][k] = '*';
                    m->mem[m->rowEff+1][k] = '*';
                }
                for (int h = 0; h < m->rowEff+2; h++){
                    m->mem[h][0] = '*';
                    m->mem[h][m->colEff+1] = '*';
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

void READMAKANAN(Matrix *m)
{
    /* Algoritma */
    FILE *fp = fopen("makanan_test.txt", "r");
    char cc = fgetc(fp);
    int n_makanan = 0;
    int looper = 0;
    boolean read_n = false;
    while (cc != '\n') {
        n_makanan *= 10;
        n_makanan = ((int) cc) - 48;
        cc = fgetc(fp);
    }
    // cc == '\n'
    Makanan container_makanan[n_makanan];
    Makanan makanan;
    // Data makanan
    int id = 0;
    string nama_makanan;
    string aksi;
    TIME expired;
    TIME delivery;

    // Looping data ke - n
    int counter = 0;
    while (looper < n_makanan && cc != EOF)
    {   
        cc = fgetc(fp);
        // Retrieve ID
        if (counter % 5 == 0) {
            id *= 10;
            id += ((int) cc) -  48;
        }
        // Get name
        if (counter % 5 == 1) {
            
        }


        looper++;
        
    }
    fclose(fp);
}

void READRESEP(Matrix *m)
{
    /* Algoritma */
    FILE *fp = fopen("peta_test.txt", "r");
    char cc = fgetc(fp);
    

    while (cc != EOF)
    {
    }
    fclose(fp);
}