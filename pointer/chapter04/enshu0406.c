#include <stdio.h>

int str_dignum(const char *s)
{
    int cnt = 0;
    int safty = 0;
    while (*s) {
        if (*s >= '0' && *s <= '9') {
            cnt++;
        }
        safty++;
        if (safty > 30) {
            printf("killing process because of too much loop\n");
        }
        s++;
    }
    return cnt;
}

int main(void)
{
    char *s = "ASD1234G789G";
    int cnt = 0;

    cnt = str_dignum(s);
    printf("数字文字は%d個見つかりました。\n",cnt);

    return 0;
}