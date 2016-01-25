#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define REP(i,a,n) for(int i=a;i<n;i++)
#define SZ(x) ((int)(x).size())
#define PB push_back

ll _sieve_size;
bitset<10000010> bs;
vi primes;

void sieve(ll upperbound) {
	_sieve_size=upperbound+1;
	bs.set();
	bs[0]=bs[1]=0;
	for(ll i=2;i<=_sieve_size;i++)
		if(bs[i]) {
			for(ll j=i*i;j<=_sieve_size;j+=i) bs[j]=0;
			primes.PB(i);
		}
}

ll numPF(ll n) {
	ll PF_idx=0,PF=primes[PF_idx],ans=1;
	while(PF*PF<=n) {
		ll power=0;
		while(n%PF==0) { n/=PF; power++; }
		ans*=power+1;
		PF=primes[++PF_idx];
	} 
	if(n!=1) ans*=2;
	return ans;
}

ll l,u,best,bestD;

void reset() {
	scanf("%lld %lld",&l,&u);
	best=bestD=0;
}

void calc() {
	for(ll n=l;n<=u;n++) {
		ll x=numPF(n);
		if(x>bestD)
			best=n,bestD=x;
	}
}

int main() {
	sieve(10000000);
	int T; scanf("%d",&T);
	while(T--) {
		reset();
		calc();
		printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n",l,u,best,bestD);
	}
}
