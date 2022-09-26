#include <stdio.h>

enum word_kind {aaa, bbb, ccc, invalid};

enum word_kind get_word(void) {
    int word;
    do {
        printf(" 0:aaa , 1:bbb, 2:ccc 3:you want stop this program ...");scanf("%d",&word);
    } while (word > invalid || word<aaa);
    return word;
}

int main(void) {
    enum word_kind word;
    do{
        switch (word = get_word()) {
            case 0 : printf("aaa\n"); break;
            case 1 : printf("bbb\n"); break; 
            case 2 : printf("ccc\n"); break;
            case 3 : printf("stopping this program...\n"); break;
        }   
    } while (word != invalid);
    return 0;
}