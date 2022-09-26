#include <stdio.h>
#include <string.h>
#define NAME_LEN 128
#define ARY_LEN 10

typedef struct person {
    char name[NAME_LEN];
    double height;
    double weight;
} person_t;

void swap(person_t *p1, person_t *p2){
    person_t tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

int main(void){
    FILE *fp;
    int ninzu=0;
    char name[NAME_LEN];
    double height, weight;
    double hsum = 0.0;
    double wsum = 0.0;

    person_t person[ARY_LEN];

    if ((fp = fopen("hw.dat","r"))==NULL){
        printf("\aファイルをオープン出来ません。\n");
    }else{
        while (fscanf(fp, "%s%lf%lf", name, &height, &weight) == 3){
            strcpy(person[ninzu].name, name);
            person[ninzu].height = height;
            person[ninzu].weight = weight;

            ninzu ++;
            hsum += height;
            wsum += weight;
            
        }
        fclose(fp);
    }
    
    int count = ninzu;//6
    while(count){
        for (int i=ninzu; i>0; i--){
            if(person[i-1].height < person[i].height){
                swap(&person[i-1],&person[i]);
            }
        }
        count--;
    }

    for (int i=0; i<ninzu; i++){
        printf("%-10s %5.1f %5.1f\n",person[i].name, person[i].height, person[i].weight);      
    }
    printf("----------------------\n");
    printf("平均       %5.1f %5.1f\n",hsum/ninzu, wsum/ninzu);
 
    return 0;
}

