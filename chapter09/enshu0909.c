#include <stdio.h>

void put_stringr(char s[]) {
    int counter = 0;

    while (s[counter]) {
        counter++;
    }
    counter--; 
    /*
      上のwhileぶんで、counter++を繰り返した結果、s[counter]には'\0'が格納されている。
      counter--することで、のちにs[counter]で値を取得した時に、空文字でない文字が取得できるようになる。
    */

    int i=0,j=0;
    for (i=0; i<=counter; i++){
        while (j < counter-1){
            printf("i:%d , counter:%d , string: %s\n",i,counter,s);
            char tmp = s[j];
            s[j] = s[j+1];
            s[j+1] = tmp;
            j++;        
        }
        j = 0;
        counter--;
    }

    char tmp = s[0];
    s[0] = s[1];
    s[1] = tmp;
}

int main(void){
    char s[7] = "abcdef\n";
    put_stringr(s);
    printf("s : %s\n",s);
}

/*
   全体的に処理が読みにくい。
   forループを抜けた後で、同じ処理を28~30行目で別立てで書いているのも、趣旨や意図が分かりズラく、のちに読む時に分かりにくくなりそう。
*/