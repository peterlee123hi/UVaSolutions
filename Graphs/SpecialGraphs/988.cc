#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef vector<int> vi;
#define REP(i,a,n) for(int i=a;i<n;i++)
#define PB push_back
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())

int n;
vector<vi> events;

void reset() {
	events.assign(n,vi(0));
}

int numPaths(int i) {
	int ans=0;
	REP(j,0,SZ(events[i])) ans+=(events[i][j]==0)?1:numPaths(events[i][j]);
	return ans;
}

int main() {
	int C=1;
	while(scanf("%d",&n)!=EOF) {
		reset();
		if(C++>1) printf("\n");
		REP(i,0,n) {
			int l; scanf("%d",&l);
			REP(j,0,l) {
				int e; scanf("%d",&e);
				events[i].PB(e);
			}
			if(l==0) events[i].PB(0);
		}

		printf("%d\n",numPaths(0));
	}
	exit(0);
}
