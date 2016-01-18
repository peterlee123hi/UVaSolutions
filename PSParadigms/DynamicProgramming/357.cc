#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
typedef long long ll;
#define REP(i,a,n) for(int i=a;i<n;i++)

int n;
int L=5;
int coins[5];
ll memo[31000][10];

ll count(int rem, int i) {
	ll &ans=memo[rem][i];
	if(ans!=-1) return ans;
	if(rem<0||i>=L) return 0;
	else if(rem==0) return 1;
	else {
		ans = 0;
		if(rem>=coins[i])
			ans += count(rem-coins[i],i);
		ans += count(rem,i+1);
		return ans;
	}
}

int main() {
	coins[0] = 50;
	coins[1] = 25;
	coins[2] = 10;
	coins[3] = 5;
	coins[4] = 1;
	memset(memo, -1, sizeof memo);
	while(scanf("%d",&n)!=EOF) {
		int ans = count(n,0);
		if(ans == 1)
			printf("There is only 1 way to produce %d cents change.\n",n);
		else
			printf("There are %lld ways to produce %d cents change.\n",count(n,0),n);
	}
}
