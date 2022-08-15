#include <stdio.h>

int strtoi(const char *nptr){
    /*
     * nptrが指す文字列を、int型の表現に変換する。
     * 返却された値を返す。結果の値がint型で表現できない時の動作は定義されない。
     */
    int ret=0;
    while(*nptr){
        int tmp;
        tmp = *nptr - '0';
        ret = ret*10 + tmp;
        nptr++;
    }

    return ret; 
}

long strtol(const char *nptr){
    /*
     * nptrが指す文字列を、long型の表現に変換する。
     * 返却された値を返す。結果の値がlong型で表現できない時の動作は定義されない。
     */
    long ret=0;
    while(*nptr){
        long tmp;
        tmp = *nptr - '0';
        ret = ret*10 + tmp;
        nptr++;
    }

    return ret; 
}

double strtof(const char *nptr){
    /*
     * nptrが指す文字列を、double型の表現に変換する。
     * 返却された値を返す。結果の値がdouble型で表現できない時の動作は定義されない。
     */
    double ret=0;
    double integer = 0;
    double decimal = 0;
    
    while((*nptr != '.') && (*nptr != '\0')){
        double tmp_i; //tmp_integer
        tmp_i = *nptr - '0';
        integer = integer*10 + tmp_i;
        nptr++;
    }

    int denominator = 1; //分母
    while(*nptr){
        if (*nptr == '.'){
            nptr++;
            continue;
        }
        double tmp_d; //temp_decimal : 小数
        tmp_d = *nptr -'0';
        decimal = decimal*10 + tmp_d;
        denominator *= 10;
        nptr++;                
    }
    decimal /= denominator;

    ret = integer + decimal;

    return ret;     
}

int test_strtoi(){
    char s[] = "123";
    int num = strtoi(s);
    printf("test_strtoi(123)    : %d\n",num);
    printf("test_strtoi(123) - 1: %d\n",num-1);

    if (num==123 && (num-1)==122){
        return 0;
    }else{
        return 1;
    }
}

int test_strtol(){
    char s[] = "123456";
    long num = strtoi(s);
    printf("test_strtoi(123)    : %ld\n",num);
    printf("test_strtoi(123) - 1: %ld\n",num-1);

    if (num==123456 && (num-1)==123455){
        return 0;
    }else{
        return 1;
    }
}

int test_strtof(){
    char s[] = "12.34";
    double num = strtof(s);
    printf("test_strtoi(12.34)    : %f\n",num);
    printf("test_strtoi(12.34) - 1: %f\n",num-0.1);

    if (num==12.34 && (num-0.1)==12.24){
        return 0;
    }else{
        return 1;
    }
}

int main(void){
    int ng=0;
    int sum=0;

    ng += test_strtoi(); sum++;
    ng += test_strtol(); sum++;
    ng += test_strtof(); sum++;

    printf("Result of the Test\n NG : %d\n Number of the test case : %d\n",ng,sum);

    return 0;
}
