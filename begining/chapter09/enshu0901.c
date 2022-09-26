#include <stdio.h>

int main(void) {
    char str[] = "ABC\0DEF";
    printf("文字列strは\"%s\"です。\n",str);

    return 0;
    /*
        ABCの直後の\0によって、文字列が終了となる。
        printfで表示されるのは、ABCのみ。DEFは表示されない。
    */
}