#include <stdio.h>

#define STR_LEN 128

int main(void){
    char s[STR_LEN];
    printf("ファイル名を入力して下さい。\n :");
    scanf("%s",s);

    FILE *fp;
    fp = fopen(s,"w");

    if (fp==NULL){
        printf("ファイル%sを開けませんでした。\n",s);
    }else{
        printf("ファイル%sを開きました。\n",s);
    }
    fclose(fp);

    return 0;
}