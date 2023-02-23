#include <stdio.h>

int main(void) {
    char s[4] = {'\0','A','B','C'};
    char s2[4] = {'A','B','C','\0'};
    printf("s : %s\n",s);
    printf("s2: %s\n",s2);

    return 0;
}