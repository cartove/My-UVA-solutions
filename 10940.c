#include <stdlib.h>
int main() {
   register int n,i;
   char input[100];

    while(1) {
        i=1;
	  fgets ( input, 100, stdin );
	  n = atoi (input);
        if(n==0) break;
        if(1048576%n==0) {
            printf("%d\n",n);
            continue;
        }
            while(i<n)
                i*=2;
            printf("%d\n",n-(i%n));
    }
    return 0;
}
