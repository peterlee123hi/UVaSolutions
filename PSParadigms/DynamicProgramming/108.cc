#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,a,n) for(int i=a;i<n;i++)

int main() {
	int n;
	scanf("%d",&n);
	int mat[n][n];

	REP(i,0,n) REP(j,0,n) {
		scanf("%d",&mat[i][j]);
		if(i>0) mat[i][j]+=mat[i-1][j];
		if(j>0) mat[i][j]+=mat[i][j-1];
		if(i>0&&j>0) mat[i][j]-=mat[i-1][j-1];
	}

	int ans=-127*100*100;
	REP(sx,0,n) REP(sy,0,n) {
		REP(ex,sx,n) REP(ey,sy,n) {
			int subrect=mat[ex][ey];
			if(sx>0) subrect-=mat[sx-1][ey];
			if(sy>0) subrect-=mat[ex][sy-1];
			if(sx>0&&sy>0) subrect+=mat[sx-1][sy-1];
			ans=max(ans,subrect);
		}
	}

	printf("%d\n",ans);
	exit(0);
}
