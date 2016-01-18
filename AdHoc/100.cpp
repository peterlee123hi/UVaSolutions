#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,a,n) for(int i=a;i<n;i++)

int cycle(int n) {
	if(n==1) return 1;
	else if(n%2==0) return 1+cycle(n/2);
	else return 1+cycle(n*3+1);
}

int main() {
	int i,j;
	while(scanf("%d %d",&i,&j)!=EOF) {
		int ans=0;
		int a=min(i,j), b=max(i,j);
		REP(x,a,b+1) {
			ans=max(ans,cycle(x));
		}
		printf("%d %d %d\n",i,j,ans);
	}
	exit(0);
}
