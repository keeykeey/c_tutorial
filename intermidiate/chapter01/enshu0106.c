#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int mode[4] = {1, 2, 3, 4};
int maxNumber[4] = {9, 99, 999, 9999};

int chooseGameLevel()
{
    int mode;
    do {
        printf("レベルを選んでください。(1) 1~9 (2)1~99 (3)1~999 (4)1~9999\n :");
        scanf("%d",&mode);
        if (!(mode >= 1) || !(mode <= 4)) {
            printf("1から4の整数を入力してください。\n");
            mode = 0;
        }
    } while (!mode);

    return mode;
}

int retCountToAnswer(int ans) {
    int count = 0;
    while(ans) {
        ans /= 10;
        count++;
        if (count > 20) {
            printf("too much loop\n");
            return 0;
        }
    }
    return count * 2 + 4;
}

int main(void)
{
    int mode = chooseGameLevel();
    int max = maxNumber[mode-1];

    srand(time(NULL));
    int ans = 1 + rand() % (max+1);
    int count = retCountToAnswer(ans);

    printf("1から%dの整数で、正解の数字を当ててください。\n :",max);
    while(count) {
        int input;
        scanf("%d",&input);
        
        if(!count-- && (ans != input)) {
            printf("残念。ハズレです。正解は%dです。\n",ans);
            return 0;
        }

        if (input < ans) {
            printf("正解はもっと大きい数字です。\n あと%d回入力できます。\n",count);
        } else if (input > ans) {
            printf("正解はもっと小さい数字です。\n あと%d回入力できます。\n",count);
        } else {
            printf("正解です。\n");
            break;
        }
    }
    return 0;
}
