#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
#define REP(i,a,n) for(int i=a;i<n;i++)

int t,n;
int nums[20];
int c=0;
set<string> sols;

void reset() {
	c=0;
	sols.clear();
}

int backtrack(int i, int sum, string str) {
	if(i==n) {
		if(sum==t&&sols.find(str)==sols.end()) {
			printf("%s\n",str.c_str());
			c++;
			sols.insert(str);
		}
	} else {
		string other(str);
		if(str.length() > 0) str.append("+");
		str.append(to_string(nums[i]));
		backtrack(i+1,sum+nums[i],string(str));
		backtrack(i+1,sum,other);
	}
}

int main() {
	while(scanf("%d %d",&t,&n),n) {
		reset();
		REP(i,0,n) {
			int x;
			scanf("%d",&x);
			nums[i]=x;
		}

		printf("Sums of %d:\n",t);
		backtrack(0,0,"");
		if(c==0) {
			printf("NONE\n");
		}
	}
}
