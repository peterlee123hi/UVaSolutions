#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define REP(i,a,n) for(int i=a;i<n;i++)
#define PB push_back
#define MP make_pair
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define FI first
#define SE second
#define INF 1000000000

int n,m;
vector<vii> AdjList;

void reset() {
	scanf("%d %d",&n,&m);
	AdjList.clear();
	AdjList.assign(n,vii(0));
}

bool bellmanford() {
	vi dist(n,INF); dist[0]=0;
	REP(i,0,n-1)
		REP(u,0,n)
			REP(j,0,SZ(AdjList[u])) {
				ii v=AdjList[u][j];
				dist[v.FI]=min(dist[v.FI],dist[u]+v.SE);
			}

	REP(u,0,n)
		REP(j,0,SZ(AdjList[u])) {
			ii v=AdjList[u][j];
			if((dist[u]+v.SE)<dist[v.FI])
				return true;
		}
	return false;
}

int main() {
	int T;
	scanf("%d",&T);
	vector<string> ans;
	while(T--) {
		reset();
		REP(i,0,m) {
			int u,v,w;
			scanf("%d %d %d",&u,&v,&w);
			AdjList[u].PB(MP(v,w));
		}
		ans.PB(bellmanford()?"possible":"not possible");
	}
	REP(i,0,SZ(ans)) printf("%s\n",ans[i].c_str());
	exit(0);
}
