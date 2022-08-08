#include <stdio.h>

void null_string(char s[]) {
    s[0] = '\0';
}

int main(void) {
    char s[] = "ABC";
    printf("ABC : %s\n",s);
    null_string(s);
    printf("ナル文字 : %s\n",s);
}