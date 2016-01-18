#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;
#define REP(i,a,n) for(int i=a;i<n;i++)

int nums[3000];
int n;
bool* diff;

void reset(int n) {
	diff = new bool[n-1];
}

void load() {
	REP(i,1,n) {
		int d=abs(nums[i]-nums[i-1])-1;
		if(d<0||d>=n-1) return;
		diff[d]=true;
	}
}

int jolly() {
	REP(i,0,n-1)
		if(!diff[i])
			return false;
	return true;
}

int main() {
	while(scanf("%d",&n)!=EOF) {
		reset(n);
		REP(i,0,n) {
			int x;
			scanf("%d",&x);
			nums[i]=x;
		}
		load();
		printf("%s\n", jolly()?"Jolly":"Not jolly");
	}
}
