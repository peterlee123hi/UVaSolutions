#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,a,n) for(int i=a;i<n;i++)

int main() {
	int TC,n,m;
	char p;
	scanf("%d",&TC);
	while(TC--) {
		scanf(" %c %d %d",&p,&n,&m);
		if(p=='r')
			printf("%d\n",min(n,m));
		else if(p=='k')
			printf("%d\n",((n+1)/2)*((m+1)/2)+n/2*m/2);
		else if(p=='Q')
			printf("%d\n",min(n,m));
		else if(p=='K')
			printf("%d\n",((n+1)/2)*((m+1)/2));
	}
	return 0;
}
