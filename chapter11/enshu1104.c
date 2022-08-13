#include <stdio.h>

void put_string(const char *s){
    while (*s){
        putchar(*s);
        *s++;
    }
    putchar('\n');
}

int main(void){
    char *s = "ABC";
    put_string(s);
}