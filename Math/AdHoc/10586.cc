#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;
#define REP(i,a,n) for(int i=a;i<n;i++)

int main() {
	int n,k;
	while(scanf("%d %d",&n,&k),n!=-1&&k!=-1) {
		int coeff[n+1];
		REP(i,0,n+1) scanf("%d",&coeff[n-i]);
		REP(i,0,n+1-k) {
			int c=coeff[i];
			coeff[i]-=c;
			if(k>0)
				coeff[i+k]-=c;
		}

		int p=0;
		REP(i,0,n+1)
			if(coeff[n-i]!=0) {
				printf("%s%d",(p==0)?"":" ",coeff[n-i]);
				p++;
			}
		if(p==0) printf("%d",coeff[n]);
		printf("\n");
	}
	exit(0);
}
