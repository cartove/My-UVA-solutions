#include <iostream>

int main() {
    register unsigned cases,casesx,sz,env,num,total;
    std::cin>> cases;
    while(cases--) {
        std::cin>> casesx;
        total=0;
        while(casesx--) {
                std::cin>>sz>>num>>env;
            total+=sz*env;
        }
    std::cout<<total<<std::endl;
    }
    return 0;
}
