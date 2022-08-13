#include <stdio.h>

void swap(int *n1,int *n2) {
    int tmp = *n1;
    if (*n1>=*n2){
        ;
    }else if(*n1<*n2){
        *n1 = *n2;
        *n2 = tmp;
    }
}

void sort3(int *n1, int *n2, int *n3) {
    swap(n2,n3);
    swap(n1,n2);
    swap(n2,n3);
}

int main(void){
    int n1,n2,n3;
    printf("一つ目の数字 : "); scanf("%d",&n1);
    printf("二つ目の数字 : "); scanf("%d",&n2);
    printf("三つ目の数字 : "); scanf("%d",&n3);

    sort3(&n1,&n2,&n3);

    printf("n1 : %d\n",n1);
    printf("n2 : %d\n",n2);
    printf("n3 : %d\n",n3);

    return 0;

}