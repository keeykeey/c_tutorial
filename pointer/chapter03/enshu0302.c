#include <stdio.h>

int main(){
    int arr[3][3][3] = {0};
    int n_el = (unsigned)sizeof(arr) / sizeof(arr[0][0][0]);
    printf("arrの要素数は%uです。\n",n_el);

    return 0;
}