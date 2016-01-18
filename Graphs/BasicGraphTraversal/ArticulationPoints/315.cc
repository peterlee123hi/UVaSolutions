#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
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
#define SET(x,s) memset(x,s,sizeof x)

const int UNVISITED=-1;

int n,dfs_counter,dfs_root,rootChildren;
vi dfs_num,dfs_low,dfs_parent;
bool critical[100];
vector<vii> AdjList;

void reset(int n) {
	dfs_counter=dfs_root=rootChildren=0;
	dfs_num.assign(n,UNVISITED); dfs_low.assign(n,0); dfs_parent.assign(n,0);
	SET(critical,false);
	AdjList.assign(n,vii(0));
}

int countCritical() {
	int ans=0;
	REP(i,0,n) if(critical[i]) ans++;
	return ans; 
}

void dfs(int u) {
	dfs_num[u]=dfs_low[u]=dfs_counter++;
	REP(j,0,SZ(AdjList[u])) {
		ii v=AdjList[u][j];
		if(dfs_num[v.FI]==UNVISITED) {
			dfs_parent[v.FI]=u;
			if(u==dfs_root) rootChildren++;
			dfs(v.FI);
			if(dfs_low[v.FI]>=dfs_num[u]) critical[u]=true;
			dfs_low[u]=min(dfs_low[u],dfs_low[v.FI]);
		} else if(v.FI!=dfs_parent[u])
			dfs_low[u]=min(dfs_low[u],dfs_num[v.FI]);
	}
}

int main() {
	while(scanf("%d",&n),n) {
		reset(n);

		int u,v;
		char c;
		while(scanf("%d",&u),u) {
			do {
				scanf("%d%c",&v,&c);
				AdjList[u-1].PB(MP(v-1,0));
				AdjList[v-1].PB(MP(u-1,0));
			} while(c!='\n');
		}

		REP(u,0,n)
			if(dfs_num[u]==UNVISITED) {
				dfs_root=u; rootChildren=0;
				dfs(u);
				critical[dfs_root]=(rootChildren>1);
			}

		//DEBUG
		/*
		REP(i,0,n) {
			printf("%d:",i);
			REP(j,0,SZ(AdjList[i]))
				printf(" %d",AdjList[i][j].FI);
			printf("\n");
		}
		printf("DFS_NUM:");
		REP(i,0,n) printf(" %d",dfs_num[i]); printf("\n");
		printf("DFS_LOW:");
		REP(i,0,n) printf(" %d",dfs_low[i]); printf("\n");
		printf("CRITICAL:");
		REP(i,0,n) printf(" %d",critical[i]); printf("\n");
		*/
		//END DEBUG

		printf("%d\n",countCritical());
	}
	exit(0);
}
