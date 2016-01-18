#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#define REP(i,a,n) for(int i=a;i<n;i++)
#define SZ(x) ((int)(x).size())
#define INF 1000000000

int grid[75][75],n,k;
bool reached;
int memo[75][75][6][3];
bool memoC[75][75][6][3];

void reset() {
	REP(i,0,n) REP(j,0,n) scanf("%d",&grid[i][j]);
	reached=false;
	REP(i,0,n) REP(j,0,n) REP(k,0,6) REP(x,0,3) memo[i][j][k][x]=memoC[i][j][k][x]=0;
}

bool inbounds(int i, int j) { return 0<=i&&i<n&&0<=j&&j<n; }
bool valid(int i, int j, int left) { return inbounds(i,j)&&left>=0; }

int backtrack(int i, int j, int left, int stat) {
	if(grid[i][j]<0) left--;
	if(left<0) return -INF;
	if(i==n-1&&j==n-1) {
		reached=true;
		return grid[i][j];
	}

	int &ans=memo[i][j][left][stat];
	if(memoC[i][j][left][stat]) return ans;
	
	int best=-INF;
	if(valid(i+1,j,left))
		best=max(best,backtrack(i+1,j,left,0));
	if(stat!=2&&valid(i,j-1,left))
		best=max(best,backtrack(i,j-1,left,1));
	if(stat!=1&&valid(i,j+1,left))
		best=max(best,backtrack(i,j+1,left,2));
	
	memoC[i][j][left][stat]=true;
	return ans=(grid[i][j]+best);
}

int main() {
	int CN=1;
	while(scanf("%d %d",&n,&k),n||k) {
		reset();
		int ans=backtrack(0,0,k,0);
		if(reached) printf("Case %d: %d\n",CN++,ans);
		else printf("Case %d: impossible\n",CN++);
	}
	exit(0);
}
