#include <stdio.h>
#include "charmachine.h"
#include "wordmachine.h"
#include "../sederhana/simulator.h"
// Driver ADT Mesin Karakter & Kata

// Run path : gcc wordmachine.c charmachine.c driverCharWordMachine.c -o a
char currentChar;
boolean EOP;

void displayPeta(Matrix m, Simulator S)
{
    /* I.S. m terdefinisi */
    /* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
       dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan newline */
    /* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
    int i, j;
    POINT currS = { .X = S.posisi.X , .Y = S.posisi.Y};
    for (i = 0; i < m.rowEff+2; i++)
    {
        for (j = 0; j < m.colEff+2; j++)
        {
            if (i == currS.Y && j == currS.X) {
                printf("S ");    
            } else {
                printf("%c", m.mem[i][j]);
                if (j != (m.colEff + 1))
                {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}

int main () {
    Matrix m;    
    Simulator S;
    S.posisi.X = 1;
    S.posisi.Y = 2;
    READPETA(&m, "../../test/peta_test.txt");
    displayPeta(m, S);
    printf("List Makanan\n");
    ListMakanan ans = READMAKANAN("../../test/makanan_test.txt");
    int k = 0;
    while (ans.arr[k].id != -9999) {
            printf("id : %d\n", ans.arr[k].id);
            printf("Nama : %s\n", ans.arr[k].nama.content);
            printf("Expired : ");
            TulisTIME(ans.arr[k].waktu_kedaluwarsa);
            printf("\n");
            printf("Delivery : ");
            TulisTIME(ans.arr[k].lama_pengiriman);
            printf("\n");
            printf("Aksi : %s\n", ans.arr[k].lokasi_aksi.content);
            printf("Ukuran x : %d", ans.arr[k].size_x);
            printf("\n");
            printf("Ukuran y : %d", ans.arr[k].size_y);
            printf("\n");
            printf("\n");
        k++;
    }

    printf("Info resep:\n");
    ListResep l_resep;
    l_resep = READRESEP("../../test/resep_test.txt");
    int i = 0;
    while (l_resep.arr[i].parent_ID != -9999) {
        printf("Parent ID: %d", l_resep.arr[i].parent_ID);
        printf("\n");
        printf("Child ID: ");
        int j;
        for (j = 0; j < l_resep.arr[i].child_ID.nEff; j++){
            printf("%d ", l_resep.arr[i].child_ID.buffer[j]);
        }
        printf(", total child = %d", j);
        printf("\n");
        i++;
    }

    string command;
    scanWord(&command);
    printf("Command yang diberikan : %s\n", command.content);
    printf("Status command: %s\n", commandOptions(command));

    string wait_cmd;
    scanWord(&wait_cmd);
    // asumsi input wait x y valid
    int extra_h, extra_m;
    processWaitCommand(wait_cmd, &extra_h, &extra_m);
    printf("Extra Hour: %d\n", extra_h);
    printf("Extra Minute: %d\n", extra_m);

    return 0;
}