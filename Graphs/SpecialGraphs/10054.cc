#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <list>
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

int n;
vector<vii> AdjList;
vii tour;

void reset() {
	scanf("%d",&n);
	AdjList.assign(50,vii(0));
	tour.clear();
}

bool EulerianCheck() {
	REP(i,0,SZ(AdjList))
		if(SZ(AdjList[i])%2) return false;
	return true;
}

void EulerianTour(int i,int u) {
	REP(j,0,SZ(AdjList[u])) {
		ii &v=AdjList[u][j];
		if(v.SE) {
			v.SE=0;
			REP(k,0,SZ(AdjList[v.FI])) {
				ii &uu=AdjList[v.FI][k];
				if(uu.FI==u&&uu.SE) {
					uu.SE=0;
					break;
				}
			}
			tour.insert(tour.begin()+i,ii(u,v.FI));
			EulerianTour(i+1,v.FI);
		}
	}
}

int main() {
	int T,s; scanf("%d",&T);
	REP(CN,1,T+1) {
		if(CN>1) printf("\n");
		reset();
		REP(i,0,n) {
			int a,b; scanf("%d %d",&a,&b); a--; b--; s=a;
			AdjList[a].PB(ii(b,1));
			AdjList[b].PB(ii(a,1));
		}
		printf("Case #%d\n",CN);
		if(EulerianCheck()) {
			EulerianTour(0,s);
			REP(i,0,SZ(tour)) printf("%d %d\n",tour[i].FI+1,tour[i].SE+1);
		} else {
			printf("some beads may be lost\n");
		}
	}
	exit(0);
}
