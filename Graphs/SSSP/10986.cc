#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
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

struct state {
	int u,d;
	state(int u,int d) { this->u=u; this->d=d; } };
bool operator<(const state& a,const state& b) { return a.d>b.d; }

int n,m,s,t;
vector<vii> AdjList;

void reset() {
	scanf("%d %d %d %d",&n,&m,&s,&t);
	AdjList.clear();
	AdjList.assign(n,vii(0));
}

int sssp() {
	vi dist; dist.assign(n,INF); dist[s]=0;
	priority_queue<state> pq; pq.push(state(s,0));
	while(!pq.empty()) {
		state p=pq.top(); pq.pop();
		if(p.d>dist[p.u]) continue;
		REP(j,0,SZ(AdjList[p.u])) {
			ii e=AdjList[p.u][j];
			if(p.d+e.SE<dist[e.FI]) {
				dist[e.FI]=p.d+e.SE;
				pq.push(state(e.FI,dist[e.FI]));
			}
		}
	} return dist[t];
}

int main() {
	int T, C=1;
	scanf("%d",&T);
	while(T--) {
		reset();
		REP(i,0,m) {
			int u,v,w;
			scanf("%d %d %d",&u,&v,&w);
			AdjList[u].PB(MP(v,w));
			AdjList[v].PB(MP(u,w));
		}

		int d=sssp();
		if(d==INF) printf("Case #%d: unreachable\n",C++);
		else printf("Case #%d: %d\n",C++,d);
	}
	exit(0);
}
