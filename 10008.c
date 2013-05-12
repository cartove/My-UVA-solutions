#include <stdio.h>

typedef struct  {
    int count;
    char ch;
} crypto;

int i,j;
crypto a [27];
char in[1000]= {0};
void sort(int x[],crypto array[], int n) {
    int i,j;
    for(i = 0; i < n-1; ++i) {
        for(j = i+1; j < n; ++j) {
            if( array[x[i]].count > array[x[j]].count ) {
                int hold = array[x[i]].count;
                char swapy =array[x[i]].ch;
                array[x[i]].ch = array[x[j]].ch;
                array[x[i]].count = array[x[j]].count;
                array[x[j]].ch = swapy;
                array[x[j]].count = hold;
            }
            if(array[x[i]].count == array[x[j]].count && array[x[i]].ch < array[x[j]].ch) {
               char swapy =array[x[i]].ch;
                array[x[i]].ch = array[x[j]].ch;
                array[x[j]].ch = swapy;
            }
        }
    }
}

int main() {
    int cases;
    int indexs[]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26};
    scanf("%d",&cases);
    getchar();
    while(cases--) {
        gets(in);
        for(i=0; in[i]; i++) {
            a[i].ch =i+65;
            if(in[i]>=97 && in[i]<=122) {
                (a[in[i]-97].count)+=1;
            }
            if(in[i]>=65 && in[i]<=90) {
                (a[in[i]-65].count)+=1;
            }
        }
    }
    sort(indexs,a, 27);
    for(i=26; i>0; i--)if(a[i].count!=0) printf("%c %d\n",a[i].ch,a[i].count);

    return 0;
}
