#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
typedef vector<int> vi;
typedef long long ll;
#define REP(i,a,n) for(int i=a;i<n;i++)
#define PB push_back
#define SZ(x) ((int)(x).size())

int high=0;
string memo[110000];
vi queries;

int gcd(int a,int b) { return (a%b==0)?b:gcd(b,a%b); }

int count() {
	ll c=0;
	ll inc=1;
	REP(i,0,high+1) {
		if(c%2) memo[i]=to_string(c)+"/2";
		else memo[i]=to_string(c/2)+"";
		c+=inc; inc++;
	}
}

int main() {
	int T; scanf("%d",&T);
	REP(i,0,T) {
		int x; scanf("%d",&x);
		queries.PB(x-1); high=max(high,x);
	} count();
	REP(CN,1,T+1)
		printf("Case %d: %s\n",CN,memo[queries[CN-1]].c_str());
	exit(0);
}
