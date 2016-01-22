#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<pll> vll;
#define REP(i,a,n) for(auto i=a;i<n;i++)
#define REPX(i,a,n,x) for(auto i=a;i<n;i+=x)
#define PB push_back
#define MP make_pair
#define SZ(x) ((ll)(x).size())
#define FI first
#define SE second

ll _sieve_size;
bitset<20000100> bs;
vll pprimes;

void sieve(ll upper_bound) {
	_sieve_size=upper_bound+1;
	bs.set();
	bs[0]=bs[1]=0;
	REP(i,2,_sieve_size) {
		if(bs[i]) {
			REPX(j,i+i,_sieve_size,i) {
				if(j<0) break;
				bs[j]=0;
			}
			if(bs[i-2])
				pprimes.PB(MP(i-2,i));
		}
	}
}

int main() {
	sieve(20000000);
	ll n;
	while(scanf("%lld",&n)!=EOF) {
		printf("(%lld, %lld)\n",pprimes[n-1].FI,pprimes[n-1].SE);
	} exit(0);
}
