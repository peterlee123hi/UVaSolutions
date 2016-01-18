#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,a,n) for(int i=a;i<n;i++)

int tracks[20];
int t,n,best=0,best_bm=0;

void reset() { best=best_bm=0; }

void backtrack(int i, int cur, int cur_bm) {
	if(cur<=t) {
		if(i==n) {
			if(abs(cur-t)<abs(best-t)) {
				best=cur;
				best_bm=cur_bm;
			}
		} else {
			backtrack(i+1,cur+tracks[i],cur_bm|(1<<i));
			backtrack(i+1,cur,cur_bm);
		}
	}
}

void output() {
	int sum=0;
	REP(i,0,n)
		if(best_bm&(1<<i)) {
			printf("%d ",tracks[i]);
			sum+=tracks[i];
		}
	printf("sum:%d\n",sum);
}

int main() {
	while(scanf("%d %d",&t,&n)!=EOF) {
		REP(i,0,n) {
			int d;
			scanf("%d",&d);
			tracks[i]=d;
		}

		backtrack(0,0,0);
		output();
		reset();
	}
}
