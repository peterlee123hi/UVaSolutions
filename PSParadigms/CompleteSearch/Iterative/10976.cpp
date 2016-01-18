#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define PB push_back
#define MP make_pair
#define SZ(x) ((int)(x).size())
#define FI first
#define SE second
#define REP(i,a,n) for(int i=a;i<n;i++)

int main() {
	int k;
	while(scanf("%d",&k)!=EOF) {
		vii pairs;
		REP(a,k+1,2*k+1) {
			double bf=(double)a*k/(a-k);
			if(bf==(int)bf) {
				int b=(int)bf;
				pairs.PB(MP(b,a));
			}
		}
		int n=SZ(pairs);
		printf("%d\n", n);
		REP(i,0,n) {
			printf("1/%d = 1/%d + 1/%d\n",k,pairs[i].FI,pairs[i].SE);
		}
	}
}
