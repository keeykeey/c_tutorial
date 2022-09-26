#include <stdio.h>

void put_stringr(char s[]) {
    int counter = 0;

    while (s[counter]) {
        counter++;
    }
    printf("end while %d\n",counter);
    counter--; 
    /*
      上のwhileぶんで、counter++を繰り返した結果、s[counter]には'\0'が格納されている。
      counter--することで、のちにs[counter]で値を取得した時に、空文字でない文字が取得できるようになる。
    */

    int i=0,j=0;
    for (i=0; i<=counter; i++){
        while (j < counter-1 | (counter-1) == 1 ==j){
            /*
                j < counter とすると、文字を前後の文字を入れ替える処理の最後に、ナル文字も入れ替えてしまう。
                その結果、文字数がループごとに少なくなってしまって良くないので、ナル文字を入れ替えないようにcounter-1。

                counterが２になった時は一番左の文字と一番左から２番目の文字を入れ替えたい（処理A）が、j<counter-1
                の式で、 1<2-1 となり、whileの条件が0になるため、処理Aが行われない。
                従って、処理Aが行われるように、特別に(counter-1)==1==jという条件を足した。

                ここは、コメントを書かなくてもコードの意味が分かるようにかけた方がいいかもしれない。
            */
            char tmp = s[j];
            s[j] = s[j+1];
            s[j+1] = tmp;
            j++;        
            printf("i:%d, j:%d , counter:%d , string: %s\n",i,j,counter,s);
        }
        j = 0;
        counter--;
    }
}

int main(void){
    char s[7] = "abcdef\n";
    put_stringr(s);
    printf("s : %s\n",s);
}
