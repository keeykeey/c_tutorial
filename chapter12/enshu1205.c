#include <stdio.h>
#include <math.h>

#define sqr(n) ((n) * (n))
#define ZAHYOU 0
#define KYORI 1

typedef struct {
    double x;
    double y;
}point_t;

typedef struct {
    point_t pt;
    double fuel;
}car_t;

double distance_of(point_t pa, point_t pb){
    return sqrt(sqr(pa.x - pb.x) + sqr(pa.y - pb.y));
}

void put_info(car_t c){
    printf("現在位置 : (%.2f, %.2f)\n", c.pt.x, c.pt.y);
    printf("残り燃料 : %.2fリットル\n",c.fuel);
}

int move_to_dest(car_t *c ,point_t dest){
    double d = distance_of(c->pt, dest);
    if(d > c->fuel){
        return 0;
    }
    c->pt = dest;
    c->fuel -= d;
    return 1;
}

int move_by_dist(car_t *c, double dx, double dy){
    point_t dest = {(c->pt.x) + dx, (c->pt.y)+dy};
    double d = distance_of(c->pt, dest);
    if(d > c->fuel){
        return 0;
    }
    c->pt = dest;
    c->fuel -= d;
    return 1;
}

int select_mode(void){
    int select;
    printf("入力方法を選択してください。\n");
    printf("0 : 目的地の座標入力\n");
    printf("1 : 移動距離入力\n");
    scanf("%d",&select);

    return select;
}

int main(void){
    car_t mycar = {{0.0,0.0},90.0};

    while(1){
        int select;
        point_t dest;
        put_info(mycar);
        
        printf("移動しますか?\n");
        printf("Yes・・・1 / No・・・2\n :");
        scanf("%d",&select);
        if (select != 1)break;

        int mode = select_mode();
        switch (mode){
            case ZAHYOU :
                printf("目的地のX座標 : "); scanf("%lf", &dest.x);
                printf("目的地のY座標 : "); scanf("%lf", &dest.y);
                if (!move_to_dest(&mycar,dest)){
                    puts("\a燃料不足で移動できません。\n");
                }
            case KYORI :
                double dx,dy;
                printf("X座標上の移動距離 : "); scanf("%lf", &dx);
                printf("Y座標上の移動距離 : "); scanf("%lf", &dy);
                if (!move_by_dist(&mycar,dx,dy)){
                    puts("\a燃料不足で移動できません。\n");
                }
        }

    }
    
    return 0;
    
}

/*
  undefined reference to `sqrt'とエラーが出る場合は、以下のようにコンパイルする。
  gcc -o enshu1205.out enshu1205.c -lm
*/