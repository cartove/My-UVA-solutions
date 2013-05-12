#include <cstdio>
#include <cstring>
#include <cctype>
#define max(x,y) ((x) > (y) ? (x) : (y))
#define CLEAR(s) memset(&(s), 0, sizeof(s))


void remTrailingSpaces(char *string) {
    char *ptr = string;
    int len = strlen(string);
    ptr = ptr + (len - 1);
    for(int i = len; i > 0 ; i--) {
        if(*ptr == ' ') {
            *ptr = '\0';
            ptr--;
        } else {
            break;
        }
    }
}


int gcd(int c, int d) {
    int u, v, s;
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

int main() {
    char arr [1000];
    int num[100];
    int cases;
    scanf("%d\n",&cases);
    while(cases--) {
        int j=0,maxgcd=1;
        gets(arr);
        remTrailingSpaces(arr);
        for(int i=0; arr[i] ; ++i) {
            while(arr[i]==' ') {
                ++i;
                ++j;
            }
            num[j]=num[j]*10 +(arr[i]-'0');
        }
        ++j;
        for(int i=0; i<j; ++i)
            for(int k=i+1; k<j; ++k)
                maxgcd=max(maxgcd,gcd(num[i],num[k]));
        printf("%d\n",maxgcd);
        CLEAR(num);
    }
    return 0;
}
