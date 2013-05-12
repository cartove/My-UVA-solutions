#include <string>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <algorithm>
bool flag;

std::string dechex (std::string str) {
    if(str[1]=='x') {
        flag=true;
        int num;
        std::stringstream o;
        std::istringstream i(str);
        i >> std::hex >> num;
        o<<num;
        return o.str();
    } else {
        flag=false;
        int num=atoi(str.c_str());
        std::stringstream o;
        o << std::hex << num;
        return o.str();
    }
}

int main() {
    std::string mystring;
    while(getline(std::cin,mystring)) {
        if(mystring[0]=='-') return 0;
        std::string stringy=dechex(mystring);
        if (flag==false) std::cout<<"0x";
        std::transform(stringy.begin(), stringy.end(),stringy.begin(), ::toupper);
        std::cout<<stringy<<std::endl;
    }
    return 0;
}
