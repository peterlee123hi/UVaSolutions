#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,a,n) for(int i=a;i<n;i++)

int main() {
	int n,m;
	while(scanf("%d %d",&n,&m),n,m) {
		int dragons[n],knights[m];
		REP(i,0,n) {
			int x;
			scanf("%d",&x);
			dragons[i]=x;
		}
		REP(i,0,m) {
			int x;
			scanf("%d",&x);
			knights[i]=x;
		}
		sort(dragons,dragons+n);
		sort(knights,knights+m);
		int gold=0,d=0,k=0;
		while(d<n) {
			while(dragons[d]>knights[k]&&k<m) k++;
			if(k==m) break;
			gold+=knights[k++];
			d++;
		}
		if(d==n) printf("%d\n",gold);
		else printf("Loowater is doomed!\n");
	}
	return 0;
}
