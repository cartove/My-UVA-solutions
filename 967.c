#include <stdio.h>


int main() {
    int myints[] = {113, 131, 197, 199, 311, 337, 373, 719, 733, 919, 971, 991, 1193, 1931, 3119, 3779, 7793, 7937, 9311, 9377, 11939, 19391, 19937, 37199, 39119, 71993, 91193, 93719, 93911, 99371, 193939, 199933, 319993, 331999, 391939, 393919, 919393, 933199, 939193, 939391, 993319, 999331};
    int m,n,i,cnt;
    while(scanf("%d",&m) &m!=-1) {
        scanf("%d",&n);
        cnt=0;
        for(i=0; i<42; ++i) {
            if(m<100) m=112;
            if(myints[i]>n) break;
            if(myints[i]<=n && myints[i]>=m) ++cnt;
        }
        if(!cnt)puts("No Circular Primes.");
        else if(cnt==1)puts("1 Circular Prime.");
        else printf("%d Circular Primes.\n",cnt);
    }
    return 0;
}
