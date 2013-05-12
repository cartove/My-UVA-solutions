#include <queue>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int> > pq;
    register int i, j,N,total;
while(cin>>N){
    if(N==0)return 0;
        for (i=0;i<N;i++){
            int t;
            cin >> t;
            pq.push(t);
        }
        total = 0;
        while(pq.size() > 1) {
            i = pq.top();
            pq.pop();
            j = pq.top();
            pq.pop();
            total += (i+j);
            pq.push(i+j);
        }
        cout << total << endl;
        pq.pop();
    }
    return 0;
}
