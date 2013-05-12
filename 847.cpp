#include <stdio.h>

int main() {
    long long n,p,i;
    while(scanf("%lld", &n)==1) {
        p = 1,i= 1;
        while (1) {
            if (i % 2) p *= 9;
            else p *= 2;
            if (p >= n) {
                if (i % 2) puts("Stan wins.");
                else puts("Ollie wins.");
                break;
            }
            ++i;
        }
    }
}
