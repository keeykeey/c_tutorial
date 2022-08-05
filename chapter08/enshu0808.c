#include <stdio.h>

int max(int dx,int dy) {
    return ((dx >= dy) ? dx : dy);
}

int min(int dx,int dy) {
    return ((dx>=dy) ? dy : dx);
}

int get_diff(int longer,int shorter) {
    int diff = longer;
    while (diff > shorter) {
        diff = diff - shorter; 
    }
    return diff;
}

int gcd(int x, int y) {
    int longer = max(x,y);
    int shorter = min(x,y);

    while(longer != shorter){
        int tmp = longer;
        longer = shorter;
        shorter = get_diff(tmp,shorter);
    }

    return shorter;//最大公約数    
}

int main(void) {
    int dx,dy;
    printf("一つ目の長さを入力 : "); scanf("%d",&dx);
    printf("二つ目の長さを入力 : "); scanf("%d",&dy);
    int ret = gcd(dx,dy);
    printf("main function :%d\n",ret);
}


