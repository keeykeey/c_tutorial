#include <stdio.h>
#include <time.h>
#define FEELING_LEN 10

char data_file[]="enshu1305.dat";

void get_data(void){
    FILE *fp;
    if((fp=fopen(data_file,"r"))==NULL){
        printf("本プログラムを実行するのは初めてですね。\n");
    }else{
        int year, month, day, h, m, s;
        char str[FEELING_LEN];
        fscanf(fp,"%d%d%d%d%d%d%s",&year,&month,&day,&h,&m,&s,str);
        printf("前回は%d年%d月%d日%d時%d分%d秒で、気分は%sでした。\n",
            year,month,day,h,m,s,str);
        fclose(fp);
    }
}

void put_data(void){
    FILE *fp;
    time_t current = time(NULL);
    struct tm *timer = localtime(&current);
    char feeling[FEELING_LEN];

    printf("今の気分を入力して下さい。\n :");
    scanf("%s",feeling);

    if((fp = fopen(data_file,"w")) == NULL){
        printf("\aファイルをオープン出来ません。\n");
    }else{
        fprintf(fp,"%d %d %d %d %d %d %s\n",
            timer->tm_year + 1900, timer->tm_mon + 1, timer->tm_mday,
            timer->tm_hour, timer->tm_min, timer->tm_sec, feeling);
        fclose(fp);
    }
}

int main(void){
    get_data();
    put_data();

    return 0;
}