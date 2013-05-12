#include <stdio.h>
int main() {
    int n,k,sum,avg,degs,i,result,_std[1000];
    scanf("%d",&n);
    for(k=0;k<n;++k){
        sum = 0;
        result = 0;
        scanf("%d",&degs);
        for(i=0; i<degs; ++i) {
            scanf("%d",&_std[i]);
            sum+=_std[i];
        }
        avg=sum/degs;
        for(i=0; i<degs; ++i) {
            if(_std[i]>avg)
                result++;
        }
        printf("%.3f%%\n",(result*100/(float)degs));
    }
    return 0;
}
