#include <stdio.h>
#include <stdlib.h>
int a[15]= {0};
int main() {
    register int i,j,k,l,m,n;
    int flag=0,size;
    while(1) {
        scanf("%d",&size);
        if(size==0)break;
        if(flag==1) printf("\n");
        for(i=0; i<size; ++i)
            scanf("%d",&a[i]);

        for(i=0; size-i>5; ++i)
            for(j=i+1; size-j>4; ++j)
                for(k=j+1; size-k>3; ++k)
                    for(l=k+1 ; size-l>2; ++l)
                        for(m=l+1; size-m>1; ++m)
                            for(n=m+1; size-n>0; ++n)
                                printf("%d %d %d %d %d %d\n",a[i],a[j],a[k],a[l],a[m],a[n]);
                                flag=1;
    }
    return 0;
}
