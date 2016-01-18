#include <cstdio>
using namespace std;

int main() {
	int TC, CN=0;
	scanf("%d",&TC);
	while(TC--) {
		int l,w,h;
		scanf("%d %d %d",&l,&w,&h);
		if(l<=20&&w<=20&&h<=20)
			printf("Case %d: good\n",++CN);
		else
			printf("Case %d: bad\n",++CN);
	}
}
