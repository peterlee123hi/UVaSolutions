#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#define REP(i,a,n) for(int i=a;i<n;i++)

int c[100];

int cat(int n) {
	int &ans=c[n];
	if(ans!=-1) return ans;
	return ans=((2*(2*n-1)*cat(n-1))/(n+1));
}

int main() {
	memset(c,-1,sizeof c);
	c[0]=1;

	int n,CN=1;
	while(scanf("%d",&n)!=EOF) {
		if(CN++>1) printf("\n");
		printf("%d\n",cat(n));
	} exit(0);
}
