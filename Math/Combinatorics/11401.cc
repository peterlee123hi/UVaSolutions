#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
typedef unsigned long long ll;
#define REP(i,a,n) for(int i=a;i<n;i++)
/*
struct tri {
	int a,b,c;
	tri(int a,int b,int c) {
		this->a=a; this->b=b; this->c=c;
	}
	bool valid() {
		return a<(b+c)&&b<(a+c)&&c<(a+b);
	}
	bool complete() {
		return a!=-1&&b!=-1&&c!=-1;
	}
};

int n;
int c;

void backtrack(int i,tri t,int side) {
	if(t.complete()) {
		if(t.valid()) c++;
		return;
	}
	if(i>n||side>2) return;
	if(side==0)
		backtrack(i+1,tri(i,t.b,t.c),side+1);
	else if(side==1)
		backtrack(i+1,tri(t.a,i,t.c),side+1);
	else
		backtrack(i+1,tri(t.a,t.b,i),side+1);
	backtrack(i+1,tri(t.a,t.b,t.c),side);
}

int main() {
	while(scanf("%d",&n),n>=3) {
		c=0;
		backtrack(1,tri(-1,-1,-1),0);
		printf("%d\n",c);
	} exit(0);
}
*/

ll memo[1000100];

ll seq(ll i) {
	ll &ans=memo[i];
	if(ans!=-1) return ans;
	ll a=1;
	ll b=1;
	if(i%2==0)
		a=i/2,b=i-1;
	else a=(i-1)/2,b=i;
	return ans=(seq(i-2)+a*b);
}

int main() {
	memset(memo,-1,sizeof memo);
	memo[0]=0; memo[1]=0; memo[2]=1;
	for(int i=100000; i<=1000000; i+=50000) seq(i);
	ll n;
	while(scanf("%llu",&n),n>=3) {
		printf("%llu\n",seq(n-2));
	} exit(0);
}
