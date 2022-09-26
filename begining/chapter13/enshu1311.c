#include <stdio.h>
#define ELEMENTS 10

void getInputNumber(int n, double* ary){
    int i = 0;
    
    while(i < n){
        printf("数字を入力してください. : ");
        scanf("%lf",&ary[i]);
        i++;
    }    
}

int main(void) {
    double ary[ELEMENTS];
    double retAry[ELEMENTS];
    
    getInputNumber(ELEMENTS,ary);

    /* 書き込み */
    FILE *dfp;
    if ((dfp = fopen("numbers.txt","w")) == NULL){
        printf("numbers.txtファイルを開けません。\n");
    } else {
        int i;
        for (i=0; i<ELEMENTS; i++){
            fprintf(dfp,"%f",ary[i]);
            if (i != (ELEMENTS-1)) {
                fprintf(dfp,"\n");
            }
        }
        fclose(dfp);
    }
    
    /* 読み込み */
    FILE *sfp;
    if ((sfp = fopen("numbers.txt","r")) == NULL) {
        printf("numbers.txtファイルを開けません。\n");
    } else {
        int i;
        for (i=0; i<ELEMENTS; i++) {
            fscanf(sfp, "%lf", &retAry[i]);
            printf("%f\n",retAry[i]);
        }
        fclose(sfp);
    }
    
    return 0;

}

