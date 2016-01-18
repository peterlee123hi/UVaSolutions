#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#define REP(i,a,n) for(int i=a;i<n;i++)

int nums[1000];

int main() {
	int n,cn=1;
	while(scanf("%d",&n),n) {
		int a=0,b=0,x;
		REP(i,0,n) {
			scanf("%d",&x);
			if(x>0) a++; else b++;
		}
		printf("Case %d: %d\n",cn++,a-b);
	}
	exit(0);
}
