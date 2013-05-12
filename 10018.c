#include<stdio.h>
#include<stdlib.h>

unsigned long rev(unsigned long v) {
unsigned long  revv = 0 ;
do (revv = revv * 10 + v %10) ;
while ( v = v / 10 );
return rev;
}
int main() {
    unsigned long num,n,k;
    int cases,flag;
    scanf("%d",&cases);
    while(cases-- ){
        scanf("%lu",&num);
        n = rev(num);
        k = n + num;
        flag = 1;
        while(1) {
            n = rev(k);
            if(n == k)  break;
            k= n + k;
            ++flag;
        }
        printf("%d %lu\n",flag,k);
    }
    return 0;
}
