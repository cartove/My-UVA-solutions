#include <stdio.h>
#define max(x,y) ((x) > (y) ? (x) : (y))
#define CLEAR(s) memset(&(s), 0, sizeof(s))

int main() {
    unsigned long long y, n1;
    while(scanf("%lld",&y)==1 && y) {
        n1=y+y/9;
        if(y%9==0) {
            printf("%llu %llu\n",n1-1,n1);
            continue;
        }
        printf("%llu\n",n1);
    }
    return 0;
}
