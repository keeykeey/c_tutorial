#include <stdio.h>

int main(void) {
    int i;
    float f;
    
    for (i=0; i<=100; i++) {
        printf("x = %.6f ",(float)i/100);
        printf("x = %.6f \n",f);
        f += 0.01;
    }

    return 0;
}