#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{
    srand(time(NULL));
    int ans = 3 * rand() % 335 - 3;

    int count = 6;
    int input = 0;
    printf("数当てゲーム開始。3から999の中の３の倍数うち、正解は何番でしょうか？\n");
    do {
        scanf("%d",&input);
        if ((input % 3) && (argc > 1)) {
            printf("3の倍数しか入力できません。\n");
            break;
        } else if ((input % 3) && (argc == 1)) {
            printf("3の倍数しか入力できません。\n");
            continue;
        }

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