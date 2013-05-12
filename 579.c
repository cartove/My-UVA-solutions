#include <stdio.h>
#include <stdlib.h>
int main() {
    int h,m;
    register double hd,md,d;
    while(scanf("%d:%d",&h,&m)==2) {
    	if(h==0 && m==0) break;
        md=m/2.0;
        hd=h*30.0+md;
        md*=12.0;
        d=hd-md;
        if(d<0)d=-d;
        if(d>180) d=360-d;
        printf("%.3f\n",d);
    }
    return 0;
}

