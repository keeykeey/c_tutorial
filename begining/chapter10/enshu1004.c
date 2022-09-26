#include <stdio.h>

void set_idx(int *v, int n){
    for (int i=0; i<n ;i++){
        *(v+i) = i;
    }
}

int main(void) {
    int s[5] = {10,2,5,14,3};
    set_idx(s,5);

    for (int i=0; i<5; i++){
        printf("s[%d] : %d\n",i,s[i]);
    }

    return 0;
}