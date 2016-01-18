#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define REP(i,a,n) for(int i=a;i<n;i++)
#define PB push_back
#define SZ(x) ((int)(x).size())
#define FI first
#define SE second
#define INF 1000000000

int n,m,d;
vector<vi> AdjList;

void read() {
	scanf("%d",&n);
	AdjList.assign(n,vi(0));
	REP(u,0,n) {
		int m; scanf("%d",&m);
		REP(i,0,m) {
			int v; scanf("%d",&v);
			AdjList[u].PB(v);
		}
	}
}

void bfs(int init) {
	m=d=0;
	vi dist(n,INF); dist[init]=0;
	vi day(n,0);
	queue<ii> q; q.push(ii(init,0));
	while(!q.empty()) {
		ii node=q.front(); q.pop();
		int u=node.FI,l=node.SE;
		day[l]++;
		REP(j,0,SZ(AdjList[u])) {
			int v=AdjList[u][j];
			if(dist[v]==INF) {
				dist[v]=l+1,q.push(ii(v,dist[v]));
			}
		}
	}
	REP(i,0,n)
		if(day[i]>m||(d==0&&day[i]>=m))
			m=day[i],d=i;
}

int main() {
	read();
	int T; scanf("%d",&T);
	while(T--) {
		int q; scanf("%d",&q);
		bfs(q);
		if(d)
			printf("%d %d\n",m,d);
		else
			printf("0\n");
	} exit(0);
}
