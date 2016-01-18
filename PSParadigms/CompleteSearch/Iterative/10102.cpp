#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,a,n) for(int i=a;i<n;i++)

int m;
int dist(int x1, int y1, int x2, int y2) { return abs(x1-x2)+abs(y1-y2); }

int main() {
	while(scanf("%d",&m)!=EOF) {
		int field[m][m];
		REP(i,0,m)
			REP(j,0,m) {
				int x;
				scanf("%1d",&x);
				field[i][j]=x;
			}

		int max3=0;
		REP(i,0,m) {
			REP(j,0,m) {
				if(field[i][j]==1) {
					int min3=-1;
					REP(a,0,m) {
						REP(b,0,m) {
							if(field[a][b]==3) {
								int d=dist(i,j,a,b);
								if(min3==-1) min3=d;
								else min3=min(min3,d);
							}
						}
					}
					max3=max(max3,min3);
				}
			}
		}
		printf("%d\n",max3);
	}
}
