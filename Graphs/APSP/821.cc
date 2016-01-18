#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define REP(i,a,n) for(int i=a;i<n;i++)
#define PB push_back
#define MP make_pair
#define ALL(x) (x).begin(),(x).end();
#define SZ(x) ((int)(x).size())
#define FI first
#define SE second
#define INF 1000000000

int AdjMat[100][100];
set<int> n;

void reset() {
	REP(i,0,100) REP(j,0,100)
		AdjMat[i][j]=(i==j)?0:INF;
	n.clear();
}

int sum(int r) {
	int s=0;
	REP(c,0,100)
		if(AdjMat[r][c]!=INF) s+=AdjMat[r][c];
	return s;
}

double warshall() {
	REP(k,0,100) REP(i,0,100) REP(j,0,100)
		AdjMat[i][j]=min(AdjMat[i][j],AdjMat[i][k]+AdjMat[k][j]);

	int clicks=0;
	REP(r,0,100) clicks+=sum(r);
	int l=SZ(n);
	return (double)clicks/(l*(l-1));
}

int main() {
	int u,v,C=1;
	while(scanf("%d %d",&u,&v),u||v) {
		reset();
		do {
			u--; v--;
			n.insert(u); n.insert(v);
			AdjMat[u][v]=1;
		} while(scanf("%d %d",&u,&v),u||v);

		printf("Case %d: average length between pages = %.3f clicks\n",C++,warshall());
	}
	exit(0);
}
