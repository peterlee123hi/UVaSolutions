#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define REP(i,a,n) for(int i=a;i<n;i++)

int main() {
	int T,CN=1; scanf("%d",&T);
	while(T--) {
		int d,v,u; scanf("%d %d %d",&d,&v,&u);
		if(u>v&&v) {
			double shortest=d/sqrt(u*u-v*v);
			double fastest=(double)d/u;
			printf("Case %d: %.3f\n",CN++,abs(shortest-fastest));
		} else {
			printf("Case %d: can't determine\n",CN++);
		}
	} exit(0);
}
