#include <stdio.h>

int main(void) {
    int i;
    int d = 0;
    float f = 0.0;
    
    for (i=0; i<=100; i++) {
        d += 1;
        f += 0.01;
    }

    printf("Int : %d \n",d);
    printf("Float : %f \n",f);

    return 0;
}