#include <stdio.h>
#include <stdlib.h>

int main() {
    int x1,y1,x2,y2,x,y;
    while(1) {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        if(x1==0) break;
        if(x1==x2 && y1==y2) {
            puts("0");
            continue;
        }
        if(x1==x2 ||y1==y2) {
            puts("1");
            continue;
        }
        x=abs(x1-x2);
        y=abs(y1-y2);
        if(x==y) {
            if(x!=0&&y!=0) puts("1");
        } else  puts("2");
    }
    return 0;
}


