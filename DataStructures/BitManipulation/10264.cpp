#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
#define REP(i,a,n) for(int i=a;i<n;i++)

int N,max_sum,corners[20000],sums[20000];

bool neighboring(int a, int b) {
	REP(i,0,N)
		if((a^(1<<i))==b) {
			return true;
		}
	return false;
}

int main() {
	while(scanf("%d",&N)!=EOF) {
		int numOfCorners=pow(2,N);
		max_sum=0;
		REP(i,0,numOfCorners) {
			scanf("%d",&corners[i]);
		}
		REP(i,0,numOfCorners) {
			int sum=0;
			REP(j,0,N) {
				int b=i^(1<<j);
				sum+=corners[b];
			}
			sums[i]=sum;
		}
		REP(i,0,numOfCorners) {
			REP(j,0,N) {
				int b=i^(1<<j);
				max_sum=max(max_sum,sums[i]+sums[b]);
			}
		}
		printf("%d\n",max_sum);
	}
	return 0;
}
