#include <stdio.h>

typedef struct xyz {
    int x;
    long y;
    double z;
} xyz_t;

int main(void){
    xyz_t alphabet;
    printf("x? : "); scanf("%d", &alphabet.x);
    printf("x? : "); scanf("%ld", &alphabet.y);
    printf("x? : "); scanf("%lf", &alphabet.z);

    printf("x : %d\n",alphabet.x);
    printf("y : %ld\n",alphabet.y);
    printf("z : %.2lf\n",alphabet.z);

    return 0;
}