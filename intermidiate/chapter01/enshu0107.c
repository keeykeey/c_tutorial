#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STAGE 4

int main(void)
{
    srand(time(NULL));

    int ans = rand() % 100;
    int no;

    int num[MAX_STAGE];
    int stage = 0;

    printf("0から99の整数を当てよう\n\n");

    do {
        printf("残り%d回。いくつかな : ",MAX_STAGE - stage);
        scanf("%d",&no);
        num[stage++] = no;

        if (no > ans)
            printf("もっと小さいよ。\a\n");
        else if (no < ans)
            printf("もっと大きいよ \a\n");
    } while (no != ans && stage < MAX_STAGE);

    if (no != ans)
        printf("残念。正解は%dです。\n",ans);
    else {
        printf("正解です。%d回目で当たりましたね。\n",stage);
    }

    puts("\n--- 入力履歴 ---");
    for (int i = 0; i< stage; i++) {
        printf(" %2d : %4d %-4d\n", i+1, num[i], num[i] - ans);
    }
    return 0;
}