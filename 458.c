#include<stdio.h>
int main() {
    char c;
    int d;
    while(scanf("%c",&c)) {
        d=c;
        if(d!=10)
        printf("%c",d-7);
        else
        printf("\n");
    }
    return 0;
}
