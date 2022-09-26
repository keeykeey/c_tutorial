#include <stdio.h>
#include <string.h>

void use_strlen(){
    char s[] = "String";
    int len = strlen(s);
    printf("strlen(String) : %sは%d文字です。\n",s,len);
}

void use_strcpy(){
    char s1[] = "pineapple";
    char s2[] = "apple";

    strcpy(s1,s2);
    printf("strcpy(pineapple,apple) : %s\n",s1);
}

void use_strncpy(){
    char s1[] = "AAAAA";
    char s2[] = "hippopotamus";
    char s3[] = "dog";

    strncpy(s1,s2,4);
    printf("strncpy(AAAAA,hippopotamus,5) : %s\n",s1);

    strncpy(s1,s3,4);
    printf("strncpy(AAAAAs,dog,5) : %s\n",s1);
}

void use_strcat(){
    char s1[] = "do";
    char s2[] = "g";

    strcat(s1,s2);
    printf("starcat(do,g) : %s\n",s1);
}

void use_strncat(){
    char s1[] = "am";
    char s2[] = "ricaAAA";
    strncat(s1,s2,4);
    printf("strncat(am,rica!!!) : %s\n",s1);
}

void use_strcmp(){
    char s1[] = "house";
    char s2[] = "house";
    char s3[] = "h0use";

    printf("strcmp(house,house) : %d\n",strcmp(s1,s2));
    printf("strcmp(house,h0use) : %d\n",strcmp(s1,s3));
}

void use_strncmp(){
    char s1[] = "house";
    char s2[] = "house";
    char s3[] = "houze";

    printf("strncmp(house,house,5) : %d\n",strncmp(s1,s2,5));
    printf("strncmp(house,houze,5) : %d\n",strncmp(s1,s3,5));
    printf("strncmp(house,houze,3) : %d\n",strncmp(s1,s3,3));
}

int main(void){
    use_strlen();
    use_strcpy();
    use_strncpy();
    use_strcat();
    use_strncat();
    use_strcmp();
    use_strncmp();

    return 0;
}