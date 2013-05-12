#include <string.h>
#include <stdio.h>

int main() {
    char text[1000];
    int flag=0,i;
    while(gets(text)) {
        for(i=0; text[i]; i++) {
            if(text[i]==34 &&flag==0) {
                printf("``");
                flag=1;
                continue;
            }
            if(text[i]==34 && flag==1) {
                printf("''");
                flag=0;
                continue;
            } else printf("%c",text[i]);
        }
        printf("\n");
    }
    return 0;
}
