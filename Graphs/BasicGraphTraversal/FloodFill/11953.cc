#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,a,n) for(int i=a;i<n;i++)

int n;
char grid[100][100];

int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};

bool inbounds(int x, int y) { return 0<=x&&x<n&&0<=y&&y<n; }

void floodfill(int x, int y) {
	if(!inbounds(x,y)||grid[x][y]=='.') return;
	grid[x][y]='.';
	REP(d,0,4)
		floodfill(x+dr[d],y+dc[d]);
}

int main() {
	int T,CN=1;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		REP(i,0,n) REP(j,0,n)
			scanf(" %c",&grid[i][j]);

		int ans=0;
		REP(i,0,n) REP(j,0,n)
			if(grid[i][j]=='x') {
				ans++;
				floodfill(i,j);
			}

		printf("Case %d: %d\n",CN++,ans);
	}
	exit(0);
}
