#ifndef __STRING_H__
#define __STRING_H__

#include "../sederhana/boolean.h"

typedef struct
{
    char * content; /* container character */
    int Length;
} string;

void createString (string * str);
/* Menginisialisasi string kosong
   I.S. : str sembarang 
   F.S. : terbentuk string kosong dengan panjang 0 */

string createStringFromArr(char arr[], int arr_length);
/* Membentuk string dari arr character & panjang arr yang diberikan */

string copyString(string input);
/* Mencopy string input dan mengembalikan copynya */

string appendCCtoStr(string str, char cc);
/* Menambahkan cc ke str */

boolean cmpStrType2(char * str1, char * str2);
/* Membandingkan str1 dan str2 char pointer type */

boolean hasSubstring (string sub, string str);
/* Mengecek apakah sub ada di dalam str */

#endif