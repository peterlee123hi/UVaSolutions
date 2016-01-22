#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define REP(i,a,n) for(int i=a;i<n;i++)
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define PB push_back

int gcd(int a,int b) { return (a%b==0)?b:gcd(b,a%b); }

int main() {
	int n;
	while(scanf("%d",&n),n) {
		vi nums;
		set<int> seen;
		do {
			if(seen.find(n)==seen.end()) {
				nums.PB(n);
				seen.insert(n);
			}
			scanf("%d",&n);
		} while(n);
		sort(ALL(nums));
		REP(i,1,SZ(nums)) nums[i]-=nums[0];
		int ans=nums[1];
		REP(i,2,SZ(nums)) ans=gcd(ans,nums[i]);
		printf("%d\n",ans);
	} exit(0);
}
