#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#define REP(i,a,n) for(int i=a;i<n;i++)
#define INF 1000000000

int n,m;
int AdjMat[100][100];
int s,d;

void reset() {
	scanf("%d %d",&n,&m);
	REP(i,0,n) REP(j,0,n) AdjMat[i][j]=(i==j)?0:INF;
	REP(i,0,m) {
		int u,v; scanf("%d %d",&u,&v);
		AdjMat[u][v]=1;
		AdjMat[v][u]=1;
	} scanf("%d %d",&s,&d);
}

int warshall() {
	REP(k,0,n) REP(i,0,n) REP(j,0,n)
		AdjMat[i][j]=min(AdjMat[i][j],AdjMat[i][k]+AdjMat[k][j]);
	int ans=0;
	REP(i,0,n) ans=max(ans,AdjMat[s][i]+AdjMat[i][d]);
	return ans;
}

int main() {
	int T,CN=1; scanf("%d",&T);
	while(T--) {
		reset();
		printf("Case %d: %d\n",CN++,warshall());
	}
}
