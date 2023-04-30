#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define STAGE 3

int main(void)
{
    srand(time(NULL));
    int times_array[STAGE];
    int sum = 0;

    printf("GAME START!!\n");

    for (int stage = 0; stage < STAGE; stage++) {
        int a = 10 + rand() % 9;
        int b = 10 + rand() % 9;
        int c = 10 + rand() % 9;
        int n = rand() % 17;

        time_t start = time(NULL);
        printf("%d%*s+%*s%d%*s+%*s%d%*s : ",a,n,"",n,"",b,n,"",n,"",c,n,"");
        
        do {
            int x;
            scanf("%d",&x);
            if (x == a + b +c)
                break;
            printf("\a間違えです。再入力してください。 : ");
        } while(1);
        time_t end = time(NULL);
        times_array[stage] = difftime(end, start);
        sum += times_array[stage];
    }
    printf("%.1d秒かかりました。平均%.1f秒です。\n", sum, (float)sum/STAGE);
    printf("各計算所要時間は、以下です。\n");
    for (int i=0; i < STAGE; i++) {
        printf("%d回目 : %d秒\n",i,times_array[i]);
    }

    return 0;
}