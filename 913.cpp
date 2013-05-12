#include <iostream>
#include <cstdio>

int main() {
    register long long n=0;
    while(std::cin>>n)
        printf("%lld\n",((3*(++n*n))>>1)-9);
    return 0;
}
