#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <bitset>
#include<iostream>
using namespace std;



class Primes1000 {
public:
    std::bitset<100000> numbers;
    std::bitset<10000> flag ;
    //std::vector <int> primes;
    Primes1000();
    void generate(const int&);
    bool isPrime(const int& );
    void trollGenerator(const int&);
};

Primes1000::Primes1000() {
    generate(100000);
    trollGenerator(10000);
}
void Primes1000::generate(const int& n) {//My Super Duper Siver :P
    int p=2;
    numbers[0]=numbers [1]=false;
    numbers[2]=true;
    for(int i=3; i<=n; i+=2)
        numbers[i]=true;
    while(p!=n) {
        for(int i=2; i<=(n/p); ++i)
            numbers[i*p]=false;
        ++p;
    }
//    for(int i=2; i<=n ; ++i)
//        if(numbers[i]==true) primes.push_back(i);
}

bool Primes1000::isPrime(const int& n) {
    if(n<100000) return numbers [n];
    if(n%2 == 0)    return false;
    for(int i=3; i*i<=n; i+=2) //escapes 2 which is handlend
    if(n % i == 0)  return false;
    return true;
}

void Primes1000::trollGenerator(const int&n) {
    for(int i=0; i<=n; ++i)
        flag[i] = isPrime(i*i + i + 41);
}
int main() {
    Primes1000 myprimer;
    int n,m,count;
    while(scanf("%d%d",&n, &m)!=EOF) {
        count=0;
        for(int i=n; i<=m; ++i)
            if(myprimer.flag[i])
                ++count;
        printf("%.2lf\n",(count*100.0)/(m-n+1) + 1e-5);
    }
    return 0;
}
