#include <stdio.h>
#define NUM 5

int main(void) {
    int i ;
    int num = 0;
    char s[NUM][128];

    for (int i=0; i<NUM; i++){
        printf("s[%d] : ",i);
        scanf("%s",s[i]);

        int count_$ = 0;
        for (int j=0; j<5; j++){
            if (s[i][j] == '$') {
                count_$++;
            }
        }
        if (count_$ == 5) {
            printf("killing the process...\n");
            break;
        }else{
            num++;
        }
    }   
   
    for (i=0; i<num; i++) {
        printf("s[%d] = \"%s\"\n",i,s[i]);
    }
   
    return 0;

}