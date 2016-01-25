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
#define PB push_back
#define SZ(x) ((x).size())

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

bool isPrime(ll n) {
	if(n<=_sieve_size) return bs[n];
	REP(i,0,SZ(primes)) if(n%primes[i]==0) return false;
	return true; 
}

ll EulerPhi(ll n) {
	ll PF_idx=0,PF=primes[PF_idx],ans=n;
	while(PF*PF<=n) {
		if(n%PF==0) ans-=ans/PF;
		while(n%PF==0) n/=PF;
		PF=primes[++PF_idx];
	}
	if(n!=1) ans-=ans/n;
	return ans;
}

int main() {
	sieve(10000000);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	ll n;
	while(scanf("%lld",&n),n) {
		printf("%lld\n",EulerPhi(n));
	} exit(0);
}
