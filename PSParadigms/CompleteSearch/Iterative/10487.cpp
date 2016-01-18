#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
typedef vector<int> vi;
#define PB push_back
#define SZ(x) ((int)(x).size())
#define REP(i,a,n) for(int i=a;i<n;i++)

int main() {
	int n,m,CN=1;
	vi ns;
	while(scanf("%d",&n),n) {
		printf("Case %d:\n",CN++);
		REP(i,0,n) {
			int num;
			scanf("%d",&num);
			ns.PB(num);
		}
		sort(ns.begin(),ns.end());
		scanf("%d",&m);
		REP(i,0,m) {
			int q;
			scanf("%d",&q);

			int a=0,b=n-1,cur=ns[a]+ns[b],best=cur,best_dist=abs(best-q);
			while(a<b) {
				cur=ns[a]+ns[b];
				if(abs(cur-q)<best_dist) {
					best=cur;
					best_dist=abs(cur-q);
				}
				if(cur<q) a++;
				else b--;
			}

			printf("Closest sum to %d is %d.\n",q,best);
		}
		ns.clear();
	}
	return 0;
}
