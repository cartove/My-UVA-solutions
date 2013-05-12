#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <stdint.h>

#define min(x,y) ((x) < (y) ? (x) : (y))
#define max(x,y) ((x) > (y) ? (x) : (y))


struct fraction {

    int  num;
    int  den;
    int  oper;
    void simplify();
    void simplify(fraction &f);
    int gcd(int c, int d);

    fraction();
    fraction(const int&,const int&);
    fraction(const int&,const int&,const int&);
    fraction(const fraction&);
    void operator =(const fraction &);
    fraction operator +(const fraction&);
    fraction operator /(const fraction&);
    friend void out(const fraction &f,bool isNeg);
};

fraction::fraction() {
    num=0;
    den=1;
    oper=0;
}

fraction::fraction(const int &n,const int &d) {
    if(n>d) {
        num=n%d;
        oper=n/d;
        den=d;
    } else if(n==d) {
        num=0;
        den=1;
        oper=1;
    } else {
        oper=0;
        num=n;
        den=(d==0)? 1 :d;
    }
    simplify();
}

fraction::fraction (const fraction &f) {
    num=f.num;
    den=f.den;
    oper=f.oper;
    simplify();
}

void fraction::simplify(fraction &f) {
    if(f.num==0 || f.den==0)return;
    int g = gcd(f.num,f.den);
    f.num/=g;
    f.den/=g;
    if(f.num>f.den) {
        f.oper+=f.num/f.den;
        f.num=1;
    }
}

void fraction::simplify() {
    if(num==0 || den==0)return;
    int g = gcd(num,den);
    num/=g;
    den/=g;
    if(num>den) {
        oper+=num/den;
        num=1;
    }
}


