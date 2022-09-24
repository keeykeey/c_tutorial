#include <stdio.h>

void ccopy_file(FILE *sfile, FILE *dfile){
    printf("コピーするファイルの中身を表示します。\n\n");
    int ch;
    while ((ch = fgetc(sfile)) != EOF) {
        putchar(ch);
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
            ccopy_file(sfp,dfp);
            fclose(dfp);
        }
    fclose(sfp);
    }

    return 0;

}