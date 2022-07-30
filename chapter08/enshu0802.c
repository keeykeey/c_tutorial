#include <stdio.h>
#define max(x,y) (((x)>(y)) ? (x) : (y))

int main(void) {
    int max1 = max(max(2,3),max(4,1));
    int max2 = max(max(max(2,3),4), 1);

    printf("max1 : %d\n",max1);
    printf("max2 : %d\n",max2);

    return 0;
}