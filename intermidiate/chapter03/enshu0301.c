#include <time.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int draw;
    int lose;
    int win;
} Score;

char *hd[] = {"rock", "scissors", "paper"};

void initialize(Score *s)
{
    s->win = s->lose = s->draw = 0;
    srand(time(NULL));
    printf("----- Game Start ----- \n");
}

void jyanken(int *h_hand, int *c_hand)
{
    *c_hand = rand() % 3;

    do {
        printf("\n Rock Papers Scissors\n\n");
        for (int i = 0; i < 3; i++)
            printf("(%d)%s ", i, hd[i]);
        printf(" : ");
        scanf("%d", h_hand);
    } while (*h_hand < 0 || *h_hand > 2);
}

void update_score_and_disp_result(Score *s, int result)
{
    switch (result) {
        case 0: 
            s->draw++; 
            puts("Draw");
            break;
        case 1: 
            s->lose++; 
            puts("Lose");
            break;
        case 2: 
            s->win++;  
            puts("Win");
            break;
    }
}

int confirm_retry(void)
{
    int x;
    printf("retry ? ・・・(0)No (1) Yes :");
    scanf("%d", &x);

    return x;
}

int main(void)
{
    Score score;

    initialize(&score);

    int retry;

    do {
        int human;
        int comp;

        jyanken(&human, &comp);

        printf("Computer: %s\nYou: %s\n", hd[comp], hd[human]);

        int judge = (human - comp + 3) % 3;

        update_score_and_disp_result(&score, judge);

        retry = confirm_retry();

    } while (retry == 1);

    printf("Score\nWin: %d Lose: %d Draw: %d", score.win, score.lose, score.draw);

    return 0;
}

