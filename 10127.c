#include <stdio.h>

int main () {
    int n,num,ones, k;
    while (scanf ("%d", &num) != EOF) {
        n = ones = k = 1;
        while (k) {
            if ( n< num ) {
                n = ( n * 10 ) + 1;
                ++ones;
            }
            k = n % num;
            n = k;
        }
        printf("%d\n", ones);
    }
    return 0;
}
