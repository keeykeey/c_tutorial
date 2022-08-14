#include <stdio.h>
#include <ctype.h>

void str_toupper(char s[]){
    while(*s){
        *s = toupper(*s);
        printf("%c",*s);
        s++;
    }
}

void str_tolower(char s[]){
    while(*s){
        *s = tolower(*s);
        printf("%c",*s);
        s++;
    }
}

int main(void){
    char s1[] = "AaBbCcDd";
    str_toupper(s1);
    printf("\n");

    char s2[] = "AaBbCcDd";
    str_tolower(s2);
    printf("\n");

    return 0;
}
