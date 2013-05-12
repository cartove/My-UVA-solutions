#include <cstdio>
#include <algorithm>
#include <cstring>
#include <ctype.h>
#define max(x,y) ((x) > (y) ? (x) : (y))
#define CLEAR(s) memset(&(s), 0, sizeof(s))
char c[1000];
bool comp(char i,char j) {
    int def = toupper(i) - toupper(j);
    if(def) return def<0;
    else return i<j;
}

int main() {
    int size,cases;
    scanf("%d\n",&cases);
    while(cases--) {
        gets(c);
        size=strlen(c);
        std::sort (c,c+size,comp);
        do
            puts(c);
        while ( std::next_permutation (c,c+size,comp));
    }
    return 0;
}
