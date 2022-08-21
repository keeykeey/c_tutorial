#include <stdio.h>
#define IS_DECIMAL 1
#define NOT_DECIMAL 0

int count_decimal(char c){
    if ((c-'0')>=0 && (c-'0')<=9){
        return IS_DECIMAL;
    }
    return NOT_DECIMAL;
}

int main(void){
    char fname[FILENAME_MAX];
    FILE *fp;

    printf("ファイル名を指定して下さい。\n :");
    scanf("%s",fname);

    int count=0;
    int i=0;
    int ch;
    if((fp=fopen(fname,"r"))==NULL){
        printf("\aファイルを開けません。\n");
    }else{
        while((ch=fgetc(fp)) != EOF){
            count += count_decimal(ch);
        }
    }
    fclose(fp);

    printf("ファイルには%d個の数字がありました。\n",count);

    return 0;
}