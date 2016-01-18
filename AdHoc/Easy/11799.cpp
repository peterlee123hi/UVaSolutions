#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,a,n) for(int i=a;i<n;i++)

int main() {
	int N,cs=1; scanf("%d",&N);
	while(N--) {
		int n, max = 0; scanf("%d",&n);
		while(n--) {
			int s; scanf("%d",&s);
			if(s>max) max = s;
		}
		printf("Case %d: %d\n",cs++,max);
	}
	return 0;
}
