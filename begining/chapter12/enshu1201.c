#include <stdio.h>

#define NAME_LEN 64

struct student {
    char name [NAME_LEN];
    int height;
    float weight;
    long schols;
};

int main(void){
    struct student takao = {"Takao",173,86.2,0};

    printf("name : %p\n",&takao.name);
    printf("height : %p\n",&takao.height);
    printf("weight : %p\n",&takao.weight);
    printf("schols : %p\n",&takao.schols);
}