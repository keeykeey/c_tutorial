#include <stdio.h>
#include <time.h>

int sleep(unsigned long x)
{
    clock_t c1 = clock(), c2;
    do {
        if ((c2 = clock()) == (clock_t) -1) {
            return 0;
        }
    } while ( 1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);

    return 1;
}

int count_str_len(const char *s)
{
    int count = 0;
    while(*s++) {
        count++;
    }

    return count;
}

/*
 * direction: 0 -> 左方向, 1 -> 右方向
 * speed: ミリ秒単位
 * n: 繰り返し回数
 */
void telop(const char *s, int direction, int speed, int n)
{
    int str_len = count_str_len(s);
    int index = 0;
    
    while(n--) {
        putchar('\r');
        
        for (int i = 0; i < str_len; i++) {
            putchar(*(s + (index + i) % str_len));
            fflush(stdout);
        }

        if (direction) {
            // 右回り
            if (index) {
                index--;
            } else {
                index = str_len - 1;
            }
        } else {
            // 左回り
            index++;
        }

        sleep(speed);
    }
    putchar('\n');
}

int main(void)
{
    printf("右回り\n");
    telop("Hello World ",1, 500,20);

    sleep(1000);

    printf("左回り\n");
    telop("Hello World ",0, 500,20);
}