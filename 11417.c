#include <stdio.h>
#include <stdlib.h>
int gcd ( int a, int b ) {
    int c;
    while ( a != 0 ) {
        c = a;
        a = b%a;
        b = c;
    }
    return b;
}
int main() {
    int g,n,i,j;
    while(1) {
        g=0;
        scanf("%d",&n);
        if(n==0) break;
        for(i=1; i<n; i++)
            for(j=i+1; j<=n; j++)
                g+=gcd(i,j);
        printf("%d\n",g);
    }
    return 0;
}