int fraction::gcd(int c, int d) {
    int64_t u, v, s;
    u = __builtin_ctz(c);
    v = __builtin_ctz(d);
    s = (u < v) ? u : v;
    u = c >> u;
    v = d >> v;
    while(u != v)
        if(u > v) {
            u -= v;
            u >>= __builtin_ctz(u);
        } else {
            v -= u;
            v >>= __builtin_ctz(v);
        }
    return u << s;
}
void out(const fraction &f,bool isNeg) {
    if(f.num==0 ) {
        if(f.oper==0)puts("0");
        else {
            if(isNeg)
                printf ("- %llu\n",f.oper);
            else printf ("%llu\n",f.oper);
        }
    } else if(f.oper==0) {
        if(f.num<10 && f.den <10)
            if(isNeg)
                printf ("  %llu\n- -\n  %llu\n",f.num,f.den);
            else printf ("%llu\n-\n%llu\n",f.num,f.den);
        else if(f.num<100  &&f.num>9 &&f.den <100)
            if(isNeg)
                printf ("  %llu\n- --\n  %llu\n",f.num,f.den);
            else printf ("%llu\n--\n%llu\n",f.num,f.den);
        else if(f.den<100 && f.num<10)
            if(isNeg)
                printf ("   %llu\n- --\n  %llu\n",f.num,f.den);
            else printf (" %llu\n--\n%llu\n",f.num,f.den);
        else if(f.num<1000  &&f.num>99)
            if(isNeg)
                printf ("  %llu\n- ---\n  %llu\n",f.num,f.den);
            else printf ("%llu\n---\n%llu\n",f.num,f.den);
        else if(f.den<1000 && f.num<99)
            if(f.num<10)  if(isNeg)
                    printf ("    %llu\n- ---\n  %llu\n",f.num,f.den);
                else printf ("  %llu\n---\n%llu\n",f.num,f.den);
            else if(isNeg)
                printf ("   %llu\n- ---\n  %llu\n",f.num,f.den);
            else printf (" %llu\n---\n%llu\n",f.num,f.den);
    } else if(f.oper<10) {
        if(f.num<10 && f.den <10)
            if(isNeg)
                printf ("   %llu\n- %llu-\n   %llu\n",f.num,f.oper,f.den);
            else printf (" %llu\n%llu-\n %llu\n",f.num,f.oper,f.den);
        else if(f.num<100  &&f.num>9 &&f.den <100)
            if(isNeg)
                printf ("   %llu\n- %llu--\n   %llu\n",f.num,f.oper,f.den);
            else printf (" %llu\n%llu--\n %llu\n",f.num,f.oper,f.den);
        else if(f.den<100 && f.num<10)
            if(isNeg)
                printf ("    %llu\n- %llu--\n   %llu\n",f.num,f.oper,f.den);
            else printf ("  %llu\n%llu--\n %llu\n",f.num,f.oper,f.den);
        else if(f.num<1000  &&f.num>99)
            if(isNeg)
                printf ("   %llu\n- %llu---\n   %llu\n",f.num,f.oper,f.den);
            else printf (" %llu\n%llu---\n %llu\n",f.num,f.oper,f.den);
        else if(f.den<1000 && f.num<99) {
            if(f.num<10)  if(isNeg)
                    printf ("     %llu\n- %llu---\n   %llu\n",f.num,f.oper,f.den);
                else printf ("   %llu\n%llu---\n %llu\n",f.num,f.oper,f.den);
            else if(f.num<100)  if(isNeg)
                    printf ("    %llu\n- %llu---\n   %llu\n",f.num,f.oper,f.den);
                else printf ("  %llu\n%llu---\n %llu\n",f.num,f.oper,f.den);
            else if(f.num<1000)  if(isNeg)
                    printf ("     %llu\n- %llu---\n   %llu\n",f.num,f.oper,f.den);
                else printf ("   %llu\n%llu---\n %llu\n",f.num,f.oper,f.den);
        } else {
            if(isNeg)
                printf ("    %llu\n- %llu---\n   %llu\n",f.num,f.oper,f.den);
            else printf ("  %llu\n%llu---\n %llu\n",f.num,f.oper,f.den);
        }
    } else if(f.oper<100) {
        if(f.num<10 && f.den <10)
            if(isNeg)
                printf ("    %llu\n- %llu-\n    %llu\n",f.num,f.oper,f.den);
            else printf ("  %llu\n%llu-\n  %llu\n",f.num,f.oper,f.den);
        else if(f.num<100  &&f.num>9 &&f.den <100)
            if(isNeg)
                printf ("    %llu\n- %llu--\n    %llu\n",f.num,f.oper,f.den);
            else printf ("  %llu\n%llu--\n  %llu\n",f.num,f.oper,f.den);
        else if(f.den<100 && f.num<10)
            if(isNeg)
                printf ("     %llu\n- %llu--\n    %llu\n",f.num,f.oper,f.den);
            else printf ("   %llu\n%llu--\n  %llu\n",f.num,f.oper,f.den);
        else if(f.num<1000  &&f.num>99)
            if(isNeg)
                printf ("    %llu\n- %llu---\n    %llu\n",f.num,f.oper,f.den);
            else printf ("  %llu\n%llu---\n  %llu\n",f.num,f.oper,f.den);
        else if(f.den<1000 && f.num<99) {
            if(f.num<10)  if(isNeg)
                    printf ("      %llu\n- %llu---\n    %llu\n",f.num,f.oper,f.den);
                else printf ("    %llu\n%llu---\n  %llu\n",f.num,f.oper,f.den);
            else if(f.num<100 &&f.num>9)  if(isNeg)
                    printf ("     %llu\n- %llu---\n    %llu\n",f.num,f.oper,f.den);
                else printf ("   %llu\n%llu---\n  %llu\n",f.num,f.oper,f.den);
            else if(f.num<1000 && f.num>99)  if(isNeg)
                    printf ("     %llu\n- %llu---\n     %llu\n",f.num,f.oper,f.den);
                else printf ("   %llu\n%llu---\n    %llu\n",f.num,f.oper,f.den);

        } else {
            if(isNeg)
                printf ("     %llu\n- %llu---\n    %llu\n",f.num,f.oper,f.den);
            else printf ("   %llu\n%llu---\n  %llu\n",f.num,f.oper,f.den);
        }
    } else if(f.oper<1000) {
        if(f.num<10 && f.den <10)
            if(isNeg)
                printf ("     %llu\n- %llu-\n     %llu\n",f.num,f.oper,f.den);
            else printf ("   %llu\n%llu-\n   %llu\n",f.num,f.oper,f.den);
        else if(f.num<100  &&f.num>9 &&f.den <100)
            if(isNeg)
                printf ("     %llu\n- %llu--\n     %llu\n",f.num,f.oper,f.den);
            else printf ("   %llu\n%llu--\n   %llu\n",f.num,f.oper,f.den);
        else if(f.den<100 && f.num<10)
            if(isNeg)
                printf ("      %llu\n- %llu--\n     %llu\n",f.num,f.oper,f.den);
            else printf ("    %llu\n%llu--\n   %llu\n",f.num,f.oper,f.den);
        else if(f.num<1000  &&f.num>99) {
            if(isNeg)
                printf ("     %llu\n- %llu---\n     %llu\n",f.num,f.oper,f.den);
            else printf ("   %llu\n%llu---\n   %llu\n",f.num,f.oper,f.den);
        } else if(f.den<1000 && f.num<99) {
            if(f.num<10)  if(isNeg)
                    printf ("       %llu\n- %llu---\n     %llu\n",f.num,f.oper,f.den);
                else printf ("     %llu\n%llu---\n   %llu\n",f.num,f.oper,f.den);
            else if(f.num<100 &&f.num>9)  if(isNeg)
                    printf ("      %llu\n- %llu---\n     %llu\n",f.num,f.oper,f.den);
                else printf ("    %llu\n%llu---\n   %llu\n",f.num,f.oper,f.den);
            else if(f.num<1000 && f.num>99)  if(isNeg)
                    printf ("      %llu\n- %llu---\n      %llu\n",f.num,f.oper,f.den);
                else printf ("    %llu\n%llu---\n     %llu\n",f.num,f.oper,f.den);
        } else {
            if(isNeg)
                printf ("      %llu\n- %llu---\n     %llu\n",f.num,f.oper,f.den);
            else printf ("    %llu\n%llu---\n   %llu\n",f.num,f.oper,f.den);
        }
    } else if(f.oper<10000) {
        if(f.num<10 && f.den <10)
            if(isNeg)
                printf ("      %llu\n- %llu-\n      %llu\n",f.num,f.oper,f.den);
            else printf ("    %llu\n%llu-\n    %llu\n",f.num,f.oper,f.den);
        else if(f.num<100  &&f.num>9 &&f.den <100)
            if(isNeg)
                printf ("      %llu\n- %llu--\n      %llu\n",f.num,f.oper,f.den);
            else printf ("    %llu\n%llu--\n    %llu\n",f.num,f.oper,f.den);
        else if(f.den<100 && f.num<10)
            if(isNeg)
                printf ("       %llu\n- %llu--\n      %llu\n",f.num,f.oper,f.den);
            else printf ("     %llu\n%llu--\n    %llu\n",f.num,f.oper,f.den);
        else if(f.num<1000  &&f.num>99) {
            if(isNeg)
                printf ("      %llu\n- %llu---\n      %llu\n",f.num,f.oper,f.den);
            else printf ("    %llu\n%llu---\n    %llu\n",f.num,f.oper,f.den);
        } else if(f.den<1000 && f.num<99) {
            if(f.num<10)  if(isNeg)
                    printf ("        %llu\n- %llu---\n      %llu\n",f.num,f.oper,f.den);
                else printf ("      %llu\n%llu---\n    %llu\n",f.num,f.oper,f.den);
            else if(f.num<100 &&f.num>9)  if(isNeg)
                    printf ("       %llu\n- %llu---\n      %llu\n",f.num,f.oper,f.den);
                else printf ("     %llu\n%llu---\n    %llu\n",f.num,f.oper,f.den);
            else if(f.num<1000 && f.num>99)  if(isNeg)
                    printf ("       %llu\n- %llu---\n       %llu\n",f.num,f.oper,f.den);
                else printf ("     %llu\n%llu---\n      %llu\n",f.num,f.oper,f.den);
        } else {
            if(isNeg)
                printf ("       %llu\n- %llu---\n      %llu\n",f.num,f.oper,f.den);
            else printf ("     %llu\n%llu---\n    %llu\n",f.num,f.oper,f.den);
        }
    }else if(f.oper<100000) {
        if(f.num<10 && f.den <10)
            if(isNeg)
                printf ("       %llu\n- %llu-\n       %llu\n",f.num,f.oper,f.den);
            else printf ("     %llu\n%llu-\n     %llu\n",f.num,f.oper,f.den);
        else if(f.num<100  &&f.num>9 &&f.den <100)
            if(isNeg)
                printf ("       %llu\n- %llu--\n       %llu\n",f.num,f.oper,f.den);
            else printf ("     %llu\n%llu--\n     %llu\n",f.num,f.oper,f.den);
        else if(f.den<100 && f.num<10)
            if(isNeg)
                printf ("        %llu\n- %llu--\n       %llu\n",f.num,f.oper,f.den);
            else printf ("      %llu\n%llu--\n     %llu\n",f.num,f.oper,f.den);
        else if(f.num<1000  &&f.num>99) {
            if(isNeg)
                printf ("       %llu\n- %llu---\n       %llu\n",f.num,f.oper,f.den);
            else printf ("     %llu\n%llu---\n     %llu\n",f.num,f.oper,f.den);
        } else if(f.den<1000 && f.num<99) {
            if(f.num<10)  if(isNeg)
                    printf ("         %llu\n- %llu---\n       %llu\n",f.num,f.oper,f.den);
                else printf ("       %llu\n%llu---\n     %llu\n",f.num,f.oper,f.den);
            else if(f.num<100 &&f.num>9)  if(isNeg)
                    printf ("        %llu\n- %llu---\n       %llu\n",f.num,f.oper,f.den);
                else printf ("      %llu\n%llu---\n     %llu\n",f.num,f.oper,f.den);
            else if(f.num<1000 && f.num>99)  if(isNeg)
                    printf ("        %llu\n- %llu---\n        %llu\n",f.num,f.oper,f.den);
                else printf ("      %llu\n%llu---\n       %llu\n",f.num,f.oper,f.den);
        } else {
            if(isNeg)
                printf ("       %llu\n- %llu---\n      %llu\n",f.num,f.oper,f.den);
            else printf ("     %llu\n%llu---\n    %llu\n",f.num,f.oper,f.den);
        }
    }

}
int main() {
    int myint,temp,sum,count=0;
    bool isNeg;
    while(1) {
        isNeg=false;
        scanf("%d",&myint);
        if(myint==0)return 0;
        sum=0;
        for(int i=0; i<myint; ++i) {
            scanf("%d",&temp);
            sum+=temp;
        }
        printf("Case %d:\n",++count);
        if(sum<0) {
            isNeg=true;
            sum=abs(sum);
        }
        fraction myf(sum,myint);
        out(myf,isNeg);
    }
}
