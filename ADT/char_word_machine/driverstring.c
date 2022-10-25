#include <stdio.h>
#include "string.h"

// Run Path : gcc string.c driverstring.c -o a

int main() {
    string str = { .content = "hello worl" , .Length = 9 };
    char arr[40] = {'h','e','l','l','o','h','e','l','l','o','h','e','l','l','o','h','e','l','l','o'};
    char cc = 'd';
    str = appendCCtoStr(str, cc);
    string result;
    createString(&result);
    result = createStringFromArr(arr, 20);
    printf("%s\n", str.content);
    printf("%s\n", result.content);
    return 0;
}
