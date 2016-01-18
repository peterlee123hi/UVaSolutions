#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define REP(i,a,n) for(int i=a;i<n;i++)

int main() {
	int T,CN=1;
	scanf("%d",&T);
	while(T--) {
		int n,high=0,low=0;
		scanf("%d",&n);
		int jumps[n];
		REP(i,0,n) scanf("%d",&jumps[i]);
		REP(i,1,n)
			if(jumps[i]>jumps[i-1]) high++;
			else if(jumps[i]<jumps[i-1]) low++;
		printf("Case %d: %d %d\n",CN++,high,low);
	}
}
