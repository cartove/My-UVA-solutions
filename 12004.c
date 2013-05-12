#include <stdio.h>

long long  num, den;

long long gcd(long long c, long long d) {
    long long u, v, s;
    u = __builtin_ctz(c);
    v = __builtin_ctz(d);
    s = (u < v) ? u : v;
    u = c >> u;
    v = d >> v;
    while (u != v)
        if (u > v) {
            u -= v;
            u >>= __builtin_ctz(u);
        } else {
            v -= u;
            v >>= __builtin_ctz(v);
        }
    return u << s;
}

void solver() {
    int g = gcd(num, den);
    num /= g;
    den /= g;
    if(den != 1) printf("%lld/%lld", num, den);
        else printf("%lld", num);
    fwrite("\n",1,1,stdout);
}

int main() {
    long long n;
    register int count =0;
    int cases=0;
    scanf("%d",&cases);
    while(cases--) {
        scanf("%lld",&n);
        fwrite("Case ",1,5,stdout);
        printf("%d",++count);
        fwrite(": ",1,2,stdout);
        if(n==1)  fwrite("0\n",1,2,stdout);
        else {
            num =n*(n - 1);
            den= 4;
            solver();
        }
    }
    return 0;
}
