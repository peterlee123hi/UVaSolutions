#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
#define REP(i,a,n) for(int i=a;i<n;i++)
#define PER(i,a,n) for(int i=n-1;i>=a;i--)

int main() {
	char t[61];
	while(scanf(" %60s",t),strlen(t)>1||t[0]!='0') {
		int ans=0;
		int c=1;
		PER(i,0,strlen(t)) {
			int digit=t[i]-'0';
			ans+=digit*(pow(2,c)-1);
			c++;
		} printf("%d\n",ans);
	}
}
