#include <iostream>
#include<algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;

int main( ) {
    char c[10];
    int size,cases;
    scanf("%d\n",&cases);
    while(cases--) {
        gets(c);
        size=strlen(c);
        sort (c,c+size);
        printf("%s\n",c);
        while ( next_permutation (c,c+size))  printf("%s\n",c);
        printf("\n");
    }
    return 0;
}
