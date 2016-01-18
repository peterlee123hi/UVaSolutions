#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define REP(i,a,n) for(int i=a;i<n;i++)

int sum(int x) {
	int ans=0;
	while(x>0) {
		ans+=x%10;
		x/=10;
	} return ans;
}

int main() {
	int n;
	while(scanf("%d",&n),n) {
		int ans=n;
		while(ans>=10) ans=sum(ans);
		printf("%d\n",ans);
	}
}
