#include <stdio.h>

void put_stringr(const char s[]) {
    int counter = 0;

    while (s[counter]) {
        counter++;
    }
    counter--; 
    /*
      上のwhileぶんで、counter++を繰り返した結果、s[counter]には'\0'が格納されている。
      counter--することで、のちにs[counter]で値を取得した時に、空文字でない文字が取得できるようになる。
    */

    char s2[counter];
    for (int i=counter; i>=0; i--){
        s2[counter-i] = s[i];  
    }

    printf("s2 : %s",s2);
}

int main(void){
    char s[7] = "asdfg\n";
    put_stringr(s);
}