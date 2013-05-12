#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 130
int main() {
    char word [SIZE];
    int cases,cont01,cont02,cont11,cont12,i,stsize;
    scanf("%d\n",&cases);
    while(cases--) {
        word[0] = 0;
        cont01=cont02=cont11=cont12=0;
        gets(word);
        for(i=0;word[i];++i) {
            if(word[i]==']') {
                ++cont12;
                if(word[i-1]=='(')
                    break;
            }
            if(word[i]==')') {
               ++cont02;
                if(word[i-1]=='[')
                    break;
            }
            if(cont12>cont11)
                break;
            if(cont02>cont01)
                break;
            if(word[i]=='[') {
                ++cont11;
                if(word[i+1]==')')
                    break;
            }
            if(word[i]=='(') {
               ++cont01;
                if(word[i+1]==']')
                    break;
            }
        }
        if(cont11==cont12 && cont01==cont02)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}

