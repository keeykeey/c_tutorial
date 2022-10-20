#include <stdio.h>


void ary_cpy(int a[], const int b[], int n) {
    for (int i=0; i<n; i++){
        *a++ = *b++ ;
    }
}

int main(void) {
    int a[5] = {1, 2, 3, 4, 5};
    int b[5] = {10, 20, 30, 40, 50};

    int ary_size = (unsigned) (sizeof(b)/sizeof(b[0]));

    for (int i=0; i<ary_size; i++){
        printf("%d\n",a[i]);
    }

    ary_cpy(a, b, ary_size);

    for (int i=0; i<ary_size; i++){
        printf("%d\n",a[i]);
    }
}