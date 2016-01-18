#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
typedef vector<int> vi;
#define REP(i,a,n) for(int i=a;i<n;i++)
#define PB push_back
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())

vi nums;

int main() {
	int x;
	while(scanf("%d",&x)!=EOF) {
		nums.PB(x);
		sort(ALL(nums));
		int n=SZ(nums);
		if(n%2)
			printf("%d\n",nums[n/2]);
		else
			printf("%d\n",(nums[n/2-1]+nums[n/2])/2);
	}
}
