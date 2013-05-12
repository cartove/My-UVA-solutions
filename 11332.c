#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#define MAX 50

void f(char str[]) {
    int i,sum=0;
    for(i=0; str[i]; ++i)
        sum+=(str[i]-'0');
    sprintf (str, "%d", sum);
}
void g(char str[]) {
    while(str[1]!='\0')
        f(str);
}
int main() {
    char str[MAX];
    while(gets(str)&&str[0]!='0'){
        g(str);
        puts(str);
    }
    return 0;
}
