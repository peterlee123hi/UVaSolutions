#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#define REP(i,a,n) for(int i=a;i<n;i++)

int main() {
	int N, k, lower, upper;
	while(scanf("%d",&N)) {
		k = (int)(floor(log10(N))+2);
		lower = (int)(log2(N)+k*log2(10));
		upper = (int)(log2(N+1)+k*log2(10));
		while(lower==upper&&k<1000000) {
			k++;
			lower = (int)(log2(N)+k*log2(10));
			upper = (int)(log2(N+1)+k*log2(10));
		}
		if(k==1000000) printf("no power of 2\n");
		else printf("%d\n", upper);
	}
    exit(0);
}
