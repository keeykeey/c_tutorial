#include <stdio.h>

void swap(int *d1,int *d2) {
    if (*d1 > *d2) {
        int tmp = *d1;
        *d1 = *d2;
        *d2 = tmp;
    }
}

int sort_ptr3ary(int *x[]) {
    swap(x[0],x[1]);
    swap(x[0],x[2]);
    swap(x[1],x[2]);

    return 0;
}

int main(void) {
    int d1 = 10;
    int d2 = 5;
    int d3 = 7;
    int *x[3] = {&d1, &d2, &d3};
    int ret = sort_ptr3ary(x);

    if (ret == 1) {
        return 1;
    }else{
        for (int i=0; i<3; i++){
            printf("*x[%d] : %d\n",i,*x[i]); //5,7,10
        }
    }

    return 0;
}