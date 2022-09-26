#include <stdio.h>

int get_str_length(char s[]) {
    int i = 0;
    while (s[i++]) {
        ;
    }
    return i;
}

void side_change(char s[], int num) {
    char tmp = s[num];
    s[num] = s[num+1];
    s[num+1] = tmp;
    //printf("1:%d, 2:%d\n",s[num],s[num+1]);
}

void del_digit(char s[]) {
    /*
      処理１ sを反転する
    */
    int len = get_str_length(s);
    while (len-1){
        int j = 0;
        for (j=0; j<len-2; j++){
            if (s[j]>='0' && s[j]<='9') 
                side_change(s,j);
        }
        len--;
    }

    /*
      処理２　sから数字を削除する
    */
    int len2 = get_str_length(s);
    int num;
    for (int k=0; k<len2-1;k++){
        if (s[k] >= '0' && s[k]<='9'){
            num = k;
            break;
        }
    }
    for (int k=len2; k>num; k--) {
        char tmp = '\0';//s[k];
        s[k] = s[k-1];
        s[k-1] = tmp;
    }
}


int main(void) {
    char s[] = "A12CD3EF";
    int len = get_str_length(s);

    del_digit(s);

    printf("A12CD3EF CHANGES TO %s\n",s);

    return 0;
}