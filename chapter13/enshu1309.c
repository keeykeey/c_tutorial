#include <stdio.h>

int ltob(char ch) {
    if ((ch >= 'a') & (ch <= 'z')) {
        return (ch + 'A' - 'a');
    }else{
        return ch;
    }

}

void ccopy_ltob(FILE *sfile, FILE *dfile){
    printf("コピーするファイルの中身を表示します。\n\n");
    int ch;
    while ((ch = fgetc(sfile)) != EOF) {
        putchar(ch);
        ch = ltob(ch);
        fputc(ch,dfile);
    }
    printf("\n\nコピーが完了しました。\n");
}


int main(void) {
    FILE *sfp;
    FILE *dfp;
    char sname[FILENAME_MAX];
    char dname[FILENAME_MAX];

    printf("コピー元のファイル名 :"); scanf("%s",sname);
    printf("コピー先のファイル名 :"); scanf("%s",dname);

    if ((sfp=fopen(sname,"r")) == NULL) {
        printf("コピー元のファイルを開けませんでした。\n");
    } else {
        if ((dfp=fopen(dname,"w"))==NULL){
            printf("コピー先のファイルを開けませんでした。");
        } else {
            ccopy_ltob(sfp,dfp);
            fclose(dfp);
        }
    fclose(sfp);
    }

    return 0;

}