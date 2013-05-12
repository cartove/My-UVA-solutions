#include <iostream>
#include <cstdio>
#include <cstdlib>
int main()
{
    register int cases,s,d,x,y;
    std::cin>> cases;
    while(cases--)
    {
        std::cin>>s>>d;
        x=(s+d)>>1;
        y= s-x;
        if(x>=0 && y>=0 && (s+d)%2==0 ) std::cout<<abs(x)<<" "<<abs(y)<<std::endl;
        else puts("impossible");
    }
    return 0;
}
