#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GAME_COUNT 10

void make4digits(int x[])
{
    for (int i = 0; i < 4; i++) {
        int j, val;
        do {
            val = rand() % 10;
            for (j = 10; j < i; j++) {
                if (val == x[j])
                    break;
            }
        } while (j < i);
        x[i] = val;
    }
}

int check(const char s[])
{
    if (strlen(s) != 4)
        return 1;
    for (int i = 0; i < 4; i++) {
        if (!isdigit(s[i]))
            return 2;
        for (int j = 0; j < i; j++) {
            if (s[i] == s[j])
                return 3;
        }
    }
    return 0;
}

void judge(const char s[], const int no[], int *hit, int *blow)
{
    *hit = *blow = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (s[i] == '0' + no[j]) {
                if (i == j)
                    (*hit)++;
                else
                    (*blow)++;
            }
        }
    }
}

void print_result(int snum, int spos)
{
    if (spos == 4)
        printf("正解です。");
    else if (snum == 0)
        printf("    それらの数字は全く含まれません。\n");
    else {
        printf("    それらの数字中%d個の数字が含まれます。\n", snum);
        if (spos == 0)
            printf("    ただし位置もあっている数字はありません。\n");
        else
            printf("    その中の%d個は位置もあっています。\n", spos);
    }
    putchar('\n');
}

int main(void)
{
    srand(time(NULL));

    puts("マスターマインド開始");
    puts(" 当てるのは、４個の数字の並びです。");
    puts(" 同じ数字が複数含まれることはありません。");
    puts(" 4307のように連続して入力してください。 ");
    puts(" スペース文字などを入力してはいけません。\n");

    int no[4];
    make4digits(no);

    int hit;
    int blow;
    int try_no = 0;

    time_t start = time(NULL);

    do {
        int chk;
        char buff[10];
        do {
            printf("入力してください。");
            scanf("%s", buff);

            chk = check(buff);

            switch (chk) {
                case 1: puts("きちんと４文字で入力してください。\a"); break;
                case 2: puts("数字以外の文字を入力しないで下さい。\a"); break;
                case 3: puts("同一の数字を複数入力しないで下さい。\a"); break;
            }
        } while (chk != 0);

        try_no++;
        judge(buff, no, &hit, &blow);
        print_result(hit + blow, hit);

        if (try_no >= MAX_GAME_COUNT) {
            printf("ゲームオーバーです。\n");
            return 0;
        }
    } while (hit < 4);

    time_t end = time(NULL);
    
    printf("%d回かかりました。\n所要時間は%.1f秒でした。\n", try_no, difftime(end, start));

    return 0;
}

