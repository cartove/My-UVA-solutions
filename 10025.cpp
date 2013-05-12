#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cctype>

#define max(x,y) ((x) > (y) ? (x) : (y))
#define min(x,y) ((x) < (y) ? (x) : (y))
#define CLEAR(s) memset(&(s), 0, sizeof(s))

int main() {
    int cases;
    scanf("%d",&cases);
    while(cases--) {
        long long k;
        scanf("%lld",&k);
        if(k==0){
            puts("3");
            if(cases!=0)printf("\n");
            continue;
        }
        k=abs(k);
        long i=((-1 + sqrtl(1+8*k)) / 2),j=i*(i+1)/2;
        if (j== k) {
            printf("%ld\n",i);
            if(cases!=0)printf("\n");
        } else {
            for(;; ++i) {
                j=i*(i+1)/2;
                if (j < k) continue;
                if((j-k)%2==0) {
                    printf("%ld\n",i);
                    if(cases!=0)printf("\n");
                    break;
                }
            }
        }
    }
    return 0;
}
