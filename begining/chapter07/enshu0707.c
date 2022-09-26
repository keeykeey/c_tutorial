#include <stdio.h>

int main(void) {
    float f;
    double d;
    long double ld;
    printf("float ? : "); scanf("%f",&f);
    printf("double ? : "); scanf("%lf",&d);
    printf("long double ? : "); scanf("%Lf",&ld);

    printf("%f, %f, %Lf\n",f,d,ld);
    return 0;
}