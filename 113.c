#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>

#define max(x,y) ((x) > (y) ? (x) : (y))
#define min(x,y) ((x) < (y) ? (x) : (y))
#define CLEAR(s) memset(&(s), 0, sizeof(s))

int main() {
    double base;
    long double  n;
    while(scanf("%lf\n%llf",&base,&n)==2) {
    printf("%.0lf\n", pow(n , 1.0/base));
    }
    return 0;
}
