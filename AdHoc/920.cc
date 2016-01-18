#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define REP(i,a,n) for(int i=a;i<n;i++)

struct point {
	double x,y;
};

bool operator < (point a, point b) {
	return a.x > b.x;
}

int n;
point p[100];

int main() {
	int T,x,y;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		REP(i,0,n) {
			scanf("%d %d",&x,&y);
			p[i].x=x;
			p[i].y=y;
		} sort(p,p+n);

		double ans=0.0;
		double height=0;
		REP(i,1,n) {
			if(p[i].y>height&&p[i].y>p[i-1].y) {
				double dx=p[i].x-p[i-1].x;
				double dy=p[i].y-p[i-1].y;
				double h=sqrt(dx*dx+dy*dy);
				double sunny_y=p[i].y-height;
				ans+=h*sunny_y/dy;
			}
			height=max(height,p[i].y);
		}

		printf("%0.2f\n",ans);
	}
	exit(0);
}
