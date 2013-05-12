#include <stdio.h>
#include <string.h>

int main() {
    char mystring [15];
    register int count=0;
    while(gets(mystring)&&mystring[0]!='#') {
        fwrite("Case ",5,1,stdout);
        printf("%d",++count);
        if(strstr (mystring,"HELLO"))
            fwrite(": ENGLISH\n",10,1,stdout);
        else if(strstr (mystring,"HOLA"))
            fwrite(": SPANISH\n",10,1,stdout);
        else if(strstr (mystring,"HALLO"))
        fwrite(": GERMAN\n",9,1,stdout);
        else if(strstr (mystring,"BONJOUR"))
        fwrite(": FRENCH\n",9,1,stdout);
        else if(strstr (mystring,"CIAO"))
        fwrite(": ITALIAN\n",10,1,stdout);
        else if(strstr (mystring,"ZDRAVSTVUJTE"))
        fwrite(": RUSSIAN\n",10,1,stdout);
        else fwrite(": UNKNOWN\n",10,1,stdout);
    }
    return 0;
}
