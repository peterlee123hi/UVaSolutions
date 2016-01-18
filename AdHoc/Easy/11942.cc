#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#define REP(i,a,n) for(int i=a;i<n;i++)

int main() {
	int T; scanf("%d",&T);
	printf("Lumberjacks:\n");
	while(T--) {
		int prev=-1; bool inc,ord=true;
		REP(i,0,10) {
			if(i==0) scanf("%d",&prev);
			else if(i==1) {
				int x; scanf("%d",&x);
				inc=x>prev;
				prev=x;
			} else {
				int x; scanf("%d",&x);
				if(inc&&x<prev) ord=false;
				else if(!inc&&x>prev) ord=false;
				prev=x; 
			}
		} printf("%s\n",(ord)?"Ordered":"Unordered");
	} exit(0);
}
