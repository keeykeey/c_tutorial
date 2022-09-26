#include <stdio.h>

int main(void) {
    int count = 0;
    int ch;

    printf("文字を入力してください。\n : ");

    while ((ch=getchar()) != EOF) {
        if (ch == '\n') {
            count ++;
        }
    }

    printf("改行の数 : %d\n",count);

    return 0;

}