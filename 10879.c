#include <string.h>
#include <stdio.h>
#include <math.h>
int main() {
    int cases , i , flag , steps=0;
    unsigned long long factor;
    scanf("%d\n",&cases);
    while(cases--) {
        flag=0;
        ++steps;
        scanf("%llu",&factor);
        printf("Case #%d: %llu = ",steps,factor);
        for(i=2; i<=sqrt(factor); ++i)
            if(factor%i==0) {
                printf("%d * %llu",i,factor/i);
                ++flag;
                if(flag==1)printf(" = ");
                if(flag==2) break;
            }
        printf("\n");

    }
    return 0;
}
