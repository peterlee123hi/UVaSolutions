#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#define REP(i,a,n) for(int i=a;i<n;i++)

int main() {
	int b,n;
	while(scanf("%d %d",&b,&n),b||n) {
		int banks[b];
		REP(i,0,b) scanf("%d",&banks[i]);
		REP(i,0,n) {
			int a,b,c; scanf("%d %d %d",&a,&b,&c); a--; b--;
			banks[a]-=c; banks[b]+=c;
		}

		bool bail=true;
		REP(i,0,b)
			if(banks[i]<0) bail=false;
		printf("%c\n",(bail)?'S':'N');
	} exit(0);
}
