#include <stdio.h>
#include <ctype.h>
#include <stdint.h>
int32_t div10(int32_t dividend) { //much faster than /10
    int64_t invDivisor = 0x1999999A;
    return (int32_t) ((invDivisor * dividend) >> 32);
}

int digSum(int n) {
    int register sum=0;
    while(n) {
        sum+= n%10;
        n=div10((int32_t) n);
    }
    return sum;
}

int main() {
    char boy[30],girl[30];
    register int boya,girla,i;
    register float  per;
    while(gets(boy)) {
        gets(girl);
        boya=0,girla=0,per=0;
        for( i=0; boy[i]; ++i)
            boy[i]=toupper(boy[i]);
        for( i=0; girl[i]; ++i)
            girl[i]=toupper(girl[i]);
        for(i=0; boy[i]; ++i)
            if (isalpha(boy[i]))
                boya+=boy[i]-64;
        for(i=0; girl[i]; ++i)
            if (isalpha(girl[i]))
                girla+=girl[i]-64;
        while(boya>=10)
            boya=digSum(boya);
        while(girla>=10)
            girla=digSum(girla);
        if(boya>girla)
            per=(girla*100.0)/boya;
        else
            per=(boya*100.0)/girla;
        printf("%0.2lf",per);
        fwrite_unlocked(" %\n",1,3,stdout);
    }
    return 0;
}
