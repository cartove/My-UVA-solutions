#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#define MAX 18409201

int* MarkingArrayIsPrime;
int* PairdPrimesArray;

void make(const int &upperBound) {
    int j,i;
    for (j = 2; 2 * j < upperBound; j++)
        MarkingArrayIsPrime[2 * j] = 1;
    for (i = 3; (j = i * i) < upperBound; i += 2)
        if (!MarkingArrayIsPrime[i])
            for (; j <upperBound; j += i + i)
                MarkingArrayIsPrime[j] = 1;
}

void generatePrimesUptoMAX(const int &upperBound) {
    for (int i = 2; i * i <= upperBound; i+=2)
        if (!MarkingArrayIsPrime[i])
            for (int j = i * i; j <= upperBound; j +=i)
                MarkingArrayIsPrime[j] = true;
}

int main() {
    MarkingArrayIsPrime = (int*) malloc((MAX)*sizeof(int));
    make = (int*) malloc((MAX)*sizeof(int));
    generatePrimesUptoMAX(MAX);
    std::cout<<MarkingArrayIsPrime[13];
    return 0;
}
