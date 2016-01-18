#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;
#define REP(i,a,n) for(int i=a;i<n;i++)
#define INF 1000000000
#define PB push_back
#define SZ(x) ((int)(x).size())

int N,x,T,K;
int dimsum[100][2];
int memo[100][25000][25];

int roundup(double n) {
	if(n==(int)n) return (int)n;
	return (int)n+1;
}

int remaining(int cost) {
	int tea_charge=T*(N+1);
	int ans = x*(N+1)-cost-tea_charge-roundup(0.10*(cost+tea_charge));
	return ans;
}

int max_flavor(int id, int cost, int dishes) {
	int &ans=memo[id][cost][dishes];
	if(ans!=-1) return ans;
	else if(remaining(cost)<0) return -INF;
	else if(id==K) return 0;
	else {
		if(dishes<2*(N+1))
			ans=max(ans,dimsum[id][1]+max_flavor(id+1,cost+dimsum[id][0],dishes+1));
		if(dishes<2*(N+1)-1)
			ans=max(ans,2*dimsum[id][1]+max_flavor(id+1,cost+2*dimsum[id][0],dishes+2));
		ans=max(ans,max_flavor(id+1,cost,dishes));
		return ans;
	}
}

int main() {
	vector<double> ans;
	while(scanf("%d %d %d %d",&N,&x,&T,&K),N||x||T||K) {
		memset(memo, -1, sizeof memo);
		REP(i,0,K) {
			scanf("%d", &dimsum[i][0]);
			int sum=0; 
			REP(j,0,N+1) {
				int x;
				scanf("%d",&x);
				sum+=x;
			}
			dimsum[i][1]=sum;
		}

		double avg = (double)max_flavor(0, 0, 0)/(N+1);
		ans.PB(avg);
	}
	REP(i,0,SZ(ans))
		printf("%0.2f\n",ans[i]);
	exit(0);
}
