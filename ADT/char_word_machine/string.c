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
        // printf("%d\n", result.Length);
    return result;
}

string appendCCtoStr(string str, char cc) {
    int extra_size = 1;
    int current_len = str.Length;
    while (current_len > 4) {
        current_len -= 16;
        extra_size++;
    }
    char * container = malloc ((str.Length + extra_size)*sizeof(char));
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
// Compare direct string
boolean cmpStrType1(string str1 ,string str2) {
    return (str1.content == str2.content);
}

//Compare string of char * type
boolean cmpStrType2(char * str1, char * str2) {
    while (*str1 != '\0' || *str2 != '\0'){
        if (*str1 == *str2) {
            str1++;
            str2++;
        }
        else if ((*str1 == '\0' && *str2 != '\n') || (*str1 != '\0' && *str2 == '\n') || (*str1 != *str2)) {
            return false;
        }
    }
    return true;
}