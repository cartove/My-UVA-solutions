#include <stdio.h>
#define MAXX 1500
int min(int n0,int n1) {
    if(n0>n1)
        return n1;
    else
        return n0;
}
int main() {
    int i,j;
    int uglyarr[MAXX +1],fact[]= {2,3,5},chq[]= {1,1,1};
    uglyarr[1]=1;
    for(i=2; i<=MAXX;i++) {
        uglyarr[i] = min(2*uglyarr[chq[0]],min(3*uglyarr[chq[1]], 5*uglyarr[chq[2]]));
        for(j=0; j<3; j++)
            if(fact[j]*uglyarr[chq[j]]==uglyarr[i])
             chq[j]++;
    }
    printf("The 1500'th ugly number is %d.\n",uglyarr[MAXX]);
    return 0;
}

//inspierd by Belbesy
//or just it's his own algorithim !
