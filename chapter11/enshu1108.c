#include <stdio.h>
#include <string.h>

void swap(char *s1,char *s2){
    char tmp = *s1;
    *s1 = *s2;
    *s2 = tmp; 
}

void del_digit(char *str){
    int len = strlen(str);//仕様上ナル文字はカウントされていない。
    while(len){
        for (int i=0;i<len;i++){
            if (*str >= '0' && *str<='9' ){
                swap(str,(str+1));
            }
            str++;
        }
        str = str - len;
        len--;       
    }
}

void test(){
    char s1[] = "abc";
    char s2[] = "ABC";
    swap(s1,s2);
    printf("%s\n",s1); //Abc
    printf("%s\n",s2); //aBC
}

int main(void){
    char s1[] = "ab1c2";
    char s2[] = "1AB2AB3";

    del_digit(s1);
    del_digit(s2);
    printf("s1 : %s\n",s1);
    printf("s2 : %s\n",s2);

    return 0;
}