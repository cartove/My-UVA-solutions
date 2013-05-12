#include <iostream>
#include <ostream>
#include <string>
#include <sstream>
#include <deque>
#include <algorithm>

class reverse_word : public std::unary_function<std::string, std::string> {
public:
    std::string& operator()(std::string& str) {
        std::reverse(str.begin(), str.end());
        return str;
    }
};

int main() {
    std::string str;
    while(getline (std::cin,str)) {
        std::stringstream ss (str);
        std::deque<std::string>word_list;
        std::string temp;
        while( ss >> temp )
            word_list.push_back(temp);
        std::for_each(word_list.begin(), word_list.end(), reverse_word() );
        std::deque<std::string>::const_iterator i;
        for( i = word_list.begin() ; i != word_list.begin()+(word_list.size()-1) ; ++i )
            std::cout << *i << " ";
        std::cout <<word_list.back()<<std::endl;
    }
    return 0;
}
