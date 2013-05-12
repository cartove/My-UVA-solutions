#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main () {
    int testCase,cases = 0,n,x,i,sn;
    scanf ("%d", &testCase);
    while ( testCase-- ) {
        scanf ("%d", &n);
        sn=sqrt(n);
        printf("Case %d:",++cases);
        for (i =sn; i >= 1; --i) {
            x = n - (i * i);
            if ( x % i == 0 && x > 0 )
                printf(" %d",x);
        }
        printf ("\n");
    }

    return 0;
}
