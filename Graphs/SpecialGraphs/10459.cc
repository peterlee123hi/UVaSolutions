#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
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

int n,d;
vector<vi> AdjList;
vi best,worst,visited;

void reset() {
	d=1;
	AdjList.assign(n,vi(0));
	best.clear(); worst.clear();
	visited.assign(n,0);
}

void output() {
	sort(ALL(best));
	sort(ALL(worst));
	printf("Best Roots  :"); 
	REP(i,0,SZ(best)) printf(" %d",best[i]+1);
	printf("\nWorst Roots :"); 
	REP(i,0,SZ(worst)) printf(" %d",worst[i]+1);
	printf("\n");
}

bool mid(int i) {
	if(d%2) return i==d/2||i==d/2+1;
	else return i==d/2;
}

bool dfs(int u,int dist) {
	if(visited[u]) return false;
	visited[u]=1;
	if(dist==d) return true;
	bool is_mid=false,on_path=false;
	REP(j,0,SZ(AdjList[u])) {
		on_path|=dfs(AdjList[u][j],dist+1);
	} is_mid=on_path&mid(dist);
	if(is_mid) {
		best.PB(u);
	}
	return on_path;
}

void diameter() {
	int f;
	queue<ii> q;
	q.push(ii(0,0));
	while(!q.empty()) {
		ii u=q.front(); q.pop();
		if(visited[u.SE]) continue;
		visited[u.SE]=1;
		if(u.FI>=d)
			f=u.SE,d=u.FI;
		REP(j,0,SZ(AdjList[u.SE]))
			q.push(ii(u.FI+1,AdjList[u.SE][j]));
	} visited.assign(n+1,0);
	q.push(ii(0,f));
	while(!q.empty()) {
		ii u=q.front(); q.pop();
		if(visited[u.SE]) continue;
		visited[u.SE]=1;
		if(u.FI>=d)
			f=u.SE,d=u.FI;
		REP(j,0,SZ(AdjList[u.SE]))
			q.push(ii(u.FI+1,AdjList[u.SE][j]));
	} visited.assign(n,0);
	dfs(f,0); visited.assign(n,0);
	REP(i,0,SZ(best)) {
		vi w; int dist=0;
		q.push(ii(0,best[i]));
		while(!q.empty()) {
			ii u=q.front(); q.pop();
			if(visited[u.SE]) continue;
			visited[u.SE]=1;
			if(u.FI==dist)
				w.PB(u.SE);
			if(u.FI>dist) {
				w.clear(); w.PB(u.SE);
				dist=u.FI;
			}
			REP(j,0,SZ(AdjList[u.SE]))
				q.push(ii(u.FI+1,AdjList[u.SE][j]));
		} visited.assign(n,0);
		REP(j,0,SZ(w)) if(find(ALL(worst),w[j])==worst.end()) worst.PB(w[j]);
	}
}

int main() {
	while(scanf("%d",&n)!=EOF) {
		reset();
		REP(i,0,n) {
			int m; scanf("%d",&m);
			REP(j,0,m) {
				int v; scanf("%d",&v); v--;
				AdjList[i].PB(v);
			}
		}
		diameter();
		output();
	}
	exit(0);
}
