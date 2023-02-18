#include <stdio.h>

/*
 * int mx[3][2][4]の全要素に同一の値を代入する。
 */
void put_n_to_3d_array(int (*mx)[2][4], int n_row, int n_to_put) {
    for (int i = 0; i<n_row; i++) {
       for (int j=0; j<2; j++) {
           for (int k=0; k<4; k++) {
               mx[i][j][k] = n_to_put;
               printf("%d",mx[i][j][k]);
           }
       }
       putchar('\n');
    }
} 

int main(void) {
    int  arr[3][2][4];
    put_n_to_3d_array(arr, 3, 5);
    return 0;
}