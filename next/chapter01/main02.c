#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATA_MAX   100
#define STRING_MAX 200

struct roll {
    char name[32];
    long birth;
    char phone[20];
    char mail[50];
};

static struct roll my_data[DATA_MAX];

int main(void)
{
    FILE          *fp;
    static char    buf[STRING_MAX];
    static char    name[32];
    long           i, count;

    if ((fp = fopen("data.dat", "r")) == NULL)
    {
        fprintf(stderr, "ファイルが見つかりませんでした。\n");
        exit( EXIT_FAILURE );
    }

    count = 0;
    while (fgets(buf, STRING_MAX, fp))
    {
        sscanf(buf, "%s %ld %s %s",
            my_data[count].name,
            &my_data[count].birth,
            my_data[count].phone,
            my_data[count].mail
        );
        count++;
        if (count > DATA_MAX)
            break;
    }

    printf("探したい名前を入力して下さい。");
    scanf("%s", name);

    for (i=0; i<DATA_MAX; i++)
    {
        if (!strcmp(name, my_data[i].name))
        {
            printf("%sさんの登録情報は\n", name);
            printf("生年月日: %ld\n電話番号: %s\nメールアドレス: %s\n", my_data[i].birth, my_data[i].phone, my_data[i].mail);
            break;
        }
    }
    if (i == DATA_MAX)
        printf("%sさんの名前が見つかりませんでした。",name);
    
    fclose(fp);

    return EXIT_SUCCESS;
}