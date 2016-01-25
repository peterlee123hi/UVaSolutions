#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	ll n;
	while(scanf("%lld",&n),n) {
		printf("%s\n",(floor(sqrt(n))==ceil(sqrt(n)))?"yes":"no");
	} exit(0);
}
