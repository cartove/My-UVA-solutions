#include <stdio.h>

int main() {
    int cases,m,n;
    scanf("%d",&cases);
    while(cases--){
        scanf("%d%d",&m,&n);
        if(n%m) puts("-1");
        else printf("%d %d\n",m,n);
    }
    return 0;
}
