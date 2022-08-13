#include <stdio.h>

int str_chnum(const char *s, char c){
    int i=0;
    while(*s){
        if (*s == c){
            i++;
        }
        s++;
    }
    return i;
}

int main(void){
    char *s = "CabCdCc";
    char *c = "C";
    int n = str_chnum(s,'C');
    printf("文字列%sには、文字%sが%d個含まれています。\n",s,c,n);

    return 0;
}