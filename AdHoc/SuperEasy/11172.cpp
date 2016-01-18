#include <cstdio>
using namespace std;

int main() {
	int N, a, b;
	scanf("%d", &N);
	while(N--) {
		scanf("%d %d", &a, &b);
		printf((a>b)?">":(a==b)?"=":"<");
		printf("\n");
	}
	return 0;
}
