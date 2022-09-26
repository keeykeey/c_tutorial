#include <stdio.h>

int main(void) {
    int i,n;
    char a[][5] = {"LISP", "C", "ADAM"};
    char *p[] = {"LISP","C","ADAM"};

    n = sizeof(a)/5;

    for (i=0; i<n; i++){
        printf("a[%d] = \"%s\"\n",i,a[i]);
    } 

    for (i=0; i<n; i++){
        printf("p[%d] = \"%s\"\n",i,p[i]);
    }

    return 0;
}