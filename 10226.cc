#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <map>
using namespace std;
int main() {
    char tree[100],a[1000000];

	register int total,cases;
    gets(a);
	cases=atoi(a);
	gets(a);
    while (cases--) {
	map<string,int> mp;
    map<string,int>::iterator itt;
		total=0;
        while(gets(tree)&&strlen(tree)) {
        	++mp[string(tree)];
			++total;
        }
        for (itt=mp.begin(); itt!=mp.end(); itt++)
            cout <<itt->first<<" "<<setprecision(4)<<fixed<<itt->second*100/(double)total<<endl;
        if(total!=(cases-1) && cases!=0) printf("\n");
        tree[0]='\0';
    }
    return 0;
}
