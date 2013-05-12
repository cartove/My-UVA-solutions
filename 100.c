#include <stdio.h>

int threensandone(int m) {
    int i = 1;
    while (m != 1) {
        if (m % 2 == 0)
            m = m/2;
        else
            m = 3*m+1;
        i++;
    }
    return i;
}
int main() {
    int m,n,max,x,m0,n0,i;
    while (scanf("%d %d\n",&m,&n)==2) {
        m0 = m;
        n0 = n;
        if (m > n) {
            x = m;
            m = n;
            n = x;
        }
        max = threensandone(m);
        for(i=m+1; i<=n; i++) {
            x = threensandone(i);
            if (x > max)
                max = x;
        }
        printf("%d %d %d\n",m0,n0,max);
    }
    return 0;
}
