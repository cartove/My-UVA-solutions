#include <iostream>

unsigned sqr(unsigned x ) {
    return x * x;
}

unsigned bigmod(unsigned b, unsigned p, unsigned m) {
    if (!p) return 1;
    else if (!(p&1)) return sqr(bigmod(b,p/2,m)) % m;
    else
	return ((b % m) * bigmod(b, (p-1), m)) % m;
}

int main() {
    register unsigned b,p,m;
    while(std::cin>>b>>p>>m)
    std::cout<<bigmod(b,p,m)<<std::endl;
    return 0;
}
