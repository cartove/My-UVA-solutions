#include <stdio.h>
#ifndef min
#define min(x,y) ((x) < (y) ? (x) : (y))
#endif
#ifndef max
#define max(x,y) ((x) > (y) ? (x) : (y))
#endif

int main() {
    int cases,line,temp, maxi,rcases=0;
    scanf("%d",&cases);
    while(cases--){
        scanf("%d",&line);
        maxi = 0;
        while(line--) {
            scanf("%d",&temp);
            maxi = max(maxi,temp);
        }
        printf("Case %d: %d\n",++rcases,maxi);
    }
    return 0;
}

