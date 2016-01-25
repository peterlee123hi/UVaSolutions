#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair<int,int> ii;
#define fi first
#define se second

int z,i,m,l;

int f(int x) {
	return (z*x+i)%m;
}

ii floydCycleFinding(int x0) {
	int tortoise=f(x0),hare=f(f(x0));
	while(tortoise!=hare) tortoise=f(tortoise),hare=f(f(hare));
	int mu=0; hare=x0;
	while(tortoise!=hare) tortoise=f(tortoise),hare=f(hare),mu++;
	int lambda=1; hare=f(tortoise);
	while(tortoise!=hare) hare=f(hare),lambda++;
	return ii(mu,lambda);
}

int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int CN=1;
	while(scanf("%d %d %d %d",&z,&i,&m,&l),z||i||m||l) {
		ii ans=floydCycleFinding(l);
		printf("Case %d: %d\n",CN++,ans.se);
	} exit(0);
}
