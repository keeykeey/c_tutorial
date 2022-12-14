#include <stdio.h>
#define STR_LENGTH 128

int get_str_length(char s[]) {
    int i=0;
    while(s[i++]){
        ;
    }
    return i;
}

void swap_strs(char s[],int n){
    char tmp = s[n];
    s[n] = s[n+1];
    s[n+1] = tmp;
}

void rev_string(char s[][STR_LENGTH],int n){
    for (int i=0; i<n; i++) {
        int len = get_str_length(s[i]);
        while(len-1){
            int j=0;
            for (j=0;j<len-2;j++){
                swap_strs(s[i],j);
            }
            len--;
        }
    }
}

int main(void){    
    char s[][STR_LENGTH] = {"abc","123","12345"};
    rev_string(s,3);
    for (int i=0; i<3; i++) {
        printf("s[%d]: %s\n",i,s[i]);
    }
    return 0;   
}