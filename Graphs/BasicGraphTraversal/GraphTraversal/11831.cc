#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,a,n) for(int i=a;i<n;i++)
#define ALL(x) (x).begin(),(x).end();

int n,m,s;
char arena[100][100];
char c[100000];
char dir[4];

bool inbounds(int x, int y) { return 0<=x&&x<n&&0<=y&&y<m; }

int collect(int x, int y, int i, int d) {
	if(i==s) {
		return (arena[x][y]=='*')?1:0;
	}
	else {
		int ans = 0,to_x=x,to_y=y;
		if(arena[x][y]=='*') {
			ans=1;
			arena[x][y]='.';
		}
		if(c[i]=='F') {
			if(dir[d]=='N')
				to_x=x-1;
			else if(dir[d]=='S')
				to_x=x+1;
			else if(dir[d]=='L')
				to_y=y+1;
			else
				to_y=y-1;

			if(inbounds(to_x,to_y)&&arena[to_x][to_y]!='#')
				return ans+collect(to_x,to_y,i+1,d);
			else
				return ans+collect(x,y,i+1,d);
		}
		else if(c[i]=='D') {
			d=(d+1)%4;
			return ans+collect(x,y,i+1,d);
		}
		else {
			d=(d+3)%4;
			return ans+collect(x,y,i+1,d);
		}
	}
}

int main() {
	dir[0]='N';
	dir[1]='L';
	dir[2]='S';
	dir[3]='O';
	while(scanf("%d %d %d",&n,&m,&s),n||m||s) {
		int sx,sy;
		REP(i,0,n) REP(j,0,m) {
			scanf(" %c",&arena[i][j]);
			if(find(dir,dir+4,arena[i][j])-dir!=4) {
				sx=i;
				sy=j;
			}
		}
		REP(i,0,s)
			scanf(" %c",&c[i]);
		printf("%d\n",collect(sx,sy,0,find(dir,dir+4,arena[sx][sy])-dir));
	}
	exit(0);
}
