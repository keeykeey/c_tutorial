#include <stdio.h>

char *str_chr(const char *s, int c) {
    while(*s){
        if(*s==c){
            return s;
        }
        *s++;
    }
    s = NULL;
    return s;
}

int main(void){
    char *str = "abccba";
    char *s = str_chr(str,'c');
    printf("count c : %s\n",s);

    char *str2 = "abba";
    char *s2 = str_chr(str2,'c');
    printf("count c : %s\n",s2);
}
