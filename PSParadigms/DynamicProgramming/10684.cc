#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,a,n) for(int i=a;i<n;i++)

int main() {
	int N;
	while(scanf("%d",&N),N) {
		int sum = 0, x, ans = 0;
		REP(i,0,N) {
			scanf("%d",&x);
			sum += x;
			ans = max(ans, sum);
			if(sum < 0) sum = 0;
		}
		if(ans > 0)
			printf("The maximum winning streak is %d.\n", ans);
		else
			printf("Losing streak.\n");
	}
	exit(0);
}
