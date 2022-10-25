#ifndef __STRING_H__
#define __STRING_H__

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



#endif