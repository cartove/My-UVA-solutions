#include <stdio.h>

int main() {
    int n;
    register int i,j;
    while (scanf("%d", &n) != EOF) {
        int numbers[1000] ;
        int count = 0;
        for ( i = 0; i < n; ++i) scanf("%d", &numbers[i]);
        for ( i = 0; i < n; ++i )
            for ( j = i + 1; j < n; ++j )
                if ( numbers [i] > numbers [j] ) ++count;
        fwrite("Minimum exchange operations : ",1,30,stdout);
        printf("%d\n", count);
    }
    return 0;
}
