#include <cstdio>
using namespace std;
#define REP(i,a,n) for(int i=a;i<n;i++)

int main() {
	int T,a,b,c;
	scanf("%d",&T);
	while(T--) {
		scanf("%d %d %d",&a,&b,&c);
		bool sol=false;
		REP(x,-22,22+1) if(!sol&&x*x<=c)
			REP(y,-100,100+1) if(!sol&&x!=y&&x*x+y*y<=c)
				REP(z,-100,100+1) 
					if(!sol&&z!=x&&z!=y&&x+y+z==a&&x*y*z==b&&x*x+y*y+z*z==c) {
						sol=true;
						printf("%d %d %d\n",x,y,z);
					}
		if(!sol)
			printf("No solution.\n");
	}
}
