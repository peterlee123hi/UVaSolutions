#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define REP(i,a,n) for(int i=a;i<n;i++)

int main() {
	int n,k;
	while(scanf("%d %d",&n,&k)!=EOF) {
		int ans=n;
		while(n>=k) {
			ans+=n/k;
			n=(n/k)+(n%k);
		}
		printf("%d\n",ans);
	} exit(0);
}
