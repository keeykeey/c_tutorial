#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int startLottery()
{
    int n;
    printf("おみくじを引きますか？\n 0:no, 1:yes\n :");
    scanf("%d",&n);

    return n;
}

void showResult()
{
    srand(time(NULL));
    int r = 1 + rand() % 5;

    switch (r) {
        case 1:
            printf("大吉!\n");
            break;
        case 2:
            printf("中吉!\n");
            break;
        case 3:
            printf("小吉!\n");
            break;
        case 4:
            printf("吉!\n");
            break;
        case 5:
            printf("末吉!\n");
            break;
        case 6:
            printf("凶!\n");
            break;
        default:
            printf("失敗しました。\n");
            break;
    }
    
}

int main(void)
{
    if (startLottery()) {
        showResult();
    } else {
        printf("終了します。\n");
    }

    return 0;
}