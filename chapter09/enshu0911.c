#include <stdio.h>
#include <string.h>

#define NUMBER 5
#define STR_LENGTH 128 
#define STOP_WORD "$$$$$"

int get_string(char s[5][128]) {
    int i=0;
    while (i<5) {
        printf("%d個目の文字を入力してください。",i+1);
        scanf("%s",s[i]);
        if (strcmp(s[i],STOP_WORD)==0)
            break;
        i++;
    }
    return i;
}

void main(void){
    char s[5][128];
    int n = get_string(s);
    
    for (int i=0; i<n; i++){
        printf("%d個目に入力した値 : %s\n",i+1,s[i]);
    }
}