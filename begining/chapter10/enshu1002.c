#include <stdio.h>
#define NOT_LEAP_YEAR 0
#define LEAP_YEAR 1
#define M_DECREMENTED 1
#define M_INCREMENTED 1

int is_leap_year(int y){
    /*
      西暦を4で割って余りが0になれば、その年は閏年.
    */   
    if (y%4 == 0){
        printf("this is leap year\n");
        return LEAP_YEAR;
    }else{
        return NOT_LEAP_YEAR;
    }
}

int day_backword(int *d1, int d2){
    /*
     * d1 : デクリメントしたい日の日付
     * d2 : デクリメントしたい日の前の月のカレンダー上の最終日
     * ex) 2000/4/1をデクリメントしたい場合、d1は1、d2は31（3月は31日で終わるから）
     */
    if(*d1-1 == 0){
        *d1 = d2;
        return M_DECREMENTED;
    }else if(*d1-1 > 0){
        *d1 = *d1-1;
        return 0;
    }  
}

int month_backword(int m){
    int ret = (m-1==0 ? 12 : m-1);
    return ret;
}

void decrement_date(int *y, int *m, int *d){
    printf("DECREMENT\n");

    int leap_year = is_leap_year(*y);
    int m_decremented = 0;
    switch (*m) {
        case 1 : m_decremented = day_backword(d,31);break;
        case 2 : m_decremented = day_backword(d,31);break;
        case 3 : m_decremented = day_backword(d,28+leap_year);break;
        case 4 : m_decremented = day_backword(d,31);break;
        case 5 : m_decremented = day_backword(d,30);break;
        case 6 : m_decremented = day_backword(d,31);break;
        case 7 : m_decremented = day_backword(d,30);break;
        case 8 : m_decremented = day_backword(d,31);break;
        case 9 : m_decremented = day_backword(d,31);break;
        case 10 : m_decremented = day_backword(d,30);break;
        case 11 : m_decremented = day_backword(d,31);break;
        case 12 : m_decremented = day_backword(d,30);break;
        default : printf("day_backword_error\n"); break;
    }

    if (m_decremented){
        *m = month_backword(*m);
    }

    if (m_decremented && *m==12){
        *y = *y-1;
    }
}

int day_forword(int *d1,int d2){
    /*
     *31日の日から1日足したら32日になるが、それを31で割った時のあまり1が正しい日付となる。また、
     *16日の日から1日足したら17日になるが、それを31で割った時のあまり17が正しい日付となる。
     */
    if((*d1+1) > d2){
        *d1 = (*d1+1)%d2;
        return M_INCREMENTED;
    }else if(*d1+1 <= d2){
        *d1 = *d1 +1;
        return 0;
    }
}

int month_forword(int m){
    int ret = (m+1==12 ? m+1 : (m+1) % 12);
    return ret;
}

void increment_date(int *y, int *m, int *d){
    printf("ICREMENT\n");
    int leap_year = is_leap_year(*y);
    int m_incremented = 0;

    switch (*m) {
        case 1 : m_incremented = day_forword(d,31);break;
        case 2 : m_incremented = day_forword(d,28+leap_year);break;
        case 3 : m_incremented = day_forword(d,31);break;
        case 4 : m_incremented = day_forword(d,30);break;
        case 5 : m_incremented = day_forword(d,31);break;
        case 6 : m_incremented = day_forword(d,30);break;
        case 7 : m_incremented = day_forword(d,31);break;
        case 8 : m_incremented = day_forword(d,31);break;
        case 9 : m_incremented = day_forword(d,30);break;
        case 10 : m_incremented = day_forword(d,31);break;
        case 11 : m_incremented = day_forword(d,30);break;
        case 12 : m_incremented = day_forword(d,31);break;
        default : printf("day_forword_error\n"); break;
    }

    if (m_incremented){
        *m = month_forword(*m);
    }

    if (m_incremented && *m == 1){
        *y = *y+1;
    }
}

int main(void){
    int y, m, d, which;
    printf("年を入力してください : "); scanf("%d",&y);
    printf("月を入力してください : "); scanf("%d",&m);
    printf("日を入力してください : "); scanf("%d",&d);
    printf("以下を入力してください\nDecrementする場合 : 0\nIncrementする場合 : 1\n : ");scanf("%d",&which);

    switch (which) {
        case 0:{
            decrement_date(&y,&m,&d);
            printf("Year : %d\n",y);
            printf("Month : %d\n",m);
            printf("Day : %d\n",d);            
        };break;
        
        case 1:{
            increment_date(&y,&m,&d);
            printf("Year : %d\n",y);
            printf("Month : %d\n",m);
            printf("Day : %d\n",d);            
        };break;
        default:printf("入力が不正です。\n");break;
    }
    return 0;
}
