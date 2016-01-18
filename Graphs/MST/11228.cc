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
#define MP make_pair
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define FI first
#define SE second
#define INF 1000000000

class UnionFind {
private: vi p,rank;
public:
	UnionFind(int n) {
		p.assign(n,0); rank.assign(n,0);
		REP(i,0,n) p[i]=i;
	}
	int findSet(int i) { return (p[i]==i)?i:p[i]=findSet(p[i]); }
	bool isSameSet(int i,int j) { return findSet(i)==findSet(j); }
	void unionSet(int i,int j) {
		if(!isSameSet(i,j)) {
			int x=findSet(i),y=findSet(j);
			if(rank[x]<rank[y]) p[x]=p[y];
			else {
				p[y]=p[x];
				if(rank[x]==rank[y]) rank[x]++;
			}
		}
	}
};

int n,r,s;
double a,b;
vector< pair<double,ii> > EdgeList;

int reset() {
	scanf("%d %d",&n,&r);
	s=1; a=b=0;
	EdgeList.clear();
	vii cities;
	REP(i,0,n) {
		int x,y; scanf("%d %d",&x,&y);
		cities.PB(ii(x,y));
	}
	REP(i,0,n) REP(j,0,n)
		if(i!=j) {
			double dx=cities[i].FI-cities[j].FI,dy=cities[i].SE-cities[j].SE;
			EdgeList.PB(MP(hypot(dx,dy),ii(i,j)));
		}
}

void kruskal() {
	UnionFind uf(n);
	sort(ALL(EdgeList));
	REP(i,0,SZ(EdgeList)) {
		pair<double,ii> e=EdgeList[i];
		double w=e.FI; int u=e.SE.FI,v=e.SE.SE;
		if(!uf.isSameSet(u,v)) {
			if(w>r) s++,b+=w;
			else a+=w;
			uf.unionSet(u,v);
		}
	}
}

int main() {
	int T,CN=1; scanf("%d",&T);
	while(T--) {
		reset();
		kruskal();
		printf("Case #%d: %d %d %d\n",CN++,s,(int)round(a),(int)round(b));
	}
	exit(0);
}
