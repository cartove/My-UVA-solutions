#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int values[2000000]= {0};

int compare (const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}

int main () {
    long n,i;
    while(1) {
        scanf("%ld",&n);
        if(n==0)break;
        for(i=0; i<n; ++i) scanf("%d",&values[i]);
        qsort (values, n, sizeof(int), compare);
        for (i=0; i<n; ++i) {
            printf ("%d",values[i]);
            if(i!=n-1) printf(" ");
        }
        printf("\n");
        memset(values, 0, sizeof values);

    }
    return 0;
}
