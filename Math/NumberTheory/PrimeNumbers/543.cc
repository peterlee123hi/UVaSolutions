#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define REP(i,a,n) for(ll i=a;i<n;i++)
#define REPX(i,a,n,x) for(ll i=a;i<n;i+=x)
#define PB push_back
#define SZ(x) ((int)(x).size())

ll _sieve_size;
bitset<1001000> bs;
vll primes;

void sieve(ll upperbound) {
	_sieve_size=upperbound+1;
	bs.set();
	bs[0]=bs[1]=0;
	REP(i,2,_sieve_size) {
		if(bs[i]) {
			REPX(j,i+i,_sieve_size,i) bs[j]=0;
			primes.PB(i);
		}
	}
}

bool isPrime(ll n) {
	if(n<_sieve_size) return bs[n];
	REP(i,0,SZ(primes))
		if(n%primes[i]==0) return false;
	return true;
}

int main() {
	sieve(1001000);
	ll n;
	while(scanf("%lld",&n),n) {
		bool found=false;
		REP(i,0,SZ(primes)) {
			if(primes[i]>=n-1) break;
			if(isPrime(n-primes[i])) {
				printf("%lld = %lld + %lld\n",n,primes[i],n-primes[i]);
				found=true;
				break;
			}
		}
		if(!found) printf("Goldbach's conjecture is wrong.\n");
	} exit(0);
}
