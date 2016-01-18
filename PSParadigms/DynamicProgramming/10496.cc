#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define REP(i,a,n) for(int i=a;i<n;i++)
#define PB push_back
#define MP make_pair
#define SZ(x) ((int)(x).size())
#define FI first
#define SE second
#define INF 1000000000

int d[20][20];
int x,y,sx,sy,n;

int dist(ii a, ii b) { return abs(a.FI-b.FI)+abs(a.SE-b.SE); }

int backtrack(int cur, int visited) {
	if(visited==(1<<(n+1))-1)
		return d[cur][0];
	else {
		int ans=INF;
		REP(i,0,n+1) {
			if((visited&(1<<i))==0) {
				ans=min(ans,d[cur][i]+backtrack(i,visited|(1<<i)));
			}
		}
		return ans;
	}
}

int main() {
	int TC;
	scanf("%d",&TC);
	while(TC--) {
		vii locs;
		scanf("%d %d %d %d %d",&x,&y,&sx,&sy,&n);
		locs.PB(MP(sx,sy));
		REP(i,0,n) {
			int bx,by;
			scanf("%d %d",&bx,&by);
			locs.PB(MP(bx,by));
		}
		REP(i,0,n+1) REP(j,0,n+1)
			d[i][j]=dist(locs[i],locs[j]);
		printf("The shortest path has length %d\n",backtrack(0,1));
	}
	exit(0);
}
