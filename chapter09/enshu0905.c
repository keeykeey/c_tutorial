#include <stdio.h>

int str_char(const char s[], int c) {
    int i = 0;
    while(s[i] != '\0') {
        if (s[i] == c) {
            return i;
        }
        i++;
    }
    return -1;
}

int main(void) {
    char s[] = "abc";
    int ret = str_char(s,99);
    printf("cは左から%d文字目で見つかりました。\n",ret+1);
    return ret;
}