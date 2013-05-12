#include <stdio.h>
int main() {
    int h,u,d,f,day,sum;
    while(1) {
        scanf("%d%d%d%d",&h,&u,&d,&f);
        if(h==0) break;
        f*=u;
        h*=100;
        u*=100;
        d*=100;
        sum=day=0;
        while(1) {
            if(u>=0) sum+=u;
            ++day;
            if(sum>h) {
                printf("success on day %d\n",day);
                break;
            }
            sum-=d;
            if(sum<0) {
                printf("failure on day %d\n",day);
                break;
            }
            u-=f;
        }
    }
    return 0;
}

