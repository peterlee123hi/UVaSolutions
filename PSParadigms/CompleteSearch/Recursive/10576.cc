#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
#define REP(i,a,n) for(int i=a;i<n;i++)

ll s,d,ans;
ll months[12];

void backtrack(ll sum,ll m) {
	if(m==12) { ans=max(ans,sum); return; }
	months[m]=s;
	if(m>5&&months[m]+months[m-1]+
		months[m-2]+months[m-3]+months[m-4]>0)
		return;
	backtrack(sum+s,m+1);
	months[m]=-d;
	if(m>5&&months[m]+months[m-1]+
		months[m-2]+months[m-3]+months[m-4]>0)
		return;
	backtrack(sum-d,m+1);
}

int main() {
	while(scanf("%lld %lld",&s,&d)!=EOF) {
		ans=0; memset(months,0,sizeof months);
		backtrack(0,0);
		if(ans>0) printf("%lld\n",ans); 
		else printf("Deficit\n");
	} exit(0);
}
