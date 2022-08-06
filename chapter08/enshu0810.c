#include <stdio.h>

int count_values_and_ret_maxval(int arr[]){
    int ch;

    printf("数字を入力してください。入力後は「Enter」の後「ctrl」+「D」を押してください。\n : ");

    int max = 0;
    while((ch=getchar()) != EOF) {
        if (ch>='0' && ch<= '9') {
            arr[ch-'0']++;
            max = max>arr[ch-'0'] ? max : arr[ch-'0'] ;
        }
    }

    return max;
} 

int draw_graph(int arr[],int len_arr,int maxval) {
    for (int i = maxval; i>0; i--){
        for (int j = 0; j<len_arr; j++){
            switch (arr[j] < i){
                case 0 : printf(" * "); break;
                default : printf("   "); break;
            }
        }
        putchar('\n');
    }
    for (int k=0; k<10; k++) {
        printf("---");
    }
    putchar('\n');

    for (int l=0; l<10; l++) {
        printf(" %d ",l);
    }
    putchar('\n');
}

int main(void) {
    int counter[10] = {0};
    int maxval = count_values_and_ret_maxval(counter);

    printf("max value %d\n",maxval);

    draw_graph(counter,10,maxval);
}
