#include <stdio.h>

int str_chnum(const char s[], int ch){
    int i = 0;
    int count_ch=0;
    while (s[i] != '\0'){
        if (s[i] == ch){
            count_ch++;
        }
        i++;
    }
    return count_ch;
}

int main(void) {
    //C : 67
    int ret;
    char s[] = "abCabCabCC\0";

    ret = str_chnum(s,67);
    printf("Cの含まれる個数 : %d\n",ret); //

    return 0;
}