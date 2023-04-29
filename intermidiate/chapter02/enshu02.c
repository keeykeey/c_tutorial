#include <stdio.h>
#include <time.h>

int sleep(unsigned long x)
{
    clock_t c1 = clock(), c2;

    do {
        if ((c2 = clock()) == (clock_t) -1) {
            return 0;
        }
    } while ( 1000.0 * (c2 - c1)/CLOCKS_PER_SEC < x);

    return 1;
}

int gput(const char *s, int speed)
{
    while(*s) {
        putchar(*s++);
        fflush(stdout);
        sleep(speed);
    }
    putchar('\n');

    return 0;
}

int main(void)
{
    gput("ABCDEFG",1000);

    return 0;
}