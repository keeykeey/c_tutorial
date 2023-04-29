#include <stdio.h>
#include <time.h>

int sleep(unsigned long x)
{
    clock_t c1 = clock(), c2;

    do {
        if ((c2 = clock()) == (clock_t)-1) {
            return 0;
        }
    } while (1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);

    return 1;
}

void bput(const char *s, int d, int e, int n)
{
    while(n--){
        int len = 0;
        while (*s) {
            putchar(*s++);
            fflush(stdout);
            len++;
        }
        sleep(d);

        while(len--) {
            printf("\b \b");
            fflush(stdout);
            s--;
        }
        sleep(e);
    }
}

int main(void)
{
    bput("ABCDE",1000,1000,7);
    return 0;
}