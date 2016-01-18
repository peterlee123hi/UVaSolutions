#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
#define REP(i,a,n) for(int i=a;i<n;i++)

int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		int n;
		ll total=0;
		scanf("%d",&n);
		REP(i,0,n) {
			ll a,b,c,p;
			scanf("%lld %lld %lld",&a,&b,&c);
			total+=a*c;
		} printf("%lld\n",total);
	}
}
