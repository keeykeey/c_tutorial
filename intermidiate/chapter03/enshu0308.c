#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct {
    int draw;
    int lose;
    int win;
} Score;

char *hd[] = {"グー", "チョキ", "パー"};


int initialize(Score *s)
{
    s->win = s->lose = s->draw = 0;
    srand(time(NULL));
    printf("----- Game Start ----- \n");

    int n;
    printf("何回戦しますか？ : ");
    scanf("%d", &n);

    return n;
}

void jyanken(int *h_hand, int *c1_hand, int *c2_hand, int *c3_hand)
{
    *c1_hand = rand() % 3;
    *c2_hand = rand() % 3;
    *c3_hand = rand() % 3;

    do {
        printf("\n Rock Papers Scissors\n\n");
        for (int i = 0; i < 3; i++)
            printf("(%d)%s ", i, hd[i]);
        printf(" : ");
        scanf("%d", h_hand);
    } while (*h_hand < 0 || *h_hand > 2);
}

void update_score(Score *s, int result)
{
    switch (result) {
        case 0: s->draw++; break;
        case 1: s->lose++; break;
        case 2: s->win++; break;
    }
}

void disp_result(int result)
{
    switch (result) {
        case 0: puts("Draw"); break;
        case 1: puts("Lose"); break;
        case 2: puts("Win"); break;
    }
}

int judgeBetween4(int judge1, int judge2, int judge3) {
    int final_judge;
    switch (judge1) {
        case 0: {
            if (!(judge2 * judge3)) {
                final_judge = judge2 ? judge2 : judge3;
            } else if (judge2 * judge3 % 2 == 1) {
                final_judge = 1;
            } else if (!(judge2 * judge3 % 2)) {
                if ((judge2 == 1) || (judge3 == 1)) {
                    final_judge = 0;
                } else {
                    final_judge = 2;
                }
            }
            break;
        }
        case 1: {
            if ((judge2 == 2) || (judge3 == 2)) {
                final_judge = 0;
            } else {
                final_judge = 1;
            }
            break;
        }
        case 2: {
            if ((judge2 == 1) || (judge3 == 1)) {
                final_judge = 0;
            } else {
                final_judge = 2;
            }
            break;
        }
        default: break;
    }
    return final_judge;
}

int main(void)
{
    Score score;

    int n = initialize(&score);

    while(n--) {
        int human;
        int comp1;
        int comp2;
        int comp3;

        jyanken(&human, &comp1, &comp2, &comp3);

        printf("Com1は%sで、Com2は%sで、Comp3は%sで、あなたは%sです。\n",hd[comp1], hd[comp2], hd[comp3], hd[human]);

        int judge1 = (human - comp1 + 3) % 3;
        int judge2 = (human - comp2 + 3) % 3;
        int judge3 = (human - comp3 + 3) % 3;
        int judge = judgeBetween4(judge1, judge2, judge3);

        update_score(&score, judge);

        disp_result(judge);
    }

    printf("%d勝%d負%d分けでした。\n",score.win, score.lose, score.draw);

    return 0;
}