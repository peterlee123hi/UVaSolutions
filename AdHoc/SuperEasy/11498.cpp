#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,a,n) for(int i=a;i<n;i++)

int main() {
	int N,X,Y,x,y;
	while(scanf("%d",&N),N) {
		scanf("%d %d",&X,&Y);
		REP(i,0,N) {
			scanf("%d %d",&x,&y);
			if(x==X||y==Y) printf("divisa\n");
			else if(x>X&&y>Y) printf("NE\n");
			else if(x>X&&y<Y) printf("SE\n");
			else if(x<X&&y<Y) printf("SO\n");
			else printf("NO\n");
		}		
	}
	return 0;
}
