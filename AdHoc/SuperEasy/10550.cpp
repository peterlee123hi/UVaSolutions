#include <cstdio>
using namespace std;

int main() {
	int a,b,c,d,deg;
	while(scanf("%d %d %d %d\n",&a,&b,&c,&d), a||b||c||d) {
		deg = 1080;
		deg += (a-b)>0?(a-b)*9:(a-b+40)*9;
		deg += (c-b)>0?(c-b)*9:(c-b+40)*9;
		deg += (c-d)>0?(c-d)*9:(c-d+40)*9;
		printf("%d\n",deg);
	}
	return 0;
}