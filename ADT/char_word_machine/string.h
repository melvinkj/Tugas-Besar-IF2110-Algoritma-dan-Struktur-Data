#ifndef __STRING_H__
#define __STRING_H__

#include "D:\OneDrive - Institut Teknologi Bandung\File Jimly\College Files\Semester 3\Algoritma & Struktur Data\Tubes\Tugas-Besar-IF2110-Algoritma-dan-Struktur-Data\ADT\sederhana\boolean.h"
// #include "../sederhana/boolean.h"

typedef struct
{
    char * content; /* container character */
    int Length;
} string;

/* Initializing empty string */
void createString (string * str);

/* Convert Array of char to string */
string createStringFromArr(char arr[], int arr_length);

string appendArrToStr (string str, char arr[], int arr_length);

string copyString(string input);

/* Append char to given string */
string appendCCtoStr(string str, char cc);

boolean cmpStrType1(string str1 ,string str2);

boolean cmpStrType2(char * str1, char * str2);

boolean hasSubstring (string sub, string str);


#endif