#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,a,n) for(int i=a;i<n;i++)

int* p;
int m,n;

void output() {
	int i=0,j=n-1,best_i,best_j;
	while(i<j) {
		int sum=p[i]+p[j];
		if(sum==m) {
			best_i=i;
			best_j=j;
		}

		if(sum<m) i++;
		else if(sum>m) j--;
		else {
			i++;
			j--;
		}
	}

	printf("Peter should buy books whose prices are %d and %d.\n\n",p[best_i],p[best_j]);
}

int main() {
	while(scanf("%d",&n)!=EOF) {
		p=new int[n];
		REP(i,0,n) {
			int x;
			scanf("%d",&x);
			p[i]=x;
		}
		sort(p,p+n);
		scanf("%d",&m);
		output();
	}
	return 0;
}
