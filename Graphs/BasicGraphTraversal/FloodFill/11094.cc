#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef vector<int> vi;
#define REP(i,a,n) for(int i=a;i<n;i++)
#define PB push_back
#define SZ(x) ((int)(x).size())

int m,n;
char grid[25][25];
char land;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int inbounds(int x, int y) { return 0<=x&&x<m&&0<=y&&y<n; }

int floodfill(int x, int y) {
	if(y==-1) y+=n;
	if(y==n) y-=n;
	if(!inbounds(x,y)) return 0;
	if(grid[x][y]!=land) return 0;
	grid[x][y]=(char)(land+1);
	int l=1;
	REP(d,0,8)
		l+=floodfill(x+dr[d],y+dc[d]);
	return l;
}

int main() {
	vi ans;
	while(scanf("%d %d",&m,&n)!=EOF) {
		REP(i,0,m) REP(j,0,n)
			scanf(" %c",&grid[i][j]);
		int sx,sy;
		scanf("%d %d",&sx,&sy);
		land=grid[sx][sy];
		floodfill(sx,sy);

		int best=0;
		REP(i,0,m) REP(j,0,n)
			best=max(best,floodfill(i,j));

		ans.PB(best);
	}

	REP(i,0,SZ(ans))
		printf("%d\n",ans[i]);
	exit(0);
}
