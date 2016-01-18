#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,a,n) for(int i=a;i<n;i++)

int main() {
	int N, L;
	scanf("%d", &N);
	while(N--) {
		scanf("%d", &L);
		int shops[L];
		REP(i,0,L) scanf("%d", &shops[i]);
		printf("%d\n",2*(*max_element(shops,shops+L)-*min_element(shops,shops+L)));
	}
	return 0;
}
