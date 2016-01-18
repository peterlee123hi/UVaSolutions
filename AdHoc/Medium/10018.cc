#include <cstdio>
using namespace std;
typedef long long ll;
#define REP(i,a,n) for(int i=a;i<n;i++)

ll n;

ll reverse(ll n) {
	ll ans=0;
	while(n>0) {
		ans=ans*10+n%10;
		n/=10;
	}
	return ans;
} 

int backtrack(int i) {
	if(n==reverse(n)&&i>0)
		return i;
	n=n+reverse(n);
	backtrack(i+1);
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		scanf("%lld",&n);
		int iter=backtrack(0);
		printf("%d %lld\n",iter,n);
	}
}
