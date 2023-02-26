#include <stdio.h>

int str_chnum(const char *s, int c)
{
    int cnt = 0;
    int safety = 0;
    while (*s) {
        if (*s == c) {
            cnt ++;
        }
        safety++;
        if (safety > 30) {
            printf("kill process beacause of too much loop\n");
            break;
        }
        s++;
    };
    
    return cnt;
}

int main(void) {
    char *s = "ABCBBA";

    int cnt = str_chnum(s, 'B');

    printf("cnt = %d\n",cnt);

    return 0;
}