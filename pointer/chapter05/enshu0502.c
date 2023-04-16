#include <stdio.h>

int main(int argc, char **argv)
{
    int i = 1;
    *argv += 1;
    while (i < argc) {
        printf("arg[%d] : %s\n",i++,*argv++);
    }
    return 0;
}