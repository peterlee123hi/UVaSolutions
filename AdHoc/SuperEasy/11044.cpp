#include <cstdio>
using namespace std;

int main() {
	int N, a, b;
	scanf("%d", &N);
	while(N--) {
		scanf("%d %d", &a, &b);
		printf("%d\n", (a/3)*(b/3));
	}
	return 0;
}
