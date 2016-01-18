#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef vector<int> vi;
#define REP(i,a,n) for(int i=a;i<n;i++)
#define PB push_back
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define INF 1000000000

int res[110][110],mf,f,s,t,m,w;
vi p;

int v_out(int v) { return v+m; }

void reset() {
	memset(res,0,sizeof res);
	mf=f=s=0; t=m-1;
	p.assign(m,-1);
}

void augment(int v,int minEdge) {
	if(v==s) { f=minEdge; return; }
	else if(p[v]!=-1) {
		augment(p[v],min(minEdge,res[p[v]][v]));
		res[p[v]][v]-=f; res[v][p[v]]+=f;
	}
}

void karp() {
	do {
		f=0;
		vi dist(2*m,INF); dist[s]=0;
		queue<int> q; q.push(s);
		p.assign(2*m,-1);

		while(!q.empty()) {
			int u=q.front(); q.pop();
			if(u==t) break;
			REP(v,0,2*m) {
				if(res[u][v]>0&&dist[v]==INF)
					dist[v]=dist[u]+1,q.push(v),p[v]=u;
			}
		}
		augment(t,INF);
		mf+=f;
	} while(f>0);
}

int main() {
	while(scanf("%d %d",&m,&w),m||w) {
		reset();
		res[0][v_out(0)]=INF; res[m-1][v_out(m-1)]=INF;
		REP(i,0,m-2) {
			int v,w; scanf("%d %d",&v,&w);
			v--;
			res[v][v_out(v)]=w;
		}
		REP(i,0,w) {
			int u,v,w; scanf("%d %d %d",&u,&v,&w);
			u--; v--;
			res[v_out(u)][v]=w; res[v_out(v)][u]=w;
		}
		karp();
		printf("%d\n",mf);
	}
	exit(0);
}
