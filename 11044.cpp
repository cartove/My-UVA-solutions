#include <iostream>

int main() {
        register unsigned cases,n,m;
    std::cin>> cases;
    while(cases--) {
        std::cin>>n>>m;
        m-=2;
        n-=2;
        if(n % 3 == 0)  n/= 3;
        else n=n/3 + 1;
        if(m % 3 == 0) m/= 3;
        else m=m / 3 + 1;
        std::cout<<m*n<<std::endl;
        }
        return 0;
    }
