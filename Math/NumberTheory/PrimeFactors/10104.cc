#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define REP(i,a,n) for(int i=a;i<n;i++)

int a,b,d,x,y;

void extendedEuclid(int a,int b) {
	if(b==0) {
		x=1; y=0; d=a; 
		return;
	}
	extendedEuclid(b,a%b);
	int x1=y;
	int y1=x-(a/b)*y;
	x=x1; y=y1;
}

int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	while(scanf("%d %d",&a,&b)!=EOF) {
		extendedEuclid(a,b);
		printf("%d %d %d\n",x,y,d);
	} exit(0);
}
