#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int x,y,z;
    int cases,k=1;
    scanf("%d",&cases);
    while(cases--) {
        scanf("%d%d",&x,&y);
        if(x%2==0) x++;
        if(y%2 ==0) y--;
        if(x==1)
            z=pow(((y+x)/2),2);
        else
            z=pow(((y+1)/2),2)-pow(((x-1)/2),2);
            printf("Case %d: %d\n",k++,z);
    }
    return 0;
}
