#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_GAME_COUNT 10

typedef struct {
    int draw;
    int lose;
    int win;
} score_t;

typedef struct {
    int game_count;
    int h_hand;
    int c_hand;
    int result;
} game_result_log_t;

char *hd[] = {"グー", "チョキ", "パー"};
char *result_master[] = {"Draw", "You Lose", "You Win"};

int initialize(score_t *s)
{
    s->win = s->lose = s->draw = 0;
    srand(time(NULL));
    printf("----- Game Start ----- \n");

    int n;
    do {
        printf("何回戦しますか？ : ");
        scanf("%d", &n);
        if (n > MAX_GAME_COUNT && n < 1) {
            printf("1から10までの数字を入力してください。");
        } 
    } while (n > 10 &&  n < 1);

    return n;
}

void jyanken(int *h_hand, int *c_hand)
{

    do {
        printf("\n Rock Papers Scissors\n\n");
        for (int i = 0; i < 3; i++)
            printf("(%d)%s ", i, hd[i]);
        printf(" : ");
        scanf("%d", h_hand);
    } while (*h_hand < 0 || *h_hand > 2);

    *c_hand = rand() % 3;
}

void update_score(score_t *s, int result)
{
    switch (result) {
        case 0: s->draw++; break;
        case 1: s->lose++; break;
        case 2: s->win++; break;
    }
}

void update_game_result_log(game_result_log_t grl_array[MAX_GAME_COUNT], game_result_log_t gr) {
    if (gr.game_count < 1 || gr.game_count > 10) {
        printf("ゲーム回数が不正です。\n");
    } else {
        grl_array[gr.game_count-1] = gr;
    }
}

void disp_result(int result)
{
    switch (result) {
        printf("%s\n",result_master[result]);
    }
}

int main(void)
{
    score_t score;
    game_result_log_t game_result_log[MAX_GAME_COUNT];

    int n = initialize(&score);

    int game_count = 1;
    while(game_count <= n) {
        int human;
        int comp;

        jyanken(&human, &comp);

        printf("私は%sで、あなたは%sです。\n",hd[comp], hd[human]);

        int judge = (human - comp + 3) % 3;

        update_score(&score, judge);

        game_result_log_t grl;
        grl.game_count = game_count++;
        grl.h_hand = human;
        grl.c_hand = comp;
        grl.result = judge;
        update_game_result_log(game_result_log, grl);

        disp_result(judge);
    }

    printf("\nRESULT\n %d勝%d負%d分けでした。\n",score.win, score.lose, score.draw);
    printf("ゲームの履歴を表示します。\n");
    for (int i=0; i<n; i++) {
        printf("Game Number %d\n You: %s\n Computer: %s\n Result: %s\n",
            game_result_log[i].game_count,
            hd[game_result_log[i].h_hand],
            hd[game_result_log[i].c_hand],
            result_master[game_result_log[i].result]
        );
    }
    return 0;
}