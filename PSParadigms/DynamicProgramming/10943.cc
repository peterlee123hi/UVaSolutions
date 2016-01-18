#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#define REP(i,a,n) for(int i=a;i<n;i++)

int memo[105][105];

void reset() {
	memset(memo,-1,sizeof memo);
}

int backtrack(int n, int k) {
	if(n==0&&k==0) return 1;
	if(n<0||k<0) return 0;

	int &ans=memo[n][k];
	if(ans!=-1) return ans;

	ans=0;
	REP(i,0,n+1) {
		ans+=backtrack(n-i,k-1);
		ans%=1000000;
	} return ans;
}

int main() {
	int n,k;
	while(scanf("%d %d",&n,&k),n||k) {
		reset();
		printf("%d\n",backtrack(n,k));
	} exit(0);
}
