#include <stdio.h>
#include "charmachine.h"
#include "wordmachine.h"
// Driver ADT Mesin Karakter & Kata

// Untuk keperluan print peta
void displayMatrix(Matrix m)
{
    /* I.S. m terdefinisi */
    /* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
       dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan newline */
    /* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
    int i, j;
    for (i = 0; i < m.rowEff+2; i++)
    {
        for (j = 0; j < m.colEff+2; j++)
        {
            printf("%c", m.mem[i][j]);
            if (j != (m.colEff + 1))
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main () {
    Matrix m;
    char scanf_enter;
    char filename[100];
    printf("Masukkan nama file peta : ");
    scanf("%99s%c", filename, &scanf_enter);
    printf("\nHasil konfigurasi: \n");
    READPETA(&m, filename);
    displayMatrix(m);
    printf("Row : %d\n", m.rowEff);
    printf("Col : %d\n", m.colEff);
    Word command;
    scanWord(&command, "Masukkan Command : ");
    char * ans = commandOptions(command);
    printf("Command yang diberikan : %s", ans);
    return 0;
}