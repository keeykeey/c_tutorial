#include <stdio.h>

int main(void) {
    //1
    char str[]="";
    printf("Intend to be ""\n : %s\nbyte\n : %lu\n",str,sizeof(str));

    //2
    char s[] = "ABC";
    printf("Intend to be ABC\n : %s\nbyte\n : %lu\n",s,sizeof(s));
    
    //3
    s[0] = '\0';
    printf("Intend to be ABC\n : %s\nbyte\n : %lu\n",s,sizeof(s));    
    
    return 0;

}

/*
    //2 -> //3にかけて、表示される文字はABCから''になったが、バイト数を１に変更出来ていない点は要修正。
*/