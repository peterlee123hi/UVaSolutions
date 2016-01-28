#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i,a,n) for(ll i=a;i<n;i++)
#define per(i,a,n) for(ll i=n-1;i>=a;i--)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())

ll fact[21];
void loadFact() {
	fact[0]=fact[1]=1;
	rep(i,2,21) fact[i]=i*fact[i-1];
}

ll n;
string s;

void readInput() {
	cin>>s;
	scanf("%lld",&n);
}

void solve() {
	sort(all(s));
	string ans="";
	bool used[s.length()]; memset(used,false,sizeof used);
	per(l,0,s.length()) {
		ll i=1;
		ll c=0;
		while(i*fact[l]<=n&&i<s.length()) i++,c++;
		i--;
		//printf("%lld = %lld(%lld! or %lld) + %lld after %lld iterations\n",n,i,l,fact[l],(n-i*fact[i]<0)?0:n-i*fact[i],c);
		if(c)
			n-=i*fact[l];
		if(n<0) n=0;
		int a=0,b;
		rep(j,0,s.length()) {
			if(a>=i&&!used[j]) {
				b=j; break;
			}
			if(!used[j]) a++;
		}
		used[b]=true;
		ans+=s[b];
		//rep(i,0,s.length()) printf("%s%d",(i==0)?"":" ",used[i]); printf("\n");
	}
	s=ans;
}

void output() {
	cout<<s<<endl;
}

int main() {
	loadFact();
	int T; scanf("%d",&T);
	while(T--) {
		readInput();
		solve();
		output();
	} exit(0);
}
