#include <cstdio>
using namespace std;

int main() {
	int TC,n;
	scanf("%d",&TC);
	while(TC--) {
		scanf("%d",&n);
		n*=567;
		n/=9;
		n+=7492;
		n*=235;
		n/=47;
		n-=498;
		if(n<0) n*=-1;
		n/=10;
		printf("%d\n",n%10);
	}
 	return 0;
}
