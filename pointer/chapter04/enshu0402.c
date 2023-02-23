#include <stdio.h>

int main(void) {
    char str[5];
    printf("s[4]に文字を入れて下さい。\n");
    scanf("%s",str);
    printf("入力された文字は\"%s\"です。\n",str);
    return 0;
}
