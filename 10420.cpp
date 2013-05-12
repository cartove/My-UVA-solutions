#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, int> freq;
    string word;
    char myass[75];
    int cases;
    scanf("%d",&cases);
    while (cases--) {
        cin>>word;
        gets(myass);
        freq[word]++;
    }
    map<string, int>::const_iterator iter;
    for (iter=freq.begin(); iter != freq.end(); ++iter) {
        cout << iter->first << " " << iter->second << endl;
    }
    return 0;
}
