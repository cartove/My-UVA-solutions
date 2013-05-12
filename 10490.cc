#include <stdio.h>
int main() {
    int n;
    while(scanf("%d",&n)&&n) {
        switch (n) {
        case 1:
            puts("Perfect: 1!\n");
            break;
        case 2:
            puts("Perfect: 6!\n");
            break;
        case 3:
            puts("Perfect: 28!\n");
            break;
        case 4:
        case 6:
        case 8:
        case 9:
        case 10:
        case 12:
        case 14:
        case 15:
        case 16:
        case 18:
        case 20:
        case 21:
        case 22:
        case 24:
        case 25:
        case 26:
        case 27:
        case 28:
        case 30:
            puts("Given number is NOT prime! NO perfect number is available.\n");
            break;
        case 5:
            puts("Perfect: 496!\n");
            break;
        case 7:
            puts("Perfect: 8128!\n");
            break;
        case 11:
        case 23:
        case 29:
            puts("Given number is prime. But, NO perfect number is available.\n");
            break;
        case 13:
            puts("Perfect: 33550336!\n");
            break;
        case 17:
            puts("Perfect: 8589869056!\n");
            break;
        case 19:
            puts("Perfect: 137438691328!\n");
            break;
        case 31:
            puts("Perfect: 2305843008139952128!\n");
            break;
        }
    }
    return 0;
}


