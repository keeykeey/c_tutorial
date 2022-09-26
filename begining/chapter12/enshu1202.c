#include <stdio.h>

#define NAME_LEN 64

typedef struct student {
    char name[NAME_LEN];
    int height;
    float weight;
    long schols;
} Student;

int main(void){
    Student sanaka;
    printf("name ? : "); scanf("%s",sanaka.name);
    printf("height ? : "); scanf("%d",&sanaka.height);
    printf("weight ? : "); scanf("%f",&sanaka.weight);
    printf("schols ? : "); scanf("%ld",&sanaka.schols);

    printf("------------\n");

    printf("name : %s\n",sanaka.name);
    printf("height : %d\n",sanaka.height);
    printf("weght : %.2f\n",sanaka.weight);
    printf("schols :%ld\n",sanaka.schols);

    return 0;
}