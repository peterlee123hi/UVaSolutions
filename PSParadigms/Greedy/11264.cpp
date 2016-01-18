#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,a,n) for(int i=a;i<n;i++)
#define PER(i,a,n) for(int i=n-1;i>=a;i--)

int main() {
	int TC, n;
	int* coins;
	scanf("%d",&TC);
	while(TC--) {
		scanf("%d",&n);
		coins = new int[n];
		REP(i,0,n) {
			int d;
			scanf("%d",&d);
			coins[i]=d;
		}

		int sum=coins[0], ans=1;

		REP(i,1,n-1)
			if(sum+coins[i]<coins[i+1]) {
				sum+=coins[i];
				ans++;
			}

		printf("%d\n",ans+1);
 	}
 	return 0;
}
