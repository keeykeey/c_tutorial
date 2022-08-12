#include <stdio.h>

void adjust_point(int *n) {
    if(*n>100){
        *n = 100;
    }else if(*n<0){
        *n = 0;
    }
}

int main(void){
    int a = 101;
    int b = 50;
    int c = -1;
    adjust_point(&a);
    adjust_point(&b);
    adjust_point(&c);

    printf("a : %d\n",a);
    printf("b : %d\n",b);
    printf("c : %d\n",c);

    return 0;
}