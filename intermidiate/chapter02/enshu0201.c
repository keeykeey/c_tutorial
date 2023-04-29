#include <stdio.h>
#include <time.h>

int sleep(unsigned long x)
{
    clock_t c1 = clock(), c2;
    do {
        if ((c2 = clock()) == (clock_t) -1) {
            return 0;
        }
    } while (1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);
    return 1;
}

int main(void)
{
    for (int i = 0; i< 10; i++) {
        printf("counting... : %d\n",i);
        fflush(stdout);
        sleep(1000);
    }
    clock_t c = clock();
    printf("プログラムの実行に要した時間 : %f\n", (double) c / CLOCKS_PER_SEC);
    printf("プログラムの実行に要したクロック数 : %lu\n", c);

    return 0;
}