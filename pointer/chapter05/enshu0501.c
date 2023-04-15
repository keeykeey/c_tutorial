#include <stdio.h>
#define ANIMALS_LENGTH 4

char *animal_name(int n)
{
    if(n < 0 || n >= ANIMALS_LENGTH) {
        return NULL;
    }

    char *animals[] = {
        "cat","dog","lion","bear"
    };

    return animals[n];
}

int main(void) {
    int input;
    int retry = 1;

    while (retry) {
        printf("英語名を知りたい動物の番号を選んでください（１〜４）\n");
        printf("0:猫, 1:犬, 2:ライオン, 3:熊\n :");
        scanf("%d", &input);

        char *name = animal_name(input);
        if (name) {
            printf("英語では%sです。\n",name);
        } else {
            printf("指定された動物は見つかりませんでした。\n");
        }

        printf("もう一度？\n0: no, 1:yes\n :");
        scanf("%d",&retry);
    }
    
    return 0;
}