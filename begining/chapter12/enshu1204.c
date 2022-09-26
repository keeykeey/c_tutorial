#include <stdio.h>
#include <string.h>

#define NAME_LEN 64
#define LIST_LEN 10

typedef struct student {
    char name[NAME_LEN];
    int id;
    long schols;
    float weight;
    double height;
} student_t;

student_t ret_student_t(student_t student) {
    printf("生徒の情報を入力してください。\n");
    printf("name : "); scanf("%s",student.name);
    printf("id : "); scanf("%d",&student.id);
    printf("schols : "); scanf("%ld",&student.schols);
    printf("weight : "); scanf("%f",&student.weight);
    printf("height : "); scanf("%lf",&student.height);

    return student;
}

void test_ret_student_t(void){
    printf("test_ret_student_t------------------\n");
    student_t student;
    student = ret_student_t(student);
    printf("student.name : %s\n",student.name);
    printf("student.id : %d\n",student.id);
    printf("student.schols : %ld\n",student.schols);
    printf("student.weight : %.2f\n",student.weight);
    printf("student.height : %.2lf\n",student.height);
}

int make_student_list(student_t student_list[]){
    int list_len;
    do{
        printf("何人の生徒リストを作りますか？0~100人の範囲で入力してください。: "); 
        scanf("%d",&list_len);
        if (list_len>LIST_LEN || list_len<0){
            printf("入力できない値です。\n");
        }
    } while (list_len > LIST_LEN || list_len <0);

    for (int i=0; i<list_len; i++){
        student_t tmp;
        tmp = ret_student_t(tmp);
        student_list[i] = tmp;
    }
    return list_len;
}

void test_make_student_list(student_t student_list[]){
    printf("test_make_student_list-----------------\n");
    int list_len = make_student_list(student_list);
    for (int i=0; i<list_len; i++){
        printf("氏名 : %-8s, ID : %-5d, 奨学金 : $%8ld, 体重 : %8.2fkg, 身長 : %8.2lfcm\n",
            student_list[i].name,student_list[i].id,student_list[i].schols,
            student_list[i].weight,student_list[i].height);
    }
}

void swap_student(student_t *s1,student_t *s2){
    student_t tmp = *s1;
    *s1 = *s2;
    *s2 = tmp;
}

void test_swap_student(){
    printf("test_swap_student_list-----------------\n");
    student_t s1 = {"test",1,100,60,160};
    student_t s2 = {"test2",2,200,70,170};
    
    printf("Before swap\n");
    printf(" s1.name : %s\n",s1.name);
    printf(" s1.id : %d\n",s1.id);
    printf(" s1.schols : %ld\n",s1.schols);
    printf(" s1.weight : %.2f\n",s1.weight);
    printf(" s1.height : %.2lf\n",s1.height);
    printf(" s2.name : %s\n",s2.name);
    printf(" s2.id : %d\n",s2.id);
    printf(" s2.schols : %ld\n",s2.schols);
    printf(" s2.weight : %.2f\n",s2.weight);
    printf(" s2.height : %.2lf\n",s2.height);

    swap_student(&s1,&s2);

    printf("After swap\n");
    printf(" s1.name : %s\n",s1.name);
    printf(" s1.id : %d\n",s1.id);
    printf(" s1.schols : %ld\n",s1.schols);
    printf(" s1.weight : %.2f\n",s1.weight);
    printf(" s1.height : %.2lf\n",s1.height);
    printf(" s2.name : %s\n",s2.name);
    printf(" s2.id : %d\n",s2.id);
    printf(" s2.schols : %ld\n",s2.schols);
    printf(" s2.weight : %.2f\n",s2.weight);
    printf(" s2.height : %.2lf\n",s2.height);
}


int main(void){
   /* TEST  
    student_t test_student_list[LIST_LEN];
    test_ret_student_t();
    test_make_student_list(test_student_list);
    test_swap_student();
   */
   
    student_t student_list[LIST_LEN];
    int list_len = make_student_list(student_list);

    int mode = 3;
    printf("名前又は身長で大きい順にソートしますか？\n");
    printf("1  名前でソートする\n");
    printf("2  身長でソートする\n");
    printf("3  ソートしない\n : ");
    scanf("%d",&mode);

    for (int i=0; i<list_len-1;i++){
        switch (mode) {
            case 1 :
                if (student_list[i].name < student_list[i+1].name){
                    swap_student(&student_list[i], &student_list[i+1]);
                };break;
            case 2 :
                if (student_list[i].height < student_list[i+1].height){
                    swap_student(&student_list[i], &student_list[i+1]);
                };break;             
            case 3 :
                ;break;
            default :
                ;break;
        }
    }

    for (int i=0; i<list_len;i++){
        printf("student.name : %s\n",student_list[i].name);
        printf("student.id : %d\n",student_list[i].id);
        printf("student.schols : %ld\n",student_list[i].schols);
        printf("student.weight : %.2f\n",student_list[i].weight);
        printf("student.height : %.2lf\n",student_list[i].height);
    }

    return 0;
    
}