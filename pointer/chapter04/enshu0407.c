#include <stdio.h>

void swap_str(char s1[], char s2[])
{
    printf("before loop\ns1 : %s\ns2 : %s\n",s1,s2);
    int i = 0;
    while (s1[i] || s2[i]) {
        char c = s1[i] ? s1[i] : '\0';
        s1[i] = s2[i] ? s2[i] : '\0';
        s2[i] = c;
        printf("inside loop\ns1 : %s\ns2 : %s\n",s1,s2);
        i++;
        if (i > 10) {
            printf("too much loop\n");
            break;
        }
    }
    printf("after loop\ns1 : %s\ns2 : %s\n",s1,s2);
}

int main(void)
{
    char s1[5] = "ALSK\0";
    char s2[6] = "POIUR\0";
    swap_str(s1,s2);  
    return 0;
}