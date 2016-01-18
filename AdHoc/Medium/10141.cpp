#include <cstdio>
#include <iostream>
using namespace std;
#define REP(i,a,n) for(int i=a;i<n;i++)

int main() {
	int n,p,prn=1;
	while(scanf("%d %d\n",&n,&p),n,p) {
		if(prn>1) printf("\n");
		string bp,temp;
		int bn=0;
		float bpr=1E37;
		REP(i,0,n) getline(cin,temp);
		REP(i,0,p) {
			string pr; float pp; int pn;
			getline(cin,pr); scanf("%f %d\n",&pp,&pn);
			REP(i,0,pn) getline(cin,temp);
			if(pn>bn||pn==bn&&pp<bpr) {
				bp=pr; bn=pn; bpr=pp;
			}
		}

		printf("RFP #%d\n%s\n",prn++,bp.c_str());
	}
	return 0;
}
