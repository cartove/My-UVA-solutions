#include<cstdio>
#include <stdlib.h>
#define MAX 20000
int compare (const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}
int main() {
    int cases,n,price[MAX],i,discount;
    scanf("%d",&cases);
    while(cases--) {
        scanf("%d",&n);
        for(i=0; i<n; i++)
            scanf("%d",&price[i]);
        qsort (price, n, sizeof(int), compare);
        discount=0;
        for(i=n-3; i>=0; i-=3) discount+=price[i];
        printf("%d\n",discount);
    }
    return 0;
}
