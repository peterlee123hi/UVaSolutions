#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define REP(i,a,n) for(int i=a;i<n;i++)
#define PB push_back
#define MP make_pair
#define SZ(x) ((int)(x).size())
#define FI first
#define SE second

int r,c,n,m,even=0,odd=0;
bool water[100][100];
bool visited[100][100];

int dr[] = {-1,1,1,-1};
int dc[] = {-1,1,-1,1};

int dr2[] = {-1,0,1,0};
int dc2[] = {0,1,0,-1};

bool inbounds(int x, int y) { return 0<=x&&x<r&&0<=y&&y<c; }

bool valid(int x, int y) {
	return inbounds(x,y)&&!water[x][y];
}

void load() {
	REP(i,0,100) REP(j,0,100)
		water[i][j]=visited[i][j]=false;
}

void dfs(int x, int y) {
	if(!valid(x,y)) return;
	if(visited[x][y]) return;
	visited[x][y]=true;
	int neighbors=0;

	if(n==m) {
		REP(i,0,4)
			if(valid(x+dr[i]*n,y+dc[i]*m)) {
				neighbors++;
				dfs(x+dr[i]*n,y+dc[i]*m);
			}
	}
	else if(n==0) {
		REP(i,0,4)
			if(valid(x+dr2[i]*m,y+dc2[i]*m)) {
				neighbors++;
				dfs(x+dr2[i]*m,y+dc2[i]*m);
			}
	}
	else if(m==0) {
		REP(i,0,4)
			if(valid(x+dr2[i]*n,y+dc2[i]*n)) {
				neighbors++;
				dfs(x+dr2[i]*n,y+dc2[i]*n);
			}
	}
	else {
		REP(i,0,4)
			if(valid(x+dr[i]*n,y+dc[i]*m)) {
				neighbors++;
				dfs(x+dr[i]*n,y+dc[i]*m);
			}
		REP(i,0,4)
			if(valid(x+dr[i]*m,y+dc[i]*n)) {
				neighbors++;
				dfs(x+dr[i]*m,y+dc[i]*n);
			}
	}

	if(neighbors%2==0) even++;
	else odd++;
}

int main() {
	int TC,w,CN=1;
	scanf("%d",&TC);
	while(TC--) {
		load();
		scanf("%d %d %d %d %d",&r,&c,&n,&m,&w);
		REP(i,0,w) {
			int x,y;
			scanf("%d %d",&x,&y);
			water[x][y]=true;
		}

		dfs(0,0);
		printf("Case %d: %d %d\n",CN++,even,odd);
		even=odd=0;
	}
	exit(0);
}
