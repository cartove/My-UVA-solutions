#include <stdio.h>
#include <stdlib.h>

int main() {
    int cases,i;
    long a, b;
    scanf("%d",&cases);
    for (i=0; i<cases; i++) {
        scanf("%ld%ld",&a,&b);
        if (a<b) printf("<\n");
        else if (a>b) printf(">\n");
        else printf("=\n");
    }
    return 0;
}
