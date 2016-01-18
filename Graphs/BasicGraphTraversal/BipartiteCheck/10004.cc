#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> ii;
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

int main() {
	int n,l;
	while(scanf("%d",&n),n) {
		scanf("%d",&l);
		vector<vii> AdjList(n,vii(0));
		REP(i,0,l) {
			int u,v;
			scanf("%d %d",&u,&v);
			AdjList[u].PB(MP(v,0));
		}

		queue<int> q; q.push(0);
		vi color(n,INF); color[0]=0;
		bool isBipartite=true;

		while(!q.empty()&&isBipartite) {
			int u=q.front(); q.pop();
			REP(j,0,SZ(AdjList[u])) {
				ii v=AdjList[u][j];
				if(color[v.FI]==INF) {
					color[v.FI]=1-color[u];
					q.push(v.FI);
				} else if(color[u]==color[v.FI]) {
					isBipartite=false;
				}
			}
		}

		printf("%s\n",(isBipartite)?"BICOLORABLE.":"NOT BICOLORABLE.");
	}
	exit(0);
}
