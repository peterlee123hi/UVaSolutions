#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,a,n) for(int i=a;i<n;i++)

int best_m=100, CN=1;
int i_rows[8],rows[8];

void reset() {
	best_m=100;
}

void output() {
	printf("Case %d: %d\n",CN++,best_m);
}

int diff(int r1[8], int r2[8]) {
	int d=0;
	REP(i,0,8) {
		if(r1[i]!=r2[i])
			d++;
	}
	return d;
}

bool place(int r, int c) {
	REP(prev,0,c)
		if(rows[prev]==r||abs(rows[prev]-r)==abs(prev-c))
			return false;
	return true;
}

void backtrack(int c) {
	if(c==8) {
		if(diff(i_rows,rows)<best_m) {
			best_m=diff(i_rows,rows);
		}
	} else {
		REP(r,0,8) {
			if(place(r,c)) {
				rows[c]=r;
				backtrack(c+1);
			}
		}
	}
}

int main() {
	int r;
	while(scanf("%d",&r)!=EOF) {
		i_rows[0]=r-1;
		REP(i,1,8) {
			scanf("%d",&r);
			i_rows[i]=r-1;
		}

		backtrack(0);
		output();
		reset();
	}
	return 0;
}
