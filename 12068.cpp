#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


class fraction {
private:
    uint64_t  num;
    uint64_t  den;
    void simplify();
    void simplify(fraction &f);
    int gcd(int64_t c, int64_t d);

public:
    fraction();
    fraction(const int&,const int&);
    fraction(const fraction&);
    void operator =(const fraction &);
    fraction operator +(const fraction&);
    fraction operator /(const fraction&);
    friend void out(const fraction &f);
};

fraction::fraction() {
    num=0;
    den=1;
}

fraction::fraction(const int &n,const int &d) {
    num=n;
    den=(d==0)? 1 :d;
    simplify();
}

fraction::fraction (const fraction &f) {
    num=f.num;
    den=f.den;
    simplify();
}

void fraction::simplify(fraction &f) {
    int g = gcd(f.num,f.den);
    f.num/=g;
    f.den/=g;
}

void fraction::simplify() {
    register int g = gcd(num,den);
    den/=g;
    num/=g;
}

void fraction::operator =(const fraction& f) {
    num=f.num;
    den=f.den;
    fraction::simplify();
}

fraction fraction::operator +(const fraction &f) {
    fraction temp;
    temp.num = num * f.den + den * f.num;
    temp.den = den * f.den;
    simplify(temp);
    return temp;
}

fraction fraction::operator / (const fraction &f) {
    fraction temp;
    temp.num = num * f.den;
    temp.den = den* f.num;
    simplify(temp);
    return temp;
}

void out(const fraction &f) {
    printf ("%llu/%llu\n",f.num,f.den);
}
int fraction::gcd(int64_t c, int64_t d) {
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

int main() {
    int cases;
    register int xx=0;
    scanf("%d",&cases);
    while (cases--) {
        int count;
        fraction sumf;
        scanf("%d",&count);
        fraction _count(count,1);
        while(count--) {
            int templ;
            scanf("%d",&templ);
            fraction temp(1,templ);
            sumf=sumf+temp;
        }
        printf("Case %d: ",++xx);
        out(_count/sumf);
    }
}
