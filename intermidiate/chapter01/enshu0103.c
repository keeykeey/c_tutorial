#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand(time(NULL));
    int ans = (rand() % 1999) - 999;

    int count = 6;
    int input = 0;
    printf("数当てゲーム開始。-999から999のうち、正解は何番でしょうか？\n");
    do {
        scanf("%d",&input);
        count--;
        if (input < ans) {
            printf("もっと大きい数字です。あと%d回挑戦できます。\n",count);
        } else if ( input > ans) {
            printf("もっと小さい数字です。あと%d回挑戦できます。\n",count);
        } else {
            printf("正解です。\n");
        }
    } while (ans != input && 0 < count);

    if (!(0 < count))
        printf("ゲームオーバー\n");

    return 0;
}