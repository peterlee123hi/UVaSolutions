#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
typedef vector<int> vi;
#define REP(i,a,n) for(int i=a;i<n;i++)
#define PB push_back
#define ALL(x) (x).begin,(x).end()
#define SZ(x) ((int)(x).size())

int n,m;
vector<vi> AdjList;
vi match,vis;

void reset() {
	scanf("%d %d",&n,&m);
	AdjList.assign(n+m,vi(0));
	REP(i,0,n) REP(j,n,n+m) {
		int b; scanf("%d",&b);
		if(b) {
			AdjList[i].PB(j);
			AdjList[j].PB(i);
		}
	}
	match.assign(n+m,-1);
	vis.assign(n,0);
}

int Aug(int l) {
	if(vis[l]) return 0;
	vis[l]=1;
	REP(j,0,SZ(AdjList[l])) {
		int r=AdjList[l][j];
		if(match[r]==-1||Aug(match[r])) {
			match[r]=l; return 1;
		}
	}
	return 0;
}

int main() {
	int T; scanf("%d",&T);
	REP(CN,1,T+1) {
		reset();
		int MCBM=0;
		REP(l,0,n) {
			MCBM+=Aug(l);
			vis.assign(n,0);
		}
		printf("Case %d: a maximum of %d nuts and bolts can be fitted together\n",CN,MCBM);
	}
	exit(0);
}
