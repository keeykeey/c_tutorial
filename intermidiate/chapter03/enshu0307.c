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

void jyanken(int *h_hand, int *c1_hand, int *c2_hand)
{
    *c1_hand = rand() % 3;
    *c2_hand = rand() % 3;

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
        case 3: puts("Draw"); break;
    }
}

int judgeBetween3(int judge1, int judge2) {
    int sum = judge1 + judge2;
    int judge;
    switch (sum){
        case 0: judge = 0; break;
        case 1: judge = 1; break;
        case 2: {
            if ((judge1 == 1) && (judge2 == 1)) {
                // Lose Loseの時
                judge = 1; break;
            } else {
                // Win と Drawの時
                judge = 2; break;
            }
        }
        case 3: judge = 0; break;
        case 4: judge = 2; break;
        default:
            break;
    }
    return judge;
}

int main(void)
{
    Score score;

    int n = initialize(&score);

    while(n--) {
        int human;
        int comp1;
        int comp2;

        jyanken(&human, &comp1, &comp2);

        printf("Com1は%sで、Com2は%sで、あなたは%sです。\n",hd[comp1], hd[comp2], hd[human]);

        int judge1 = (human - comp1 + 3) % 3;
        int judge2 = (human - comp2 + 3) % 3;
        int judge = judgeBetween3(judge1, judge2);

        update_score(&score, judge);

        disp_result(judge);
    }

    printf("%d勝%d負%d分けでした。\n",score.win, score.lose, score.draw);

    return 0;
}