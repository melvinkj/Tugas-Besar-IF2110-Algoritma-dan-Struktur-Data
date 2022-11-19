#include <stdio.h>
#include "string.h"

int main() {
    string str = { .content = "hello ther" , .Length = 9 };
    char arr[40] = {'h','e','l','l','o','h','e','l','l','o'};
    char cc = 'e';
    str = appendCCtoStr(str, cc);
    string result;
    createString(&result);
    result = createStringFromArr(arr, 20);
    printf("%s\n", str.content);
    printf("%s\n", result.content);

    string str_cmp1, str_cmp2;
    createString(&str_cmp1);
    createString(&str_cmp2);
    str_cmp1.content = "sub";
    str_cmp2.content = "substring";
    if (hasSubstring(str_cmp1, str_cmp2)) printf("Yes\n");
    else printf("No\n");

    string str1 = { .content = "Copy this", .Length = 9};
    string str2 = copyString(str1);
    printf("%s", str2.content);
    printf("pass");

    return 0;
}
