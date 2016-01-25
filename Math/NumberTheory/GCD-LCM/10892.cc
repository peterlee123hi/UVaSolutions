#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef vector<int> vi;
#define REP(i,a,n) for(int i=a;i<n;i++)
#define PB push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()

int gcd(int a,int b) { return (b==0)?a:gcd(b,a%b); }
int lcm(int a,int b) { return a*(b/gcd(a,b)); }

int n;
vi divisors;

void reset() {
	divisors.clear();
}

void load() {
	int l=(int)floor(sqrt(n)+1);
	REP(i,1,l)
		if(n%i==0) {
			divisors.PB(i);
			if(i!=n/i) divisors.PB(n/i);
		}
	sort(ALL(divisors));
	//DEBUG
	//REP(i,0,SZ(divisors)) printf("%d ",divisors[i]); printf("\n");
}

int count() {
	int ans=0;
	REP(i,0,SZ(divisors)) REP(j,i,SZ(divisors))
		if(lcm(divisors[i],divisors[j])==n) {
			//DEBUG
			//printf("(%d, %d)\n",divisors[i],divisors[j]);
			ans++;
		}
	return ans;
}

int main() {
	while(scanf("%d",&n),n) {
		reset();
		load();
		printf("%d %d\n",n,count());
	}
}
