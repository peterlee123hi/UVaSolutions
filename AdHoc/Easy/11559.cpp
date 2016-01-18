#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
#define REP(i,a,n) for(int i=a;i<n;i++)

int main() {
	int n,b,h,w;
	while(scanf("%d %d %d %d",&n,&b,&h,&w) != EOF) {
		string ans = "stay home";
		int min = -1;
		REP(i,0,h) {
			int price; scanf("%d",&price);
			bool v = false;
			REP(j,0,w) {
				int week; scanf("%d",&week);
				if(n<=week) v = true;
			}
			if(v&&price*n<=b&&(price*n<min||min==-1)) min = price*n;
		}
		if(min!=-1) printf("%d\n",min);
		else printf("%s\n",ans.c_str());
	}
	return 0;
}
