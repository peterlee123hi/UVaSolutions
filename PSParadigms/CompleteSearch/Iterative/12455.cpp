#include <cstdio>
using namespace std;
#define REP(i,a,n) for(int i=a;i<n;i++)

int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		int n,p;
		scanf("%d %d",&n,&p);
		int ls[p];
		REP(i,0,p) {
			int l;
			scanf("%d",&l);
			ls[i]=l;
		}

		bool sol=false;
		REP(q,0,(1<<p)) { // q is a bitmask that has 1 if included in subset
			int l=0;
			REP(d,0,p) {
				if(q&(1<<d))
					l+=ls[d];
			}
			if(l==n) {
				sol=true;
				break;
			}
		}

		printf("%s\n",sol?"YES":"NO");
	}
	return 0;
}
