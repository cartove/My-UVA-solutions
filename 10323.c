#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    while(scanf("%d",&n)!=EOF) {
        if(n >=14 ) {
            printf("Overflow!\n");
            continue;
        } else if(n <= 7 && n>=0) {
            printf("Underflow!\n");
            continue;
        } else if(n>=8 && n<=13){
            if(n==8)
                printf("40320\n");
            else if (n==9)
                printf("362880\n");
            else if (n==10)
                printf("3628800\n");
            else if (n==11)
                printf("39916800\n");
            else if (n==12)
                printf("479001600\n");
                else
                 printf("6227020800\n");
        }else{
        if(abs(n)%2)
        printf("Overflow!\n");
        else
        printf("Underflow!\n");
        }
    }
    return 0;
}
