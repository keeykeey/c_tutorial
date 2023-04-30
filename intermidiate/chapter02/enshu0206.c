#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define STAGE 3

int main(void)
{
    srand(time(NULL));
    float times_array[STAGE];
    float sum = 0;

    printf("GAME START!!\n");

    for (int stage = 0; stage < STAGE; stage++) {
        int a = 10 + rand() % 9;
        int b = 10 + rand() % 9;
        int c = 10 + rand() % 9;
        int n = rand() % 17;
        int mode = rand() % 4;

        time_t start = time(NULL);
        switch (mode) {
            case 0:
                printf("%d%*s+%*s%d%*s+%*s%d%*s : ",a,n,"",n,"",b,n,"",n,"",c,n,"");
                break;
            case 1:
                printf("%d%*s+%*s%d%*s-%*s%d%*s : ",a,n,"",n,"",b,n,"",n,"",c,n,"");
                break;
            case 2:
                printf("%d%*s-%*s%d%*s+%*s%d%*s : ",a,n,"",n,"",b,n,"",n,"",c,n,"");
                break;
            case 3:
                printf("%d%*s-%*s%d%*s-%*s%d%*s : ",a,n,"",n,"",b,n,"",n,"",c,n,"");
                break;
            default:
                break;
        }
        
        int is_loop = 1;
        while(is_loop){
            int x;
            scanf("%d",&x);
            switch (mode) {
                case 0:
                    if (x == a + b + c){
                        is_loop = 0;
                        break;
                    }
                case 1:
                    if (x == a + b - c) {
                        is_loop = 0;
                        break;
                    }
                case 2:
                    if (x == a - b + c) {
                        is_loop = 0;
                        break;
                    }
                case 3:
                    if (x == a - b - c) {
                        is_loop = 0;
                        break;
                    }
                default:
                    printf("\a間違えです。再入力してください。 : ");
                    break;

            }
        }
        time_t end = time(NULL);
        times_array[stage] = (float) difftime(end, start);
        sum += times_array[stage];
    }
    printf("%.1f秒かかりました。平均%.1f秒です。\n", sum, (float)sum/STAGE);
    printf("各計算所要時間は、以下です。\n");
    for (int i=0; i < STAGE; i++) {
        printf("%d回目 : %.1f\n",i,times_array[i]);
    }

    return 0;
}