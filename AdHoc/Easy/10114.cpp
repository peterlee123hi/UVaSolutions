#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, float>  ifl;
typedef vector<ifl>       vifl;
#define REP(i,a,n) for(int i=a;i<n;i++)
#define PB push_back
#define MP make_pair
#define SZ(x) ((int)(x).size())
#define FI first
#define SE second

int main() {
	int t,n;
	float d,a;
	while(scanf("%d %f %f %d",&t,&d,&a,&n)!=EOF) {
		float due=a,car=a;
		vifl dep;
		REP(i,0,n) {
			int ta; float tb; scanf("%d %f",&ta,&tb);
			dep.PB(MP(ta,1-tb));
		}
		int i=0;
		REP(m,0,t) {
			due-=d;
			car*=dep.at(i).SE;
			if(i<n-1&&dep.at(i+1).FI==m+1)
				i++;
			if(due<car) {
				printf("%d month%s",m,(m==1)?"\n":"s\n");
				break;
			}
		}
	}
	return 0;
}
