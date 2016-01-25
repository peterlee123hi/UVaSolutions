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
#define SZ(x) ((x).size())
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

ll n;
ll numPF(ll n) {
	ll PF_idx=0,PF=primes[PF_idx],ans=0;
	while(PF*PF<=n) {
		bool b=false;
		while(n%PF==0) n/=PF,b=true;
		if(b) ans++;
		PF=primes[++PF_idx];
	}
	if(n!=1) ans++;
	return ans;
}

int main() {
	sieve(10000000);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	while(scanf("%lld",&n),n) {
		printf("%lld : %lld\n",n,numPF(n));
	} exit(0);
}
