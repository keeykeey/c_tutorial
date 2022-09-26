#include <stdio.h>

int factorial(int dismal) {
    if (dismal < 1) 
        return 0;
    
    int ret = dismal;
    while (dismal > 1) {
        ret = ret * (dismal-1);
        dismal--;
    }

    return ret;
}

int main(void) {
    int d1,d2;
    printf("階乗元の数値 : "); scanf("%d",&d1);

    d2 = factorial(d1);

    printf("%dの階乗は%dです。\n",d1,d2);

    return 0;
}