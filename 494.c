#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100000
int main() {
    char c[SIZE];
    int cont,i=0,size0=0;
    while(gets(c)) {
        cont=0;
        size0=strlen(c);
        for(i=0; i<size0; ++i)
            if((( (c[i]<='Z'&& c[i]>='A') || (c[i]<='z' && c[i] >='a') )) && !((( (c[i+1]<='Z'&& c[i+1]>='A') || (c[i+1]<='z' && c[i+1] >='a') )))) ++cont;
                    printf("%d\n",cont);
                }
        return 0;
}
