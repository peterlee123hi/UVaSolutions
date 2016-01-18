#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#define REP(i,a,n) for(int i=a;i<n;i++)

int main() {
	int T,CN=1; scanf("%d",&T);
	while(T--) {
		if(CN>1) printf("\n");
		int W,diff=-1; scanf("%d",&W);
		bool can=true;
		REP(i,0,W) {
			int a,b; scanf("%d %d",&a,&b);
			if(diff==-1) diff=a-b;
			else if(diff!=a-b) {
				can=false;
			}
		}
		printf("%s\n",(can)?"yes":"no");
		CN++;
	} exit(0);
}
