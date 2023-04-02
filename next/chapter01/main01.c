#include <stdio.h>
#include <stdbool.h>

int get_number() {
    int d;
    printf("数値を入力してください。");
    scanf("%d", &d);

    return d;
}

bool is_prime_number(int d) {
    int d2 = d - 1;
    while(d%d2) {
       d2--; 
       if (d2==1) {
         return true;
       }
    }
    return false;
}

int main(void) {
    int d = get_number();
    bool b = is_prime_number(d);
    if (b) {
      printf("%dは素数です。\n",d);
    } else {
      printf("%dは素数ではありません。\n",d);
    }

    return 0;
}