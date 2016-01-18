#include <cstdio>
#include <vector>
#include <map>
using namespace std;
typedef vector<int> vi;
#define PB push_back
#define SZ(x) ((int)(x).size())
#define REP(i,a,n) for(int i=a;i<n;i++)

int main() {
	int n,m;
	while(scanf("%d %d",&n,&m)!=EOF) {
		map<int, vi> AdjList;
		REP(i,0,n) {
			int e; scanf("%d",&e);
			AdjList[e].PB(i);
		}
		REP(i,0,m) {
			int k,v; scanf("%d %d",&k,&v);
			printf("%d\n",(k-1<SZ(AdjList[v]))?AdjList[v][k-1]+1:0);
		}
	}
}
