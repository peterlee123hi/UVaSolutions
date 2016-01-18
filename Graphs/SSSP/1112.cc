#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
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

int n,e,t,m;
vector<vii> AdjList;

void reset() {
	scanf("%d %d %d %d",&n,&e,&t,&m); e--;
	AdjList.assign(n,vii(0));
	REP(i,0,m) {
		int u,v,w; scanf("%d %d %d",&u,&v,&w); u--; v--;
		AdjList[u].PB(ii(v,w));
	}
}

int sssp(int init) {
	vi dist(n,INF); dist[init]=0;
	priority_queue< ii,vii,greater<ii> > pq; pq.push(ii(0,init));
	while(!pq.empty()) {
		ii node=pq.top(); pq.pop();
		int u=node.SE,d=node.FI;
		if(d>dist[u]) continue;
		REP(j,0,SZ(AdjList[u])) {
			ii e=AdjList[u][j];
			int v=e.FI,w=e.SE;
			if(w+dist[u]<dist[v]) {
				dist[v]=w+dist[u];
				pq.push(ii(dist[v],v));
			}
		}
	} return dist[e];
}

int main() {
	int T,CN=1; scanf("%d",&T);
	while(T--) {
		if(CN>1) printf("\n");
		reset();
		int ans=0;
		REP(i,0,n)
			if(sssp(i)<=t) ans++;
		printf("%d\n",ans); CN++;
	}
	exit(0);
}
