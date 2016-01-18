#include <algorithm>
#include <bitset>
#include <cstdio>
#include <cmath>
using namespace std;
#define REP(i,a,n) for(int i=a;i<n;i++)

const int L = 1000000;
bitset<L+1> minutes;

bool set_interval(int s, int e) {
	REP(i,s,e) {
		if(minutes[i]) return false;
		minutes.set(i);
	}
	return true;
}

int main() {
	int n,m;
	while(scanf("%d %d",&n,&m),n||m) {
		int s,e,r;
		bool conflict = false;
		minutes.reset();
		REP(i,0,n) {
			scanf("%d %d",&s,&e);
			if(!conflict&&!set_interval(s,e))
				conflict = true;
		}
		REP(i,0,m) {
			scanf("%d %d %d",&s,&e,&r);
			while(s<L&&!conflict) {
				if(!set_interval(s,e))
					conflict = true;
				s += r;
				e = min(e+r,L);
			}
		}
		if(conflict)
			printf("CONFLICT\n");
		else
			printf("NO CONFLICT\n");
	}
	return 0;
}
