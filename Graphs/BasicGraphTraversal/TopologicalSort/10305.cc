#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define REP(i,a,n) for(int i=a;i<n;i++)
#define PER(i,a,n) for(int i=n-1;i>=a;i--)
#define PB push_back
#define MP make_pair
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define FI first
#define SE second

int main() {
	int n,m;
	while(scanf("%d %d",&n,&m),n) {
		int incoming_degree[n] = {};
		vi ts;
		queue<int> q;
		vector<vii> AdjList(n,vii(0));

		REP(i,0,m) {
			int a,b;
			scanf("%d %d",&a,&b); a--; b--;
			AdjList[a].PB(MP(b,0));
			incoming_degree[b]++;
		}
		REP(u,0,n)
			if(incoming_degree[u]==0)
				q.push(u);

		while(!q.empty()) {
			int u=q.front(); q.pop();
			ts.PB(u);
			REP(j,0,SZ(AdjList[u])) {
				ii v=AdjList[u][j];
				incoming_degree[v.FI]--;
				if(incoming_degree[v.FI]==0)
					q.push(v.FI);
			}
		}

		REP(i,0,SZ(ts))
			printf("%s%d",(i==0)?"":" ",ts[i]+1);
		printf("\n");
	}
	exit(0);
}
