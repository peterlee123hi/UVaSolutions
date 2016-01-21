#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#define REP(i,a,n) for(int i=a;i<n;i++)

int n;
int grid[100][100];

bool stable() {
	int count[110]; memset(count,0,sizeof count);
	REP(i,0,n) REP(j,0,n) {
		count[grid[i][j]]++;
		if(count[grid[i][j]]>n) return false;
	} return true;
}

int main() {
	int T,CN=1; scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		REP(i,0,n) REP(j,0,n) {
			scanf("%d",&grid[i][j]);
		}

		printf("Case %d: %s\n",CN++,(stable())?"yes":"no");
	}
}
