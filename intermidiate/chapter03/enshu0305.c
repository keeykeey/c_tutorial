#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define TIME_CP_ALWAYS_WINS 3

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

void jyanken(int *h_hand, int *c_hand, int present_game_count)
{
    if (present_game_count % TIME_CP_ALWAYS_WINS != 0)
        *c_hand = rand() % 3;

    do {
        printf("\n Rock Papers Scissors\n\n");
        for (int i = 0; i < 3; i++)
            printf("(%d)%s ", i, hd[i]);
        printf(" : ");
        scanf("%d", h_hand);
    } while (*h_hand < 0 || *h_hand > 2);

    if (present_game_count % TIME_CP_ALWAYS_WINS == 0)
      *c_hand = (*h_hand + 2) % 3;
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
        case 1: puts("You lose"); break;
        case 2: puts("You win"); break;
    }
}

int main(void)
{
    Score score;

    int n = initialize(&score);
    int present_game_count = 1;

    while(n--) {
        int human;
        int comp;

        jyanken(&human, &comp, present_game_count++);

        printf("私は%sで、あなたは%sです。\n",hd[comp], hd[human]);

        int judge = (human - comp + 3) % 3;

        update_score(&score, judge);

        disp_result(judge);
    }

    printf("\nRESULT\n %d勝%d負%d分けでした。\n",score.win, score.lose, score.draw);

    return 0;
}