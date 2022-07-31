#include <stdio.h>

int combination(int n, int r) {
    //nCr  ex)4C3 = 4*3*2 / 3*2*1 = 4
    int ret, molecule, denominator; //戻り値、分子、分母

    molecule = 1;
    for (int i=0; i<r; i++) {
        molecule = molecule * (n-i);
    }

    denominator = 1;
    for (int i=0; i<r; i++) {
        denominator = denominator * (r-i);
    }

    ret = molecule / denominator ;

    return ret;
}

int main(void) {
    int tmp = combination(4,3);
    printf(" 4C3 : %d\n",tmp);

    tmp = combination(10,5);
    printf(" 10C5 : %d\n",tmp);

    return 0;
}