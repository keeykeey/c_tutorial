#include <stdio.h>
#define NUMBER 5

int bsort(int a[], int n) {
    int i,j;
    for (i=n-1; i>=0; i--){
        for (j=0; j < i; j++ ){
            if (a[j] > a[j+1]) {
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
    return 0;
}

int main(void) {
    int a[NUMBER] = {3,5,2,7,1};
    int i;

    bsort(a,NUMBER);

    for (i=0; i<NUMBER; i++) {
        printf("%d : %d \n",i,a[i]);
    }
    return 0;
}
