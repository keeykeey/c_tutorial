#include <stdio.h>
#define ELEMENTS 2

typedef struct tm {
    int     day;
    int     hour;
    int     minutes;
    int     seconds;
} tm_t;

void getInputNumber(tm_t* tm){
    printf("日にちを入力してください。:"); scanf("%d",&tm->day);
    printf("時間を入力してください。:"); scanf("%d",&tm->hour);
    printf("分を入力してください。:"); scanf("%d",&tm->minutes);
    printf("秒を入力してください。:"); scanf("%d",&tm->seconds);    
}

int main(void) {
    tm_t *tm;
    
    getInputNumber(tm);

    /* 書き込み */
    FILE *dfp;
    if ((dfp = fopen("numbers.txt","wb")) == NULL){
        printf("numbers.txtファイルを開けません。\n");
    } else {
        fwrite(&tm->day, sizeof(int), 1, dfp);
        fwrite(&tm->hour, sizeof(int), 1, dfp);
        fwrite(&tm->minutes, sizeof(int), 1, dfp);
        fwrite(&tm->seconds, sizeof(int), 1, dfp);
        fclose(dfp);
    }
    
    /* 読み込み */
    FILE *sfp;
    if ((sfp = fopen("numbers.txt","rb")) == NULL) {
        printf("numbers.txtファイルを開けません。\n");
    } else {
        fread(&tm->day, sizeof(double), ELEMENTS, sfp);
        fread(&tm->hour, sizeof(double), ELEMENTS, sfp+1);
        fread(&tm->minutes, sizeof(double), ELEMENTS, sfp+2);
        fread(&tm->seconds, sizeof(double), ELEMENTS, sfp+3);

        printf("day : %d\n",tm->day);
        printf("hour : %d\n",tm->hour);
        printf("minutes : %d\n",tm->minutes);
        printf("seconds : %d\n",tm->seconds);

        fclose(sfp);

    }

    return 0;
}