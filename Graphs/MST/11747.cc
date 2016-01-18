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
		p.assign(n,0); rank.assign(n,0);
		REP(i,0,n) p[i]=i;
	}
	int findSet(int i) { return (p[i]==i)?i:(p[i]=findSet(p[i])); }
	bool isSameSet(int i, int j) { return findSet(i)==findSet(j); }
	void unionSet(int i, int j) {
		if(!isSameSet(i,j)) {
			int x=findSet(i),y=findSet(j);
			if(rank[x]>rank[y]) p[y]=p[x];
			else { p[x]=p[y];
				if(rank[x]==rank[y]) rank[y]++;
			}
		}
	}
};

int n,m;
vector< pair<int,ii> > EdgeList;
vi max_weights;

void reset() {
	EdgeList.clear();
	max_weights.clear();
}

int main() {
	while(scanf("%d %d",&n,&m),n||m) {
		reset();

		REP(i,0,m) {
			int u,v,w;
			scanf("%d %d %d",&u,&v,&w);
			EdgeList.PB(MP(w,ii(u,v)));
		} sort(ALL(EdgeList));

		UnionFind UF(n);
		REP(i,0,m) {
			pair<int,ii> e=EdgeList[i];
			if(!UF.isSameSet(e.SE.FI,e.SE.SE))
				UF.unionSet(e.SE.FI,e.SE.SE);
			else
				max_weights.PB(e.FI);
		}

		int l=SZ(max_weights);
		if(l>0) {
			sort(ALL(max_weights));
			REP(i,0,l)
				printf("%s%d",(i==0)?"":" ",max_weights[i]);
			printf("\n");
		} else {
			printf("forest\n");
		}
	}
	exit(0);
}
