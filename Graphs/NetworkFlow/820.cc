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

int res[100][100],mf,f,n,s,t,c;
vi p;

void reset() {
	memset(res,0,sizeof res);
	mf=f=0;
	scanf("%d %d %d",&s,&t,&c);
	s--; t--;
	p.assign(n,-1);
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
		vi dist(n,INF); dist[s]=0;
		queue<int> q; q.push(s);
		p.assign(n,-1);

		while(!q.empty()) {
			int u=q.front(); q.pop();
			if(u==t) break;
			REP(v,0,n) {
				if(res[u][v]>0&&dist[v]==INF)
					dist[v]=dist[u]+1,q.push(v),p[v]=u;
			}
		}
		augment(t,INF);
		mf+=f;
	} while(f>0);
}

int main() {
	int C=1;
	while(scanf("%d",&n),n) {
		reset();
		REP(i,0,c) {
			int u,v,w; scanf("%d %d %d",&u,&v,&w);
			u--; v--;
			res[u][v]+=w; res[v][u]+=w;
		}

		karp();
		printf("Network %d\nThe bandwidth is %d.\n\n",C++,mf);
	}
	exit(0);
}
