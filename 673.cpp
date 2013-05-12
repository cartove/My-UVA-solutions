#include <stdio.h>
#include <stack>
using namespace std;

int main() {
    int cases;
    scanf("%d\n",&cases);
    while(cases--) {
        bool flagy=false;
        char word[130];
        stack<char> stacky;
        gets(word);
        for(int i=0; word[i]; ++i) {
            if(word[i]=='[' ||word[i]=='(') {
                stacky.push(word[i]);
            } else {
                if(word[i]==']') {
                    if (stacky.empty() || stacky.top() == '(')     flagy |= true;
                } else if(word[i]==')') {
                    if (stacky.empty() || stacky.top() == '[')     flagy |= true;
                }
                else continue;
                if(!stacky.empty())
                    stacky.pop();
            }
        }
        if(stacky.empty()&&!flagy) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
