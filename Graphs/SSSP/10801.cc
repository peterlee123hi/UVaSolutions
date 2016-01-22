#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <sstream>
#include <bitset>
#include <queue>
using namespace std;
#define REP(i,a,n) for(int i=a;i<n;i++)
#define INF 1000000000

int n,k;
int T[5],AdjMat[100][100];

void reset() {
	REP(i,0,n) scanf("%d",&T[i]); getchar();
	REP(x,0,100) REP(y,0,100) AdjMat[x][y]=INF;
	REP(i,0,n) {
		string s; getline(cin,s); stringstream ss(s);
		int f,floors[105],count=0;
		while(ss>>f) floors[count++]=f;
		REP(x,0,count) REP(y,x+1,count) {
			int f1=floors[x],f2=floors[y];
			AdjMat[f1][f2]=AdjMat[f2][f1]=min(AdjMat[f1][f2],abs(f2-f1)*T[i]);
		}
	}
}

int sssp() {
	int dist[100];
	REP(i,0,100) dist[i]=INF;
	dist[0]=0;
	bitset<100> b; b.set(0);
	queue<int> q; q.push(0);
	while(!q.empty()) {
		int u=q.front(); q.pop();
		b.set(u,0);
		REP(v,0,100) {
			if(dist[u]+AdjMat[u][v]+60<dist[v]) {
				dist[v]=dist[u]+AdjMat[u][v]+60;
				if(!b[v])
					q.push(v),b.set(v);
			}
		}
	} return dist[k];
}

int main() {
	while(scanf("%d %d",&n,&k)!=EOF) {
		reset();
		int best=sssp();
		if(best==INF) printf("IMPOSSIBLE\n");
		else if(k!=0) printf("%d\n",best-60);
		else printf("0\n");
	} exit(0);
}
