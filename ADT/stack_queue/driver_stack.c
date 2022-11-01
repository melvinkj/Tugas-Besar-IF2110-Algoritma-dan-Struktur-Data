#include "stack.h"
#include <stdio.h>

int main(){
    Stack s;
    CreateEmpty(&s);
    int x;
    x = 1;
    int *p = &x;
    *p = *p-1;
    Pop(&s, &x);
    printf("%d", x);
}