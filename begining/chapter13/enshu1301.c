#include <stdio.h>
#define STR_LEN 128

int main(void){
    FILE *fp;
    char s[STR_LEN];
    printf("ファイル名を入力して下さい。\n : ");
    scanf("%s",s);

    fp = fopen(s,"r");

    if (fp == NULL)
        printf("\aファイル\"%s\"をオープン出来ませんでした。\n",s);
    else {
        printf("\aファイル\"%s\"をオープンしました。\n",s);
        fclose(fp);
    }

    return 0;
}