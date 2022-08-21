#include <stdio.h>
#include <time.h>

#define ARY_LEN 10
#define NAME_LEN 128
#define YES 1
#define NO 0

typedef struct person{
    char name[NAME_LEN];
    double height;
    double weight;
}person_t;

int main(void){
    int select = NO;
    person_t person[ARY_LEN];
    int count=0;
    
    while(1){
        printf("名簿を追加しますか？\n 0・・・No  1・・・Yes\n :");scanf("%d",&select);
        if (select){
            if (count>ARY_LEN){
                printf("名簿追加の上限に達しています。\n");
                break;
            }
            printf("名前を入力して下さい : ");scanf("%s",person[count].name);
            printf("身長を入力して下さい : ");scanf("%lf",&person[count].height);
            printf("体重を入力して下さい : ");scanf("%lf",&person[count].weight);        
        }else{
            printf("終了します。\n");
            break;
        }
        count++;
        select = 0;
    }

    FILE *fp;
    fp = fopen("date.dat","w");
    for (int i=0; i<count; i++){
        fprintf(fp,"%-10s %5.1lf %5.1lf\n",person[i].name, person[i].height, person[i].weight);
    }
    fclose(fp);

    return 0;    
}
