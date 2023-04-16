#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int i = 0;
    char c;
    float sum;
    while (argc-- > 1) {
        printf("argv[%d]: %f\n", ++i, atof(*++argv));
        sum += atof(*argv);
    }
    printf("sum: %.6f\n",sum);
    return 0;
}