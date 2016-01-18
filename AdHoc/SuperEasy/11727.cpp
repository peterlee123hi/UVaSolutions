#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int N, a, b, c;
	int cs = 1;
	scanf("%d", &N);
	while(N--) {
		scanf("%d %d %d", &a, &b, &c);
		printf("Case %d: %d\n", cs, max(min(a,b), min(max(a,b),c)));
		cs++;
	}
	return 0;
}
