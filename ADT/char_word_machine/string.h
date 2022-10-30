#ifndef __STRING_H__
#define __STRING_H__

#include "../sederhana/boolean.h"

typedef struct
{
    char * content; /* container character */
    int Length;
} string;

/* Initializing empty string */
void createString (string * str);

/* Convert Array of char to string */
string createStringFromArr(char arr[], int arr_length);

/* Append char to given string */
string appendCCtoStr(string str, char cc);

boolean cmpStrType1(string str1 ,string str2);

boolean cmpStrType2(char * str1, char * str2);

#endif