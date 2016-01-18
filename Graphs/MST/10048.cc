#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
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

class UnionFind {
private: vi p,rank;
public:
	UnionFind(int n) {
		p.assign(n,0);
		rank.assign(n,0);
		REP(i,0,n) p[i]=i;
	}
	int findSet(int i) { return (p[i]==i)?i:(p[i]=findSet(p[i])); }
	bool isSameSet(int i, int j) { return findSet(i)==findSet(j); }
	void unionSet(int i, int j) {
		if(!isSameSet(i,j)) {
			int x=findSet(i), y=findSet(j);
			if(rank[x]<rank[y]) p[x]=p[y];
			else { p[y]=p[x];
				if(rank[x]==rank[y]) { rank[x]++; }
			}
		}
	}
};

int c,s,q;
vector< pair<int,ii> > EdgeList;
vector<vii> MST;
bool visited[100];

void reset() {
	EdgeList.clear();
	MST.assign(c,vii(0));
	memset(visited,false,sizeof visited);
}

int dfs(int u, int dest, int max_edge) {
	if(visited[u]) return 0;
	visited[u]=true;
	if(u==dest) return max_edge;

	int best=0;
	REP(j,0,SZ(MST[u])) {
		ii v=MST[u][j];
		best=max(best,dfs(v.FI,dest,max(max_edge,v.SE)));
	}
	return best;
}

int main() {
	int CN=1;
	while(scanf("%d %d %d",&c,&s,&q),c||s||q) {
		if(CN>1) printf("\n");
		reset();

		REP(i,0,s) {
			int c1,c2,w;
			scanf("%d %d %d",&c1,&c2,&w);
			EdgeList.PB(MP(w,ii(c1-1,c2-1)));
		} sort(ALL(EdgeList));

		int edge_count=0;
		UnionFind UF(c);
		REP(i,0,s) {
			pair<int,ii> e=EdgeList[i];
			if(!UF.isSameSet(e.SE.FI,e.SE.SE)) {
				edge_count++;
				UF.unionSet(e.SE.FI,e.SE.SE);
				MST[e.SE.FI].PB(ii(e.SE.SE,e.FI));
				MST[e.SE.SE].PB(ii(e.SE.FI,e.FI));
			}
			if(edge_count==c-1) break;
		}

		printf("Case #%d\n",CN++);
		REP(i,0,q) {
			int c1,c2;
			scanf("%d %d",&c1,&c2);
			memset(visited,false,sizeof visited);
			
			int max_edge=dfs(c1-1,c2-1,0);
			if(visited[c2-1])
				printf("%d\n",max_edge);
			else
				printf("no path\n");
		}
	}
	exit(0);
}
