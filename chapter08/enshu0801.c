#include <stdio.h>

#define diff(x,y) ((x) * (y))

int main(void) {
    int number = diff(2,2);
    double number2 = diff(2.5,4.0);
    printf("Int : %d\nDouble : %f\n",number,number2);

    return 0;
}