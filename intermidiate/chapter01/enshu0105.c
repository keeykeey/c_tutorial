#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    int max, min;
    srand(time(NULL));
    int range1 = rand() % 10000;
    int range2 = rand() % 10000;

    if (range1 > range2) {
        max = range1;
        min = range2;
    } else {
        max = range2;
        min = range1;
    }
    
    int ans = min + rand() % (max+1);
    int count = retCountToAnswer(ans);
    if (!count) {
        printf("エラー。ゲームが開始できません。\n");
        return 0;
    }

    int input;

    while(count) {
        printf("%dから%dの範囲で、正解は何番ですか？\n :",min, (max+min));
        scanf("%d",&input);
        
        if (!--count && (ans != input)) {
            printf("残念。正解は%dです。\n",ans);
            return 0;
        }

        if (ans < input) {
            printf(" 正解はもっと小さい数字です。\n あと%d回答えることができます。\n",count);
        } else if (ans > input) {
            printf(" 正解はもっと大きい数字です。\n あと%d回答えることができます。\n",count);
        } else {
            printf("正解です。\n");
            break;
        }
    }
    
    return 0;
}