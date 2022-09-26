#include <stdio.h>

int main(void){
    int ch;
    FILE *fp;
    char fname[FILENAME_MAX];
    int count;

    printf("fine name :");
    scanf("%s",fname);

    if((fp=fopen(fname,"r"))==NULL)
        printf("\acan\'t open the file\n");
    else{
        while((ch=fgetc(fp))!=EOF)
            if(ch=='\n'){
                count++;
            }
        fclose(fp);
    }

    printf("ファイルの行数は%d行でした。\n",count+1);

    return 0;
}