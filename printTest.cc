#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;
#define REP(i,a,n) for(int i=a;i<n;i++)

int main() {
	printf("5 99\n");
	printf("10 10 10 10 10\n");
	REP(i,0,5) {
		REP(j,0,100) printf("%s%d",(j==0)?"":" ",j);
		printf("\n");
	} exit(0);
}
