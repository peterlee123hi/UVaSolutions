#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;
#define REP(i,a,n) for(int i=a;i<n;i++)

int main() {
	int T,a=0; scanf("%d",&T);
	while(T--) {
		string com; cin>>com;
		if(com=="donate") {
			int x; scanf("%d",&x);
			a+=x;
		} else printf("%d\n",a);
	} exit(0);
}
