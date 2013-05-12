#include <stdio.h>
#include <utility>
#include <iostream>
#include <deque>
#include <algorithm>

std::deque<std::pair<int,int> > hiset;
std::deque<bool> hib;
std::deque<std::pair<int,int> >::iterator it;

int main() {
    std::pair <int,int> x;
    while (scanf("%d", &x.first)==1) {
        bool z=false;
        hiset.push_back(x);
        hib.push_back(z);
        for(it=hiset.begin(); it!=hiset.end(); ++it)
            if(x.first==it->first) {
                (it->second)++;
                break;
            }
    }
    for(it=hiset.begin(); it!=hiset.end(); ++it) {
        if(it->second ==0) continue;
        std::cout<<it->first<<" "<<it->second<<std::endl;
    }
    return 0;
}
