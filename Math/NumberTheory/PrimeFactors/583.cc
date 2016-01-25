#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define PB push_back
#define SZ(x) ((int)(x).size())

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
			primes.PB((int)i);
		}
}

int g;
vi factors;

void reset() {
	factors.clear();
}

void primeFactors(ll N) {
	ll PF_idx=0,PF=primes[PF_idx];
	while(PF*PF<=N) {
		while(N%PF==0) { N/=PF; factors.PB(PF); }
		PF=primes[++PF_idx];
	}
	if(N!=1) factors.PB(N);
}

void IO() {
	printf("%d =",g);
	for(int i=0;i<SZ(factors);i++) printf(" %s%d",(i==0)?"":"x ",factors[i]);
	printf("\n");
}

int main() {
	sieve(10000000);
	while(scanf("%d",&g),g) {
		reset();
		if(g<0) factors.PB(-1);
		primeFactors(abs(g));
		IO();
	}
}
