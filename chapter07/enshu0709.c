#include <stdio.h>
#include <math.h>

//gcc -o enshu0709.out enshu0709.c -lm
//gccでコンパイルするときは、-lmをつける。
int main(void) {
    int number;
    printf("正方形の面積を入力してください : ");scanf("%d",&number);
    double dx = sqrt(number); 
    printf("その正方形の一辺の長さは%.2fです\n",dx);

    return 0;
}