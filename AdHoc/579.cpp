#include <cstdio>
using namespace std;
#define REP(i,a,n) for(int i=a;i<n;i++)

int main() {
	float h,m;
	while(scanf("%f:%f",&h,&m),h||m) {
		float md = m*6, hd = (h+(m/60))*30;
		float ans = hd-md;
		if(ans < 0) ans *= -1;
		printf("%0.3f\n", (ans>180)?360-ans:ans);
	}
	return 0;
}
