#include <stdio.h>
#include <stdlib.h>
int fibonacci(int n) {
    int a = 0,b = 1,sum,i;
    for (i=0; i<n; i++) {
        sum = a + b;
        a = b;
        b = sum;
    }
    return a;
}
int main() {
    int x;
    while(scanf("%d",&x)==1) {
        if(x==-1) break;
        printf("%d %d\n",fibonacci(x+2)-1,fibonacci(x+3)-1);
    }
    return 0;
}
