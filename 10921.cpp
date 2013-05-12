#include <cstdio>
#include <utility>
#include <list>

int main() {
    char str[33];
    std::list<std::pair<char,char> > mypattern;
    std::list<std::pair<char,char> >::iterator it;
    mypattern.push_back ( std::pair<char,char>('A','2') );
    mypattern.push_back ( std::pair<char,char>('B','2') );
    mypattern.push_back ( std::pair<char,char>('C','2') );
    mypattern.push_back ( std::pair<char,char>('D','3') );
    mypattern.push_back ( std::pair<char,char>('E','3') );
    mypattern.push_back ( std::pair<char,char>('F','3') );
    mypattern.push_back ( std::pair<char,char>('G','4') );
    mypattern.push_back ( std::pair<char,char>('H','4') );
    mypattern.push_back ( std::pair<char,char>('I','4') );
    mypattern.push_back ( std::pair<char,char>('J','5') );
    mypattern.push_back ( std::pair<char,char>('K','5') );
    mypattern.push_back ( std::pair<char,char>('L','5') );
    mypattern.push_back ( std::pair<char,char>('M','6') );
    mypattern.push_back ( std::pair<char,char>('N','6') );
    mypattern.push_back ( std::pair<char,char>('O','6') );
    mypattern.push_back ( std::pair<char,char>('M','6') );
    mypattern.push_back ( std::pair<char,char>('N','6') );
    mypattern.push_back ( std::pair<char,char>('O','6') );
    mypattern.push_back ( std::pair<char,char>('P','7') );
    mypattern.push_back ( std::pair<char,char>('Q','7') );
    mypattern.push_back ( std::pair<char,char>('R','7') );
    mypattern.push_back ( std::pair<char,char>('S','7') );
    mypattern.push_back ( std::pair<char,char>('T','8') );
    mypattern.push_back ( std::pair<char,char>('U','8') );
    mypattern.push_back ( std::pair<char,char>('V','8') );
    mypattern.push_back ( std::pair<char,char>('W','9') );
    mypattern.push_back ( std::pair<char,char>('X','9') );
    mypattern.push_back ( std::pair<char,char>('Y','9') );
    mypattern.push_back ( std::pair<char,char>('Z','9') );
    while(gets(str)) {
        for ( it=mypattern.begin() ; it != mypattern.end(); it++ ) {
            for(int i=0;str[i];++i)
                if(str[i]==it->first)
                    str[i]=it->second;
        }
        puts(str);
    }
    return 0;
}
