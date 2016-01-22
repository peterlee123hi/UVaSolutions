#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#define REP(i,a,n) for(int i=a;i<n;i++)

int memo[100];

int backtrack(int n) {
	int &ans=memo[n];
	if(ans!=-1) return ans;
	if(n<0) return ans=0;
	if(n<=1) return ans=1;
	if(n<=3) return ans=2;
	return ans=backtrack(n-2)+backtrack(n-3);
}

int main() {
	memset(memo,-1,sizeof memo);
	int n;
	while(scanf("%d",&n)!=EOF)
		printf("%d\n",backtrack(n));
}
