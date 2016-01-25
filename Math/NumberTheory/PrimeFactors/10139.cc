#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <bitset>
#include <string>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
#define REP(i,a,n) for(int i=a;i<n;i++)
#define SZ(x) ((int)(x).size())
#define PB push_back
#define MP make_pair
#define FI first
#define SE second

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

int n,m;
vii mF;
bool d;

void reset() {
	mF.clear();
	d=true;
}

void primeFactors() {
	int x=m;
	int PF_idx=0,PF=primes[PF_idx];
	while(((ll)PF)*PF<=(ll)x) {
		int p=0;
		bool b=false;
		while(x%PF==0) { x/=PF; p++; b=true; }
		if(b) mF.PB(ii(PF,p));
		PF=primes[++PF_idx];
	}
	if(x!=1) mF.PB(ii(x,1));
}

int get_powers(ll n,ll p) {
    ll res=0;
    for(ll power=p;power<=n;power*=p)
        res+=n/power;
    return res;
}

void calc() {
	if(m==0) { return; }
	if(n>=m) return;
	primeFactors();
	REP(i,0,SZ(mF)) {
		if(mF[i].SE>get_powers(n,mF[i].FI)) {
			d=false;
			break;
		}
	}
}

void IO() {
	printf("%d %s %d!\n",m,(d)?"divides":"does not divide",n);
}

int main() {
	sieve(10000000);
	while(scanf("%d %d",&n,&m)!=EOF) {
		reset();
		calc();
		IO();
	} exit(0);
}
