#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;
typedef long long ll;
#define REP(i,a,n) for(int i=a;i<n;i++)

ll pascal[55][55];

ll C(ll n,ll k) {
	ll &ans=pascal[n][k];
	if(ans!=-1) return ans;
	if(k==0||k==n) return ans=1;
	return ans=(C(n-1,k-1)+C(n-1,k));
}

string its(ll n) {
	stringstream ss;
	ss<<n;
	return ss.str();
}

int main() {
	memset(pascal,-1,sizeof pascal);
	pascal[0][0]=1;

	int T,CN=1; scanf("%d",&T); getchar();
	while(T--) {
		string a="",b="";
		int p;
		getchar();
		char c=getchar();
		while(c!='+') {
			a+=c;
			c=getchar();
		} c=getchar();
		while(c!=')') {
			b+=c;
			c=getchar();
		} getchar();
		scanf("%d",&p); getchar();

		//printf("a = %s\tb = %s\tp = %d\n\n",a.c_str(),b.c_str(),p);
		string ans="";
		int p1=p,p2=0;
		REP(i,0,1+p) {
			if(i) ans+="+";
			string term;
			ll coef=C(p,i);
			//printf("%d %d %lld %s\n",p,i,coef,its(coef).c_str());
			bool first=false;
			if(coef>1) {
				term+=its(coef);
			}
			if(p1>0) {
				if(coef>1) term+="*";
				term+=a;
				first=true;
				if(p1>1) term+="^"+its(p1);
			}
			if(p2>0) {
				if(coef>1||first) term+="*";
				term+=b;
				if(p2>1) term+="^"+its(p2);
			}
			ans+=term; p1--; p2++;
		}
		printf("Case %d: %s\n",CN++,ans.c_str());
	} exit(0);
}
