#include<stdio.h>
 int main() {
    long  i,k,p,n;
    long  t[]= {1,10,100,1000,10000,100000,1000000,10000000};
    long  a[]= {-1,9,189,2889,38889,488889,5888889,68888889,100000001};
    while(scanf("%ld",&n)==1) {
        for(i=1; n>a[i]; i++);
        k=n-a[i-1];
        p=k%i;
        k=k/i;
        if(p==1)
            p=(k/t[i-1])%10+1;
        else if(p)
            p=(k/t[i-p])%10;
        else
            p=(k-1)%10;
        printf("%ld\n",p);
    }
    return 0;
}
