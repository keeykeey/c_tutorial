#include<stdio.h>

void hello() {
    printf("hello\n");
}

void sort(int *arr[3][2]) {
    int i,j;
    for (i=0; i<3; i++) {
        for (j=0; j<2; j++) {
            printf(" arr[%d][%d] : %p\n", i, j, arr[i][j]);
        }
    }
}

int main() {
    int a, b, c, d, e, f;
    int *arr[3][2] = {
        {&a, &b},
        {&c, &d},
        {&e, &f},
    };
    sort(arr);
    return 0;
}


