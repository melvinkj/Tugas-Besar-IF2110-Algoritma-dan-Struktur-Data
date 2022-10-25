#include "string.h"
#include <stdlib.h>
#include <stdio.h>


void createString (string * str) {
    str->content = "";
    str->Length = 0;
}

string createStringFromArr(char arr[], int arr_length) {
    string new_str;
    createString(&new_str);
    string result;
    for (int i = 0; i < arr_length; i++){
        new_str = appendCCtoStr(new_str, arr[i]);
    }
        result = new_str;
    return result;
}

string appendCCtoStr(string str, char cc) {
    char * container = malloc ((str.Length + 1)*sizeof(char));
    char * ptr = container;
    char * s = str.content;
    while (*s != '\0') {
        *ptr++ = *s++;
    }
    *ptr++ = cc;
    *ptr++ = '\0';
    string new_str;
    new_str.content = container;
    new_str.Length = str.Length + 1;
    return new_str;
}

