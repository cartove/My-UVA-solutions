#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define SIZE 2001
void sumchararray(char year[], long long *sum ) {
    int i;
    for (i=0; year[i]; ++i) *sum +=year[i]-'0';

}
void altsumchar(char year[], long long *asum) {
    long int i ;
    for (i=0; year[i]; ++i) *asum+=(pow(-1,i)*(year[i]-'0'));
}

int mod(char year[],int n) {
    int i,y=0;
    for(i=0 ; year[i]; ++i) y=(y*10+year[i]-'0')%n;
    return y;
}

int main() {
    char year[SIZE]= {0};
    int size ,leap,hu,bu,flag=0;
    long long sum=0,asum=0;
    while(scanf("%s",year)==1) {
        size=leap=hu=bu=sum=asum=0;
        if ( flag != 0 )
            printf("\n");
        flag = 1;
        size =strlen(year);
        sumchararray(year, &sum );
        altsumchar(year, &asum );
        if(!mod(year,4)&&(mod(year,100)||!mod(year,400))) {
            leap =1;
            printf("This is leap year.\n");
        }
        if(((year[size-1]-'0') % 5 ==0) && sum%3==0 ) {
            hu=1;
            printf("This is huluculu festival year.\n");
        }
        if(leap ==1 &&(( year[size-1]-'0') % 5)==0 && (asum%11)==0 ) {
            bu=1;
            printf("This is bulukulu festival year.\n");
        }
        if (leap==0 && hu==0 &&bu==0)   printf("This is an ordinary year.\n");
    }
    return 0;
}


