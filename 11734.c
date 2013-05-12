#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void striper(char buffer[]) {

    char *pbuffer1 = buffer;
    char *pbuffer2 = buffer;
    pbuffer1 = buffer;
    while(*pbuffer1 != '\0') {
        if(ispunct(*pbuffer1) || isspace(*pbuffer1)) {
            ++pbuffer1;
            continue;
        } else
            *pbuffer2++ = *pbuffer1++;
    }
    *pbuffer2 = '\0';
}


int main() {
    int cases,textor=1;
    char text[1000],txt[1000],texts[1000],txts[1000];
    scanf("%d\n",&cases);
    while(cases --) {
        gets(text);
        gets(txt);
        strcpy(texts,text);
        strcpy(txts,txt);
        striper(texts);
        striper(txts);
        printf("Case %d: ",textor);
        if(!strcmp(text,txt))
            puts("Yes");
        else if(strcmp(texts,txts))
            puts("Wrong Answer");
        else
            puts("Output Format Error");
        textor++;
    }
    return 0;
}
