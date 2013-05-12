#include<stdio.h>
#include<stack>
#include<string>
#include<cstring>
#include<stdlib.h>
#include<ctype.h>

using namespace std;

stack<char>S;
char Sym[] = "()[]{}";

void Cal(char ch) {
    int i;
    if(isdigit(ch)) {
        printf("%c",ch);
        return;
    }
    if(ch == '(' || ch == '[' || ch == '{') {
        S.push(ch);
        return;
    }
    if(ch == ')' || ch == ']' || ch == '}') {
        for(i = 1; Sym[i] !=ch; i+=2);//and never remove this empty loop !
        while(S.top() != Sym[i-1]) {//empty loop profit ! now i know the prant
            printf("%c",S.top());
            S.pop();
        }
        S.pop();
        return;
    }
    if(ch == '+' || ch == '-') {
        while(S.top() =='+'||S.top() =='-'||S.top() =='*'||S.top() =='/') {
            printf("%c",S.top());
            S.pop();
        }
        S.push(ch);
    }
    if(ch == '*' || ch == '/') {
        while(S.top() =='*'||S.top() =='/') {
            printf("%c",S.top());
            S.pop();
        }
        S.push(ch);
    }
}

int main() {
    char temp[100];//50 is ok but what ever :S
    int cases;
    gets(temp);
    cases = atoi(temp);
    gets(temp);
    while(cases--) {
        S.push('(');
        while(gets(temp)) {
            for(int i = 0; temp[i]; i++) {
                if(temp[i] == '\n') {
                    temp[i] ='\0';
                    break;
                }
            }
            if(temp[0]=='\0') break;
            Cal(temp[0]);
        }
        Cal(')');
        printf("\n");
        if(cases) printf("\n");//got 3 WA ! FUUUUU don't remove and remember it
    }
    return 0;
}
